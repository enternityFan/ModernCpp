#include <iostream>

template <template <typename T> class C, typename U>
struct X
{
    C<int> t; // 模板模板形参
};
template <template <typename T> class... C>
struct X2
{
    // 模板模板形参包
};
template <typename T>
struct Y
{
};

template <typename T>
struct Z
{
};

int main()
{
    X<Y, int> x; // 模板实例化
    std::cout << "Hello, World!" << std::endl;
    X2<Z, Y, Y, Z> x2;

    return 0;
}