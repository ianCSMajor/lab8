#ifndef __DIV_TEST_HPP__
#define __DIV_TEST_HPP__

#include "gtest/gtest.h"

#include "div.hpp"
#include "op.hpp"
TEST(DivTest, DivEvaluatePos) {
    Base* val1 = new Op(7);
    Base* val2 = new Op(4);
    Base* test = new Div(val1,val2);
    EXPECT_NEAR(test -> evaluate(), 1.75, 0.001);
}

TEST(DivTest, DivPrintPos) {
    Base* val1 = new Op(7);
    Base* val2 = new Op(4);
    Base* test = new Div(val1,val2);
    EXPECT_EQ(test -> stringify(), "7.000000 / 4.000000");
}
TEST(DivTest, DivGetChildOne) {
    Base* val1 = new Op(7);
    Base* val2 = new Op(4);
    Base* test = new Div(val1,val2);
    EXPECT_EQ(test -> get_child(1)->evaluate(), 7);
}
TEST(DivTest, DivGetChildTwo) {
    Base* val1 = new Op(7);
    Base* val2 = new Op(4);
    Base* test = new Div(val1,val2);
    EXPECT_EQ(test -> get_child(2)->evaluate(), 4);
}
TEST(DivTest, DivGetNumberChildren) {
    Base* val1 = new Op(7);
    Base* val2 = new Op(4);
    Base* test = new Div(val1,val2);
    EXPECT_EQ(test -> number_of_children(), 2);
}

#endif
