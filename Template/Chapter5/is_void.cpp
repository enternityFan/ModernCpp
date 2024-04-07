#include <iostream>

// is_void的实现
template <typename T>
struct is_void
{
    static const bool value = false;
};

template <>
struct is_void<void>
{
    static const bool value = true;
};

template <typename T, typename U>
struct is_same
{
    static const bool value = false;
};
template <typename T>
struct is_same<T, T>
{
    static const bool value = true;
};
template <typename T1, typename T2>
const bool IsSame_v = is_same<T1, T2>::value;
int main()
{
    std::cout << "is_void<void>::value = " << is_void<void>::value << std::endl;
    std::cout << "is_void<int>::value = " << is_void<int>::value << std::endl;
    std::cout << "IsSame_v<int, int> = " << IsSame_v<int, int> << std::endl;
    std::cout << "IsSame_v<int, double> = " << IsSame_v<int, double> << std::endl;
    std::cout << "IsSame_v<int, double> = " << is_same<int, double>::value << std::endl;
    return 0;
}