#ifndef __MULT_TEST_HPP__
#define __MULT_TEST_HPP__

#include "gtest/gtest.h"

#include "mult.hpp"

TEST(MultTest, MultEvaluatePos) {
    Base* val1 = new Op(7.5);
    Base* val2 = new Op(4);
    Base* test = new Mult(val1, val2);
    EXPECT_NEAR(test -> evaluate(), 30, 0.001);
    delete val1;
    delete val2;
    delete test;
}
TEST(MultTest, MultStringifyPos) {
    Base* val1 = new Op(7.5);
    Base* val2 = new Op(4);
    Base* test = new Mult(val1, val2);
    EXPECT_EQ(test -> stringify(), "7.500000 * 4.000000");
    delete val1;
    delete val2;
    delete test;
}
TEST(MultTest, MultGetChildOne) {
    Base* val1 = new Op(7);
    Base* val2 = new Op(4);
    Base* test = new Mult(val1,val2);
    EXPECT_EQ(test -> get_child(1)->evaluate(), 7);
    delete val1;
    delete val2;
    delete test;
}
TEST(MultTest, MultGetChildTwo) {
    Base* val1 = new Op(7);
    Base* val2 = new Op(4);
    Base* test = new Mult(val1,val2);
    EXPECT_EQ(test -> get_child(2)->evaluate(), 4);
    delete val1;
    delete val2;
    delete test;
}
TEST(MultTest, MultGetNumberChildren) {
    Base* val1 = new Op(7);
    Base* val2 = new Op(4);
    Base* test = new Mult(val1,val2);
    EXPECT_EQ(test -> number_of_children(), 2);
    delete val1;
    delete val2;
    delete test;
}

#endif
