#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"

TEST(OpTest, OpEvaluateNonZero) {
    Base* test = new Op(8);
    EXPECT_EQ(test->evaluate(), 8);
}

TEST(OpTest, OpPrintNonZero) {
    Base* test = new Op(8);
    EXPECT_EQ(test->stringify(), "8.000000");
}
TEST(OpTest, OpGetChildZero) {
    Base* test = new Op(7);
    EXPECT_EQ(test -> get_child(2), nullptr);
}
TEST(OpTest, OpGetNumberChildren) {
    Base* test = new Op(7);
    EXPECT_EQ(test -> number_of_children(), 0);
}

#endif
