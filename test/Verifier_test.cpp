#include "gtest/gtest.h"

#include "../src/namespace.h"
#include "../src/Verifier.h"

namespace{
    
    TEST(Verifier, verify_correct) {
        auto crypto = make_shared<PaillierEncryption>(32);
        auto verifier = make_shared<Verifier> (crypto, crypto->getGroupG());
        
        ZZ m;
        m = 0;
        ZZ_p z;

        auto r = crypto ->pickRandom(); // r < n
        auto c = crypto ->encrypt(m, r);
        auto r1 = crypto ->pickRandom();
        auto a = crypto->encrypt(m, r1);
        auto e = crypto->pickRandom();
        
        ZZ_p::init(verifier->N2);
        z = power(r, conv<ZZ>(e));
        mul(z, z, r1);
        
        Vec<ZZ_p> proofs;
        proofs.SetLength(3);
        proofs[0] = c;
        proofs[1] = a;
        proofs[2] = z;

        auto flag = verifier->verify(proofs, conv<ZZ>(e));

        EXPECT_EQ(flag,true);

    }

    TEST(Verifier, verify_wrong) {
        auto crypto = make_shared<PaillierEncryption>(32);

        EXPECT_EQ(NumBytes(crypto->getPublicKey()), 32);
        EXPECT_EQ(GCD(crypto->n, crypto->lambda), 1);
        auto verifier = make_shared<Verifier> (crypto, crypto->getGroupG());
        
        ZZ m;
        m = 0;

        ZZ_p::init(verifier->N2);

        auto r = crypto ->pickRandom(); // r < n
        auto c = power(r, crypto->n);
        auto r1 = crypto ->pickRandom();
        auto a = power(r1, crypto->n);

        auto e = crypto->pickRandom();
        auto z = crypto->pickRandom();
        
        
        Vec<ZZ_p> proofs;
        proofs.SetLength(3);
        proofs[0] = c;
        proofs[1] = a;
        proofs[2] = z;

        auto flag = verifier->verify(proofs, conv<ZZ>(e));

        EXPECT_EQ(flag, false);
    }


}