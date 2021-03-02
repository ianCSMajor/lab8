#include "gtest/gtest.h"
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

TEST(SubTest, SubEvaluateZero) {
    Base* val1 = new Op(7);
    Base* val2 = new Op(7);
    Base* test = new Sub(val1, val2);
    EXPECT_NEAR(test -> evaluate(), 0, 0.1);
}
TEST(SubTest, SubStringifyZero) {
    Base* val1 = new Op(7);
    Base* val2 = new Op(7);
    Base* test = new Sub(val1, val2);
    EXPECT_EQ(test -> stringify(), "7.000000 - 7.000000");
}
TEST(SubTest, SubGetChildOne) {
    Base* val1 = new Op(7);
    Base* val2 = new Op(4);
    Base* test = new Sub(val1,val2);
    EXPECT_EQ(test -> get_child(1)->evaluate(), 7);
}
TEST(SubTest, SubGetChildTwo) {
    Base* val1 = new Op(7);
    Base* val2 = new Op(4);
    Base* test = new Sub(val1,val2);
    EXPECT_EQ(test -> get_child(2)->evaluate(), 4);
}

TEST(SubTest, SubGetNumberChildren) {
    Base* val1 = new Op(7);
    Base* val2 = new Op(4);
    Base* test = new Sub(val1,val2);
    EXPECT_EQ(test -> number_of_children(), 2);
}


TEST(MultTest, MultEvaluatePos) {
    Base* val1 = new Op(7.5);
    Base* val2 = new Op(4);
    Base* test = new Mult(val1, val2);
    EXPECT_NEAR(test -> evaluate(), 30, 0.001);
}
TEST(MultTest, MultStringifyPos) {
    Base* val1 = new Op(7.5);
    Base* val2 = new Op(4);
    Base* test = new Mult(val1, val2);
    EXPECT_EQ(test -> stringify(), "7.500000 * 4.000000");
}
TEST(MultTest, MultGetChildOne) {
    Base* val1 = new Op(7);
    Base* val2 = new Op(4);
    Base* test = new Mult(val1,val2);
    EXPECT_EQ(test -> get_child(1)->evaluate(), 7);
}
TEST(MultTest, MultGetChildTwo) {
    Base* val1 = new Op(7);
    Base* val2 = new Op(4);
    Base* test = new Mult(val1,val2);
    EXPECT_EQ(test -> get_child(2)->evaluate(), 4);
}
TEST(MultTest, MultGetNumberChildren) {
    Base* val1 = new Op(7);
    Base* val2 = new Op(4);
    Base* test = new Mult(val1,val2);
    EXPECT_EQ(test -> number_of_children(), 2);
}


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
TEST(PowTest, PowGetChildOne) {
    Base* val1 = new Op(7);
    Base* val2 = new Op(4);
    Base* test = new Pow(val1,val2);
    EXPECT_EQ(test -> get_child(1)->evaluate(), 7);
}
TEST(PowTest, PowGetChildTwo) {
    Base* val1 = new Op(7);
    Base* val2 = new Op(4);
    Base* test = new Pow(val1,val2);
    EXPECT_EQ(test -> get_child(2)->evaluate(), 4);
}
TEST(PowTest, PowGetNumberChildren) {
    Base* val1 = new Op(7);
    Base* val2 = new Op(4);
    Base* test = new Pow(val1,val2);
    EXPECT_EQ(test -> number_of_children(), 2);
}


TEST(RandTest, RandEvaluateNonZero) {
    srand(1);
    Base* test = new Rand();
    EXPECT_EQ(test->evaluate(), 83);
}
TEST(RandTest, RandStringifyNonZero) {
    srand(1);
    Base* test = new Rand();
    EXPECT_EQ(test->stringify(),"83.000000");
}
TEST(RandTest, RandEvaluateSame) {
    srand(1);
    Base* test = new Rand();
    EXPECT_EQ(test -> evaluate(), 83);
}
TEST(RandTest, RandStringifySame) {
    srand(1);
    Base* test = new Rand();
    EXPECT_EQ(test->stringify(),"83.000000");
}
TEST(RandTest, RandGetChildZero) {
    Base* test = new Rand();
    EXPECT_EQ(test -> get_child(2), nullptr);
}
TEST(RandTest, RandGetNumberChildren) {
    Base* test = new Rand();
    EXPECT_EQ(test -> number_of_children(), 0);
}


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



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
