#include "gtest/gtest.h"
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
	 delete val1;     delete val2;     delete test;
}
TEST(AddTest, AddGetChildOne) {
    Base* val1 = new Op(7);
    Base* val2 = new Op(4);
    Base* test = new Add(val1,val2);
    EXPECT_EQ(test -> get_child(1)->evaluate(), 7);
 delete val1;     delete val2;     delete test;
}
TEST(AddTest, AddGetChildTwo) {
    Base* val1 = new Op(7);
    Base* val2 = new Op(4);
    Base* test = new Add(val1,val2);
    EXPECT_EQ(test -> get_child(2)->evaluate(), 4);
 delete val1;     delete val2;     delete test;
}
TEST(AddTest, AddGetNumberChildren) {
    Base* val1 = new Op(7);
    Base* val2 = new Op(4);
    Base* test = new Add(val1,val2);
    EXPECT_EQ(test -> number_of_children(), 2);
 delete val1;     delete val2;     delete test;
}

TEST(SubTest, SubEvaluateZero) {
    Base* val1 = new Op(7);
    Base* val2 = new Op(7);
    Base* test = new Sub(val1, val2);
    EXPECT_NEAR(test -> evaluate(), 0, 0.1);
 delete val1;     delete val2;     delete test;
}
TEST(SubTest, SubStringifyZero) {
    Base* val1 = new Op(7);
    Base* val2 = new Op(7);
    Base* test = new Sub(val1, val2);
    EXPECT_EQ(test -> stringify(), "7.000000 - 7.000000");
 delete val1;     delete val2;     delete test;
}
TEST(SubTest, SubGetChildOne) {
    Base* val1 = new Op(7);
    Base* val2 = new Op(4);
    Base* test = new Sub(val1,val2);
    EXPECT_EQ(test -> get_child(1)->evaluate(), 7);
 delete val1;     delete val2;     delete test;
}
TEST(SubTest, SubGetChildTwo) {
    Base* val1 = new Op(7);
    Base* val2 = new Op(4);
    Base* test = new Sub(val1,val2);
    EXPECT_EQ(test -> get_child(2)->evaluate(), 4);
 delete val1;     delete val2;     delete test;
}

TEST(SubTest, SubGetNumberChildren) {
    Base* val1 = new Op(7);
    Base* val2 = new Op(4);
    Base* test = new Sub(val1,val2);
    EXPECT_EQ(test -> number_of_children(), 2);
 delete val1;     delete val2;     delete test;
}


TEST(MultTest, MultEvaluatePos) {
    Base* val1 = new Op(7.5);
    Base* val2 = new Op(4);
    Base* test = new Mult(val1, val2);
    EXPECT_NEAR(test -> evaluate(), 30, 0.001);
 delete val1;     delete val2;     delete test;
}
TEST(MultTest, MultStringifyPos) {
    Base* val1 = new Op(7.5);
    Base* val2 = new Op(4);
    Base* test = new Mult(val1, val2);
    EXPECT_EQ(test -> stringify(), "7.500000 * 4.000000");
 delete val1;     delete val2;     delete test;
}
TEST(MultTest, MultGetChildOne) {
    Base* val1 = new Op(7);
    Base* val2 = new Op(4);
    Base* test = new Mult(val1,val2);
    EXPECT_EQ(test -> get_child(1)->evaluate(), 7);
 delete val1;     delete val2;     delete test;
}
TEST(MultTest, MultGetChildTwo) {
    Base* val1 = new Op(7);
    Base* val2 = new Op(4);
    Base* test = new Mult(val1,val2);
    EXPECT_EQ(test -> get_child(2)->evaluate(), 4);
 delete val1;     delete val2;     delete test;
}
TEST(MultTest, MultGetNumberChildren) {
    Base* val1 = new Op(7);
    Base* val2 = new Op(4);
    Base* test = new Mult(val1,val2);
    EXPECT_EQ(test -> number_of_children(), 2);
 delete val1;     delete val2;     delete test;
}


TEST(DivTest, DivEvaluatePos) {
    Base* val1 = new Op(7);
    Base* val2 = new Op(4);
    Base* test = new Div(val1,val2);
    EXPECT_NEAR(test -> evaluate(), 1.75, 0.001);
 delete val1;     delete val2;     delete test;
}

