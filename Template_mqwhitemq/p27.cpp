#include <iostream>

// 类模板偏特化

template <typename T, typename T2>
struct X
{
    void f() const {}
};

template <typename T>
struct X<void, T>
{
    void f2() const {}
    int a{};
};

// 一般不建议写到类外。
template <typename T>
void X<void, T>::f2() const
{
}

int main()
{
    X<int, int> x;
    return 0;
}