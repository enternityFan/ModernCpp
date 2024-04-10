#include <iostream>

// 这是一个非常经典的例子
// 说明待决与非待决查找规则
void f() { std::cout << "全局" << std::endl; }

template <typename T>
struct X
{
    void f() const { std::cout << "X\n"; }
};

template <typename T>
struct Y : X<T>
{
    void t() const
    {
        this->f(); // X
    }

    void t2() const
    {
        f(); // 全局
    }

    // 是否this访问成员有区别的
};

int main()
{

    Y<void> y;
    y.t();
    y.t2();

    return 0;
}