#include "gtest/gtest.h"

TEST(TestAddInt, test_add_int_1) {
    int a = 1;
    a ++;
    EXPECT_EQ(a, 2);
}
