#include <iostream>

template <std::size_t N = 66>
constexpr std::size_t v = N;

int main()
{
    constexpr int b = v<10>;
    std::cout << b << std::endl;
    std::cout << v<> << std::endl;
    std::cout << v<10> << std::endl;

    return 0;
}