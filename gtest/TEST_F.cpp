
#include <gtest/gtest.h>
#include <iostream>
#include <queue>
using namespace std;
class queueTestSmpl3 : public testing::Test
{ // 继承了 testing::Test
protected:
    static void SetUpTestSuite()
    {
        std::cout << "run before first case..." << std::endl;
    }

    static void TearDownTestSuite()
    {
        std::cout << "run after last case..." << std::endl;
    }

    virtual void SetUp() override
    {
        std::cout << "enter into SetUp()" << std::endl;
        q1_.push(1);
        q2_.push(2);
        q2_.push(3);
    }

    virtual void TearDown() override
    {
        std::cout << "exit from TearDown" << std::endl;
    }

    static int Double(int n)
    {
        return 2 * n;
    }

    void MapTester(const queue<int> *q)
    {
        const queue<int> *const new_q(q);

        ASSERT_EQ(q->size(), new_q->size());


        delete new_q;
    }

    queue<int> q0_;
    queue<int> q1_;
    queue<int> q2_;
};

// Tests the default c'tor.
TEST_F(QueueTestSmpl3, DefaultConstructor)
{
    // !!! 在 TEST_F 中可以使用 QueueTestSmpl3 的成员变量、成员函数
    EXPECT_EQ(0u, q0_.size());
}
