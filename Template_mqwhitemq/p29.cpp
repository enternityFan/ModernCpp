#include <iostream>

// 实现is_same
template <typename T, typename U>
struct is_same
{
    static constexpr bool value = false;
};

template <class Ty>
struct is_same<Ty, Ty>
{
    static constexpr bool value = true;
};

int main()
{
    std::cout << std::is_same<int, int>::value << std::endl;    // true
    std::cout << std::is_same<int, double>::value << std::endl; // false
    std::cout << is_same<int, int>::value << std::endl;    // true
    std::cout << is_same<int, double>::value << std::endl; // false
    return 0;
}