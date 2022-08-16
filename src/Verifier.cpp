#include "./Verifier.h"


Verifier::Verifier (
    const ZZ &N,
    const ZZ &N2,
    const ZZ_p &G ) 
{
    this -> N = N;
    this -> N2 = N2;
    this -> G = G;
}

Verifier::Verifier (
    shared_ptr<PaillierEncryption> & crypto,
    const ZZ_p & G )
{
    this -> N = crypto -> getPublicKey();
    this -> N2 = crypto -> getGroupP();
    this -> G = G;
    this -> crypto = crypto;
}

bool Verifier::verify (const Vec<ZZ_p> & proofs, const ZZ &e) {
    if (proofs.length() != 3) {
      cout << "wrong proof length !" << endl;
      return false;   
    }
    ZZ_p::init(N2);
    ZZ_p c;
    ZZ_p a;
    ZZ_p z;

    c = proofs[0];
    a = proofs[1];
    z = proofs[2];

    ZZ_p tmp_left, tmp_right;
    tmp_left = power(z, N);
    tmp_right = power(c, e);
    mul(tmp_right, tmp_right, a);

    if (tmp_left != tmp_right){
        cout << "wrong proof !" << endl;
        return false;
    }

    return true;
}

bool Verifier::or_verify (const Vec<ZZ_p> & proofs, const ZZ & e) {
        if (proofs.length() != 8) {
         Error("incorrect proof length!");
        }
        auto c1 = proofs[0];
        auto a1 = proofs[1];
        auto z1 = proofs[2];
        auto e1 = proofs[3];
        auto c2 = proofs[4];
        auto a2 = proofs[5];
        auto z2 = proofs[6];
        auto e2 = proofs[7];

        ZZ_p::init(N2);
        auto left1 = power(z1, N); 
        auto right1 = power(c1, conv<ZZ>(e1));
        mul(right1, right1, a1);

        auto left2 = power(z2, N);
        auto right2 = power(c2, conv<ZZ>(e2));
        mul(right2, right2, a2);

        return (left1 == right1 && left2 == right2);
}

bool Verifier::or_verify_ni (const Vec<ZZ_p> & proofs) {
        if (proofs.length() != 9) {
         Error("incorrect proof length!");
        }
        auto c1 = proofs[0];
        auto a1 = proofs[1];
        auto z1 = proofs[2];
        auto e1 = proofs[3];
        auto c2 = proofs[4];
        auto a2 = proofs[5];
        auto z2 = proofs[6];
        auto e2 = proofs[7];
        auto e = proofs[8];

        ZZ_p::init(N2);
        auto left1 = power(z1, N); 
        auto right1 = power(c1, conv<ZZ>(e1));
        mul(right1, right1, a1);

        auto left2 = power(z2, N);
        auto right2 = power(c2, conv<ZZ>(e2));
        mul(right2, right2, a2);

        ZZ_p::init(SqrRoot(N));
        ZZ_p sum = e1 + e2;

        return (left1 == right1 && left2 == right2 && e == sum);
}

