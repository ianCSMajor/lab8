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
}
TEST(PowTest, PowPrintOne) {
    Base* val1 = new Op(9);
    Base* val2 = new Op(0);
    Base* test = new Pow(val1,val2);
    EXPECT_EQ(test -> stringify(), "9.000000 ** 0.000000");
}
#endif
