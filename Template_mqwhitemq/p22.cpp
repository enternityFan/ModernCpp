#include <iostream>
#include <type_traits>

// 模板全特化

template <typename T>
struct is_void
{
    static constexpr bool value = false;
};
template <>
struct is_void<void>
{
    static constexpr bool value = true;
};

int main()
{
    std::cout << is_void<void>::value << std::endl;
    std::cout << is_void<int>::value << std::endl;

    return 0;
}