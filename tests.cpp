#include "methods.h"
#include "gtest/gtest.h"


TEST(mainLogic, t1)
{
    const char* str = "4*(1+2)/3";
    float result = mainLogic(str);
    EXPECT_EQ(result, 4);
}


TEST(mainLogic, t2)
{
    const char* str = "9-2*2+1";
    float result = mainLogic(str);
    EXPECT_EQ(result, 6);
}

TEST(mainLogic, t3)
{
    const char* str = "8/2+5-4*2";
    float result = mainLogic(str);
    EXPECT_EQ(result, 1);
}
TEST(mainLogic, t4)
{
    const char* str = "((4+2)*(5-3))";
    float result = mainLogic(str);
    EXPECT_EQ(result, 12);
}








int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
