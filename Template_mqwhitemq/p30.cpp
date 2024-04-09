#include <iostream>

//函数模板显式实例化
template<typename T>
void f(T){}

template void f<int>(int); // 显示实例化

int main()
{
    return 0;
}