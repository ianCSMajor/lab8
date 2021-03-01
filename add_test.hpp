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
#endif
