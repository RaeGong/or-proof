#include "gtest/gtest.h"

#include "../src/namespace.h"

#include <set>
#include "../src/PaillierEncryption.h"
#include "../src/utils/ConvertUtils.h"
#include "../src/Prover.h"

namespace{

    TEST(Prover, correct_interactive) {
        auto crypto = make_shared<PaillierEncryption>(128);
        auto verifier = make_shared<Verifier> (crypto, crypto->G);
        auto prover = make_shared<Prover> (verifier);


        ZZ_p::init(prover->N2);
        ZZ_p tmp_left, tmp_right;
        Vec<ZZ_p> proofs;
    
        auto e = prover->pickRandom(); // simulate the verifier picks e
        proofs = prover->prove(conv<ZZ>(e));

        power(tmp_left, proofs[2], prover->N);
        power(tmp_right, proofs[0], conv<ZZ>(e));
        mul(tmp_right, tmp_right, proofs[1]);

        EXPECT_EQ(tmp_left, tmp_right);
        EXPECT_EQ(proofs.length(), 3);
    }

    TEST(Prover, correct_non_interactive) {
        auto crypto = make_shared<PaillierEncryption>(128);
        auto verifier = make_shared<Verifier> (crypto, crypto->G);
        auto prover = make_shared<Prover> (verifier);

        ZZ_p::init(SqrRoot(prover->N));
        ZZ e;

        ZZ_p::init(prover->N2);
        ZZ_p tmp_left, tmp_right;

        auto proofs = prover->prove_ni(e);

        auto c = proofs[0];
        auto a = proofs[1];
        auto z = proofs[2];
        
        power(tmp_left, z, prover->N);
        power(tmp_right, c, e);
        mul(tmp_right, tmp_right, a);

        EXPECT_EQ(tmp_left, tmp_right);
        EXPECT_EQ(proofs.length(), 3);
    }

    TEST(Prover, or_proof_test) {
        auto crypto = make_shared<PaillierEncryption>(256); // N_length = 2048 bits
        auto verifier = make_shared<Verifier> (crypto, crypto->G);
        auto prover = make_shared<Prover> (verifier);


        ZZ_p::init(SqrRoot(prover->N));
        ZZ_p e;
        random(e);
         
        auto proofs = prover->or_proof(conv<ZZ>(e));
        EXPECT_EQ(proofs.length(), 8);

        auto c1 = proofs[0];
        auto a1 = proofs[1];
        auto z1 = proofs[2];
        auto e1 = proofs[3];
        auto c2 = proofs[4];
        auto a2 = proofs[5];
        auto z2 = proofs[6];
        auto e2 = proofs[7];

        ZZ_p::init(prover->N2);
        auto left1 = power(z1, prover->N);        
        auto right1 = power(c1, conv<ZZ>(e1));
        mul(right1, right1, a1);
        EXPECT_EQ(left1, right1);
        
        auto left2 = power(z2, prover->N);        
        auto right2 = power(c2, conv<ZZ>(e2));
        mul(right2, right2, a2);
        EXPECT_EQ(left2, right2);

        ZZ_p::init(SqrRoot(prover->N));
        ZZ_p sum = e1 + e2;
        EXPECT_EQ(sum, e);

    }

}