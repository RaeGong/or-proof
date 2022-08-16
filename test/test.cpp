#include "gtest/gtest.h"
#include "../src/PaillierEncryption.h"

TEST(TestAddInt, test_add_int_1) {
    int a = 1;
    a ++;
    EXPECT_EQ(a, 2);
}

// TEST(Paillier, KeyGeneration)
// {
//   // check key length correct
//   for (size_t i = 1; i < 32; i++)
//   {

//     auto crypto = make_shared<PaillierEncryption>(i);
//     EXPECT_EQ(NumBytes(crypto->getPublicKey()), i);
//     EXPECT_EQ(GCD(crypto->n, crypto->lambda), 1);
//   }

//   // check seedable key gen
//   vector<uint8_t> seed{0x00, 0x00, 0x00, 0x00, 0x00, 0x12, 0x34};
//   auto c1 = make_shared<PaillierEncryption>(32, seed);
//   auto c2 = make_shared<PaillierEncryption>(32, seed);
//   EXPECT_EQ(c1->p, c2->p);
//   EXPECT_EQ(c1->q, c2->q);
//   EXPECT_EQ(c1->n2, c2->n2);
//   EXPECT_EQ(GCD(c1->n, c1->lambda), 1);
// }

