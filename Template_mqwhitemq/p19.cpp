#include <iostream>

// 类的静态数据成员
struct X
{
    // static int n;       // 声明
    static const int m = 20; // 这不是定义，仍然是声明。
    //static inline int m = 20; // 此时是定义,cpp17支持。
};

// int X::n = 10; // 定义

// 读取编译时常量，不是ODR使用。


struct limits{
    template<typename T>
    static const T min; // 静态数据成员模板的声明
};

template<typename T>
const T limits::min = {}; // 静态数据成员模板的定义


int main()
{
    int b = X::m;                    // 没有问题,不是ODR使用
//    std::cout << &X::m << std::endl; // UB,未定义。
    int c = limits::min<int>;

    return 0;
}