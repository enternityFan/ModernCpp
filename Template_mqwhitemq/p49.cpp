#include <iostream>
#include <type_traits>
#include <concepts>

template <typename T>
concept add = requires(T t) {
    t + t;
};

template <typename T>
    requires(sizeof(T) >= 4) // 这么抽象也是可以的，因为sizeof也是编译期求值的
void f(T)
{
}

// requires子句,他就是想要一个bool值的表达式。
template <typename T>
    requires requires(T t) { t + t; } // 这么抽象也是可以的，因为sizeof也是编译期求值的
void f(T)
{
}
int main()
{
    f(1);
}
