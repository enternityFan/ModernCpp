#include <iostream>

// 变量模板偏特化
template <typename T>
const char *s = "?";

// 偏特化，对指针这一“类”类型
template <typename T>
const char *s<T *> = "pointer to ";

template <typename T>
const char *s<T[]> = "array"; // 偏特化，但是只对T[]这一类类型，而不是数组类型。





int main()
{
    std::cout << s<int> << std::endl;
    std::cout << s<int *> << std::endl;
    std::cout << s<int[]> << std::endl;
    std::cout << s<double[]> << std::endl;
    std::cout << s<double[1]> << std::endl; // 输出 "?"因为他是double[1],不是double[]

    return 0;
}