#include <iostream>

// 类型要求
template <typename T>
struct S
{
};

template <typename T>
using Ref = T &;

template <typename T>
concept C = requires {
    typename T::X2;   // 要求嵌套类型
    typename T::type; // 要求嵌套类型
    typename S<T>;    // 要求类模板特化。
    typename Ref<T>;  // 要求别名模板特化。
};

struct X
{
    using X2 = int;
    using type = int;
};

struct Y
{
    struct X2
    {
    };
    using type = int;
};

int main()
{
    // 只要求有X2，不管X2的形式。
    std::cout << std::boolalpha << C<X> << std::endl; // true
    std::cout << std::boolalpha << C<Y> << std::endl; // true

    return 0;
}