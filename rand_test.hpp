#ifndef _RAND_TEST_HPP_
#define _RAND_TEST_HPP_
#include "gtest/gtest.h"

#include "rand.hpp"

TEST(RandTest, RandEvaluateNonZero) {
    srand(1);
    Base* test = new Rand();
    EXPECT_EQ(test->evaluate(), 83);
delete test;
}
TEST(RandTest, RandStringifyNonZero) {
    srand(1);
    Base* test = new Rand();
    EXPECT_EQ(test->stringify(),"83.000000");
delete test;
}
TEST(RandTest, RandEvaluateSame) {
    srand(1);
    Base* test = new Rand();
    EXPECT_EQ(test -> evaluate(), 83);
delete test;
}
TEST(RandTest, RandStringifySame) {
    srand(1);
    Base* test = new Rand();
    EXPECT_EQ(test->stringify(),"83.000000");
delete test;
}
TEST(RandTest, RandGetChildZero) {
    Base* test = new Rand();
    EXPECT_EQ(test -> get_child(2), nullptr);
delete test;
}
TEST(RandTest, RandGetNumberChildren) {
    Base* test = new Rand();
    EXPECT_EQ(test -> number_of_children(), 0);
delete test;
}
#endif
