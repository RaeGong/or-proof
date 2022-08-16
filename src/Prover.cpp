#include "./Prover.h"

/* 
for sha256 usage: https://wiki.openssl.org/index.php/OpenSSL_3.0
*/

Prover::Prover(
    shared_ptr<Verifier> verifier)
{
    this->N = verifier->N;
    this->N2 = verifier->N2;
    this->verifier = verifier;
}


/* 
    1. c  = r ^ N mod N^2 
    encryption of 0 with withness r
    
    2. prover: a = r1 ^ N mode N^2

    3. verifier: challenge e
    |e| = 1/2 * |N|

    4. prover: z = r1 * r ^ e mode N^2

    5. verifier check: z^N = a * c ^ e mod N^2

    */

Vec<ZZ_p> Prover::prove(const ZZ & e) {

    ZZ_p::init(N2);

    Vec<ZZ_p> proofs;
    proofs.SetLength(3);
    ZZ_p z;

    auto r = this->verifier->crypto->pickRandom();
    auto c = power(r, N);

    auto r1 = this->pickRandom();
    auto a = power(r1, N);

    z = power(r, e);
    mul(z, z, r1);

    proofs[0] = c;
    proofs[1] = a;
    proofs[2] = z;
    return proofs;
}

Vec<ZZ_p> Prover::prove_ni (ZZ & e) {

    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    
    // ZZ_p::init(N);
    ZZ_p::init(SqrRoot(N)); // e is only N/2 -bit for special soundness
    ZZ_p tmp;
    random(tmp);
    e = conv<ZZ>(tmp);
    cout << "e is ," << e << endl;

    cout << "bits of N: " << NumBits(N) << endl;
    cout << "bits of N^2: " << NumBits(N2) << endl;
    cout << "bits of e: " << NumBits(e) << endl;

    ZZ_p::init(N2);
    Vec<ZZ_p> proofs;
    proofs.SetLength(3);

    auto r = this->pickRandom();
    auto c = power(r, N);

    // compute challenge e, try using sha256 here
    // todo: need to convert it to a zz_p
    // string str = ConvertUtils::toString(c);
    // SHA256_Update(&sha256, str.c_str(), str.size());
    // SHA256_Final(hash, &sha256);
    // cout << "sha256 is " << sha256.data << endl;

    
    auto r1 = this->pickRandom();
    auto a = power(r1, N);
    auto z = power(r, e);
    mul(z, z, r1);

    proofs[0] = c;
    proofs[1] = a;
    proofs[2] = z;
    
    return proofs;
}

//todo: changed into a hash function
ZZ_p Prover::pickRandom() { 
    ZZ_pPush push(this->N);
    ZZ_p r;
    while (true)
    {
        random(r);
        if (r == 0)
            continue;
        auto gcd = GCD(conv<ZZ>(r), this->N);

        if (gcd == 1)
            return r;
    }
}

ZZ_p Prover::pickRandomN2 () {
    ZZ_pPush push(this->N2);
    ZZ_p r;
    while (true)
    {
        random(r);
        if (r == 0)
            continue;
        auto gcd = GCD(conv<ZZ>(r), this->N2);

        if (gcd == 1)
            return r;
    }
}

// or-proof
// assume prover knows v1, not knows v2
// return proofs: c1, a1, z1, e1; c2, a2, z2, e2
Vec<ZZ_p> Prover:: or_proof (const ZZ & e) {
    
    ZZ_p::init(N);
    auto v1 = pickRandom();
    auto v2 = pickRandom();
    auto r1 = pickRandom();
    auto r2 = pickRandom();


    ZZ_p::init(N2);
    auto c2 = power(v2, N);
    mul(c2, c2, conv<ZZ_p>(1 + N));
    ZZ_p a1 = power(r1, N); 


    // simulating proof for v2
    auto z2 = pickRandomN2();
    ZZ_p::init(SqrRoot(N));
    ZZ_p e2;
    random(e2); 
    ZZ_p e1 = conv<ZZ_p>(e) - e2;


    
    ZZ_p::init(N2);
    auto a2 = power(z2, N);
    a2 = a2 / (power(c2, conv<ZZ>(e2)));


    // proof for v1
    auto proofs = prove(conv<ZZ>(e1));
    proofs.append(e1);
    proofs.append(c2);
    proofs.append(a2);
    proofs.append(z2);
    proofs.append(e2);
    
    return proofs;
}

// return proofs: c1, a1, z1, e1; c2, a2, z2, e2，e
Vec<ZZ_p> Prover::or_proof_ni (ZZ& e) {
    ZZ_p::init(N);
    auto v1 = pickRandom();
    auto v2 = pickRandom();
    auto r1 = pickRandom();
    auto r2 = pickRandom();

    ZZ_p::init(SqrRoot(N));
    ZZ_p tmp;
    random(tmp);
    e = conv<ZZ>(tmp);

    ZZ_p::init(N2);
    auto c2 = power(v2, N);
    mul(c2, c2, conv<ZZ_p>(1 + N));
    ZZ_p a1 = power(r1, N); 


    // simulating proof for v2
    auto z2 = pickRandomN2();

    ZZ_p::init(SqrRoot(N));
    ZZ_p e2;
    random(e2); 
    ZZ_p e1 = conv<ZZ_p>(e) - e2;
    
    
    ZZ_p::init(N2);
    auto a2 = power(z2, N);
    a2 = a2 / (power(c2, conv<ZZ>(e2)));

    // proof for v1
    auto proofs = prove(conv<ZZ>(e1));
    proofs.append(e1);
    proofs.append(c2);
    proofs.append(a2);
    proofs.append(z2);
    proofs.append(e2);
    proofs.append(conv<ZZ_p>(e));
    
    
    return proofs;
}