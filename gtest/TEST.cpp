#include <gtest/gtest.h>
#include <iostream>

template <typename T>
auto add(const T a, const T &b)
{
    return a + b;
}

int Factorial(int n)
{
    int result = 1;
    for (int i = 1; i <= n; ++i)
    {
        result *= i;
    }
    return result;
}

TEST(SuiteName, TestAdd)
{
    EXPECT_EQ(add(1, 2), 3);
    EXPECT_EQ(add(1.0, 2.0), 3.0);
    EXPECT_EQ(add(1.0f, 2.0f), 3.0f);
    EXPECT_EQ(add(true, false), 1);
    EXPECT_EQ(add(10, 3), 12) << "FAILED: EXPECT:12, ACTUAL:10+3=13";
}

TEST(ADDTEST, ADDTEST_TRUE)
{
    int num = 1;
    EXPECT_EQ(num, 1);
}

// 下面三个 TEST 都是属于同一个 test suite，即 FactorialTest
TEST(FactorialTest, Negative)
{
    EXPECT_EQ(Factorial(-5), 1);  // 测试负数
}

TEST(FactorialTest, Zero){
    EXPECT_EQ(Factorial(0), 1);
}
TEST(FactorialTest, Positive){
    EXPECT_EQ(Factorial(5), 120);
}

int main(int argc, char **argv)
{
    std::cout << "Running main() from gtest_main.cc\n";
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
