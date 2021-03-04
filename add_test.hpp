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
    delete val1;
    delete val2;
    delete test;
}
TEST(AddTest, AddStringifyZero) {
    Base* val1 = new Op(0);
    Base* val2 = new Op(0);
    Base* test = new Add(val1, val2);
    EXPECT_EQ(test -> stringify(), "0.000000 + 0.000000");
    delete val1;
    delete val2;
    delete test;
}
TEST(AddTest, AddGetChildOne) {
    Base* val1 = new Op(7);
    Base* val2 = new Op(4);
    Base* test = new Add(val1,val2);
    EXPECT_EQ(test -> get_child(0)->evaluate(), 7);
    delete val1;
    delete val2;
    delete test;
}
TEST(AddTest, AddGetChildTwo) {
    Base* val1 = new Op(7);
    Base* val2 = new Op(4);
    Base* test = new Add(val1,val2);
    EXPECT_EQ(test -> get_child(1)->evaluate(), 4);
    delete val1;
    delete val2;
    delete test;
}
TEST(AddTest, AddGetNumberChildren) {
    Base* val1 = new Op(7);
    Base* val2 = new Op(4);
    Base* test = new Add(val1,val2);
    EXPECT_EQ(test -> number_of_children(), 2);
    delete val1;
    delete val2;
    delete test;
}

#endif