TEST(DivTest, DivPrintPos) {
    Base* val1 = new Op(7);
    Base* val2 = new Op(4);
    Base* test = new Div(val1,val2);
    EXPECT_EQ(test -> stringify(), "7.000000 / 4.000000");
 delete val1;     delete val2;     delete test;
}
TEST(DivTest, DivGetChildOne) {
    Base* val1 = new Op(7);
    Base* val2 = new Op(4);
    Base* test = new Div(val1,val2);
    EXPECT_EQ(test -> get_child(1)->evaluate(), 7);
 delete val1;     delete val2;     delete test;
}
TEST(DivTest, DivGetChildTwo) {
    Base* val1 = new Op(7);
    Base* val2 = new Op(4);
    Base* test = new Div(val1,val2);
    EXPECT_EQ(test -> get_child(2)->evaluate(), 4);
 delete val1;     delete val2;     delete test;
}
TEST(DivTest, DivGetNumberChildren) {
    Base* val1 = new Op(7);
    Base* val2 = new Op(4);
    Base* test = new Div(val1,val2);
    EXPECT_EQ(test -> number_of_children(), 2);
 delete val1;     delete val2;     delete test;
}


TEST(PowTest, PowEvaluateOne){
    Base* val1 = new Op(9);
    Base* val2 = new Op(0);
    Base* test = new Pow(val1,val2);
    EXPECT_NEAR(test -> evaluate(), 1, 0.1);
 delete val1;     delete val2;     delete test;
}
TEST(PowTest, PowPrintOne) {
    Base* val1 = new Op(9);
    Base* val2 = new Op(0);
    Base* test = new Pow(val1,val2);
    EXPECT_EQ(test -> stringify(), "9.000000 ** 0.000000");
 delete val1;     delete val2;     delete test;
}
TEST(PowTest, PowGetChildOne) {
    Base* val1 = new Op(7);
    Base* val2 = new Op(4);
    Base* test = new Pow(val1,val2);
    EXPECT_EQ(test -> get_child(1)->evaluate(), 7);
 delete val1;     delete val2;     delete test;
}
TEST(PowTest, PowGetChildTwo) {
    Base* val1 = new Op(7);
    Base* val2 = new Op(4);
    Base* test = new Pow(val1,val2);
    EXPECT_EQ(test -> get_child(2)->evaluate(), 4);
 delete val1;     delete val2;     delete test;
}
TEST(PowTest, PowGetNumberChildren) {
    Base* val1 = new Op(7);
    Base* val2 = new Op(4);
    Base* test = new Pow(val1,val2);
    EXPECT_EQ(test -> number_of_children(), 2);
 delete val1;     delete val2;     delete test;
}


TEST(RandTest, RandEvaluateNonZero) {
    srand(1);
    Base* test = new Rand();
    EXPECT_EQ(test->evaluate(), 83);
delete test;
}
TEST(RandTest, RandStringifyNonZero) {
    srand(1);
    Base* test = new Rand();
    EXPECT_EQ(test->stringify(),"83.000000");
delete test;
}
TEST(RandTest, RandEvaluateSame) {
    srand(1);
    Base* test = new Rand();
    EXPECT_EQ(test -> evaluate(), 83);
delete test;
}
TEST(RandTest, RandStringifySame) {
    srand(1);
    Base* test = new Rand();
    EXPECT_EQ(test->stringify(),"83.000000");
delete test;
}
TEST(RandTest, RandGetChildZero) {
    Base* test = new Rand();
    EXPECT_EQ(test -> get_child(2), nullptr);
delete test;
}
TEST(RandTest, RandGetNumberChildren) {
    Base* test = new Rand();
    EXPECT_EQ(test -> number_of_children(), 0);
delete test;
}


TEST(OpTest, OpEvaluateNonZero) {
    Base* test = new Op(8);
    EXPECT_EQ(test->evaluate(), 8);
delete test;
}

TEST(OpTest, OpPrintNonZero) {
    Base* test = new Op(8);
    EXPECT_EQ(test->stringify(), "8.000000");
delete test;
}
TEST(OpTest, OpGetChildZero) {
    Base* test = new Op(7);
    EXPECT_EQ(test -> get_child(2), nullptr);
delete test;
}
TEST(OpTest, OpGetNumberChildren) {
    Base* test = new Op(7);
    EXPECT_EQ(test -> number_of_children(), 0);
delete test;
}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
