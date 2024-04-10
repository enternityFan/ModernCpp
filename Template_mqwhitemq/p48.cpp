#include <iostream>
#include <type_traits>
#include <concepts>

// 约束 a b都是整数类型

// 下面这个Int也是一个概念，也就是说我们编译器求值的都可以作为概念。
template <typename Ty>
concept Int = std::is_same_v<Ty, int>;

decltype(auto) max(const Int auto &a, const std::integral auto &b)
{
    return a > b ? a : b;
}

int main()
{

    max(1, 2);
    // max('1', '2');
    return 0;
}