#include <iosfwd>
#include <gtest/gtest.h>

double calc(double x, int n);
bool isValid(double a, double b,double h,int n);
void checkValidInput(std::istream &in);
void checkValidParams(double a, double b, double h,int n);
int countSteps(double a, double b,double h);

TEST(Calc,test1) {EXPECT_NEAR(14.0,calc(0,5), 1e-9);}
TEST(Calc,test2) {EXPECT_NEAR(2.0,calc(2,5), 1e-9);}
TEST(Calc,test3) {EXPECT_NEAR(60.0,calc(3,10), 1e-9);}
TEST(Calc,test4) {EXPECT_NEAR(2.5,calc(0.5,4), 1e-9);}
TEST(Calc,test5) {EXPECT_NEAR(5.0,calc(2.5,6), 1e-9);}
TEST(Calc,test6) {EXPECT_NEAR(1.0,calc(0,3), 1e-9);}
TEST(Calc,test7) {EXPECT_NEAR(0.0,calc(2,2), 1e-9);}
TEST(Calc,test8) {EXPECT_NEAR(0.0,calc(1,0), 1e-9);}
TEST(Calc,test9) {EXPECT_NEAR(1.0,calc(-1,5), 1e-9);}
TEST(Calc,test10) {EXPECT_NEAR(1.0,calc(-0.5,0), 1e-9);}
TEST(Calc,test11) {EXPECT_NEAR(1.0,calc(-10,3), 1e-9);}

TEST(IsValid,test1) {EXPECT_TRUE(isValid(0,10,1,5));}
TEST(IsValid,test2) {EXPECT_TRUE(isValid(3,3,1,5));}
TEST(IsValid,test3) {EXPECT_TRUE(isValid(0,10,1,0));}
TEST(IsValid,test4) {EXPECT_FALSE(isValid(10,0,1,5));}
TEST(IsValid,test5) {EXPECT_FALSE(isValid(0,10,0,5));}
TEST(IsValid,test6) {EXPECT_FALSE(isValid(0,10,-1,5));}
TEST(IsValid,test7) {EXPECT_FALSE(isValid(0,10,1,-1));}

TEST(CheckValidParams,test1){EXPECT_NO_THROW(checkValidParams(0,10,1,5));}
TEST(CheckValidParams,test2){EXPECT_THROW(checkValidParams(10,0,1,5), const char*);}
TEST(CheckValidParams,test3){EXPECT_THROW(checkValidParams(0,10,0,5), const char*);}
TEST(CheckValidParams,test4) {
    try {
        checkValidParams(0,10,1,-3);
        FAIL() << "expected exception not thrown";
    }catch(const char *ex) {
        EXPECT_STREQ("input correct data",ex);
    }
}

TEST(CheckValidInput,test1) {
    std::istringstream in("5");
    int n;
    in >> n;
    EXPECT_NO_THROW(checkValidInput(in));
}
TEST(CheckValidInput,2) {
    std::istringstream in("qwe");
    int n;
    in >> n;
    EXPECT_THROW(checkValidInput(in),const char*);
}
TEST(CheckValidInput,test3) {
    std::istringstream in("");
    int n;
    in >> n;
    EXPECT_THROW(checkValidInput(in),const char*);
}

TEST(CountSteps,test1) {EXPECT_EQ(10,countSteps(0,10,1));}
TEST(CountSteps,test2) {EXPECT_EQ(10,countSteps(0,1,0.1));}
TEST(CountSteps,test3) {EXPECT_EQ(0,countSteps(5,5,1));}
TEST(CountSteps,test4) {EXPECT_EQ(2,countSteps(0,2.5,1));}
TEST(CountSteps,test5) {EXPECT_EQ(0,countSteps(0,1,5));}

