#include <iostream>
#include <string>

template <typename... Args>
void print(const Args &...args)
{
    int _[]{(std::cout << args << " ", 0)...};
    ((std::cout << args << " "), ...); // 一元右折叠
}

// 一元右折叠(E 运算符 ...)
// 一元左折叠(... 运算符 E)
// 折叠表达式是左折叠还是右折叠，取决于...是在形参包的左还是右

template <int... I>
constexpr int v_right = (I - ...);

template <int... I>
constexpr int v_left = (... - I);

// 二元折叠表达式
template <typename... Args>
void print(Args &&...args)
{
    // 但是下面的写法是很垃圾的。
    (std::cout << ... << args) << std::endl; // 二元右折叠
}

// 二元左折叠(I 运算符 ... 运算符 E)
// I: std::cout
// 运算符 ... 运算符: << ... <<
// E: args

template <int... I>
constexpr int v = (I + ... + 10); // 二元右折叠

template <int... I>
constexpr int v2 = (10 + ... + I); // 二元左折叠

template <typename E, typename... I>
E sum2(E &&first, I &&...rest)
{
    return (first - ... - rest);
}

int main()
{
    //(4 - (5 - 6))
    std::cout << v_right<4, 5, 6> << std::endl; // 1
    //((4-5) - 6)
    std::cout << v_left<4, 5, 6> << std::endl; // -7
    // 加法左右折叠没啥区别。。
    // 1 + (2+(3+(4+10)))
    std::cout << v<1, 2, 3, 4> << std::endl;
    // (((10+1)+2)+3)+4
    std::cout << v2<1, 2, 3, 4> << std::endl;

    // 
    std::cout << sum2(1, 2, 3) << std::endl; // 10
    return 0;
}