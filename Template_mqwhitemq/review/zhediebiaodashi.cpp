
#include <iostream>
#include <vector>
#include <type_traits>
#include <string>
using namespace std;

template <typename... Args>
void print(Args &&...args)
{
    ((cout << args << " "),...); // 一元右折
    (...,(cout << args << " ")); // 一元左折
}

template <int... I>
constexpr int v_right = (I - ...); // 一元右折

template <int... I>
constexpr int v_left = (... - I); // 一元左折


template<typename... Args>
void print_v(Args &&...args)
{
    (std::cout << ... << args) << '\n'; // 二元左折
    (std::cout << args << ... << '\n'); // 二元右折
}

template<int... I>
constexpr int v_sum 

int main()
{

    print("hello", "world", 123, 4.56);
    std::cout << v_right<1, 2, 3, 4, 5> << std::endl;
    std::cout << v_left<1, 2, 3, 4, 5> << std::endl;

    return 0;
}