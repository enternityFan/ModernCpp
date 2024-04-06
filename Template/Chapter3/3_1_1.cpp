#include <iostream>

using namespace std;

// 完美转发
template <typename F, typename... T>
void funcMiddle_Temp(F f,T&&... t){
    f(std::forward<T>(t)...) ; // 完美转发
}

void funcLast(int v1, int &v2)
{
    ++v2; // 改变v2值，让其自增1 cout << v1 +v2 << endl; }
}

//将目标函数中的返回值通过转发函数返回给调用者函数

template <typename F, typename... T>
auto funcMiddle(F f, T&&... t) -> decltype(f(std::forward<T>(t)...))
{
    return f(std::forward<T>(t)...); // 返回目标函数的返回值
}

int funcLast2(int v1, int &v2)
{
    ++v2; // 改变v2值，让其自增1
    return v1 + v2; // 返回目标函数的返回值
}


int main()
{
    int j = 70;
    funcMiddle_Temp(funcLast, 10, j); // 调用完美转发函数，传入参数10和j的引用
    cout <<"j="<<j<<endl; // 输出j=71
    cout << funcMiddle(funcLast2, 10, j) << endl; // 调用完美转发函数，传入参数10和j的引用，并返回目标函数的返回值
    return 0;
}