#ifndef __POW_TEST_HPP__
#define __POW_TEST_HPP__

#include "gtest/gtest.h"

#include "pow.hpp"
#include "op.hpp"
TEST(PowTest, PowEvaluateOne){
    Base* val1 = new Op(9);
    Base* val2 = new Op(0);
    Base* test = new Pow(val1,val2);
    EXPECT_NEAR(test -> evaluate(), 1, 0.1);
    delete val1; 
    delete val2;
    delete test;
}
TEST(PowTest, PowPrintOne) {
    Base* val1 = new Op(9);
    Base* val2 = new Op(0);
    Base* test = new Pow(val1,val2);
    EXPECT_EQ(test -> stringify(), "9.000000 ** 0.000000");
    delete val1;
    delete val2;
    delete test;
}
TEST(PowTest, PowGetChildOne) {
    Base* val1 = new Op(7);
    Base* val2 = new Op(4);
    Base* test = new Pow(val1,val2);
    EXPECT_EQ(test -> get_child(1)->evaluate(), 7);
    delete val1;
    delete val2;
	delete test;
}
TEST(PowTest, PowGetChildTwo) {
    Base* val1 = new Op(7);
    Base* val2 = new Op(4);
    Base* test = new Pow(val1,val2);
    EXPECT_EQ(test -> get_child(2)->evaluate(), 4);
    delete val1; 
    delete val2;
    delete test;
}
TEST(PowTest, PowGetNumberChildren) {
    Base* val1 = new Op(7);
    Base* val2 = new Op(4);
    Base* test = new Pow(val1,val2);
    EXPECT_EQ(test -> number_of_children(), 2);
    delete val1; 
    delete val2;
    delete test;
}

#endif
