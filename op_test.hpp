#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"

TEST(OpTest, OpEvaluateNonZero) {
    Base* test = new Op(8);
    EXPECT_EQ(test->evaluate(), 8);
    delete test;
}

TEST(OpTest, OpPrintNonZero) {
    Base* test = new Op(8);
    EXPECT_EQ(test->stringify(), "8.000000");
    delete test;
}
TEST(OpTest, OpGetChildZero) {
    Base* test = new Op(7);
    EXPECT_EQ(test -> get_child(2), nullptr);
    delete test;
}
TEST(OpTest, OpGetNumberChildren) {
    Base* test = new Op(7);
    EXPECT_EQ(test -> number_of_children(), 0);
    delete test;
}

#endif
