#ifndef __ADD_TEST_HPP__
#define __ADD_TEST_HPP__

#include "gtest/gtest.h"
#include "add.hpp"
#include "op.hpp"
TEST(AddTest, AddEvaluateZero) {
    Base* val1 = new Op(0);
    Base* val2 = new Op(0);
    Base* test = new Add(val1, val2);
    EXPECT_NEAR(test -> evaluate(), 0, 0.1);
}
TEST(AddTest, AddStringifyZero) {
    Base* val1 = new Op(0);
    Base* val2 = new Op(0);
    Base* test = new Add(val1, val2);
    EXPECT_EQ(test -> stringify(), "0.000000 + 0.000000");
}
TEST(AddTest, AddGetChildOne) {
    Base* val1 = new Op(7);
    Base* val2 = new Op(4);
    Base* test = new Add(val1,val2);
    EXPECT_EQ(test -> get_child(1)->evaluate(), 7);
}
TEST(AddTest, AddGetChildTwo) {
    Base* val1 = new Op(7);
    Base* val2 = new Op(4);
    Base* test = new Add(val1,val2);
    EXPECT_EQ(test -> get_child(2)->evaluate(), 4);
}
TEST(AddTest, AddGetNumberChildren) {
    Base* val1 = new Op(7);
    Base* val2 = new Op(4);
    Base* test = new Add(val1,val2);
    EXPECT_EQ(test -> number_of_children(), 2);
}

#endif
