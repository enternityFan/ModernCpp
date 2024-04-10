#include <iostream>

template <typename T>
concept C2 = requires(T x) {
    //*x必须合法
    // T::inner必须存在
    // *x可以隐式转换到T::inner
    {
        *x
    } -> std::convertible_to<typename T::inner>;
    // 表达式x + 1必须合法
    // 并且这个表达式必须是int ,std::same_as<decltype(x + 1), int>
    {
        x + 1
    } -> std::same_as<int>;
    {
        x.~T()
    } noexcept; // 要求T::~T() 不会抛出异常。
    {
        x.f()
    }
    nonexcept; // 要求x.f()不会抛出异常。
};

struct X
{
    int operator*() const
    {
        return 0;
    }
    int operator+(int) const { return 0; }
    using inner = int;
};

int main()
{
    std::cout << std::boolalpha << C2<X> << std::endl; // true
    return 0;
}