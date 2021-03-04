#ifndef __SUB_TEST_HPP__
#define __SUB_TEST_HPP__

#include "gtest/gtest.h"

#include "sub.hpp"
#include "op.hpp"
TEST(SubTest, SubEvaluateZero) {
    Base* val1 = new Op(7);
    Base* val2 = new Op(7);
    Base* test = new Sub(val1, val2);
    EXPECT_NEAR(test -> evaluate(), 0, 0.1);
    delete val1;
    delete val2;
    delete test;
}
TEST(SubTest, SubStringifyZero) {
    Base* val1 = new Op(7);
    Base* val2 = new Op(7);
    Base* test = new Sub(val1, val2);
    EXPECT_EQ(test -> stringify(), "7.000000 - 7.000000");
    delete val1;
    delete val2;
    delete test;
}
TEST(SubTest, SubGetChildOne) {
    Base* val1 = new Op(7);
    Base* val2 = new Op(4);
    Base* test = new Sub(val1,val2);
    EXPECT_EQ(test -> get_child(0)->evaluate(), 7);
    delete val1;
    delete val2;
    delete test;
}
TEST(SubTest, SubGetChildTwo) {
    Base* val1 = new Op(7);
    Base* val2 = new Op(4);
    Base* test = new Sub(val1,val2);
    EXPECT_EQ(test -> get_child(1)->evaluate(), 4);
    delete val1;
    delete val2;
    delete test;
}
TEST(SubTest, SubGetNumberChildren) {
    Base* val1 = new Op(7);
    Base* val2 = new Op(4);
    Base* test = new Sub(val1,val2);
    EXPECT_EQ(test -> number_of_children(), 2);
    delete val1;
    delete val2;
    delete test;
}

#endif
