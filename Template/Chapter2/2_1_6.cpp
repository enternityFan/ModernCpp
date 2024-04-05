

#include <iostream>

using namespace std;

// 普通函数
int mf(int tmp1, int tmp2) { return 1; }
typedef int (*FunType)(int, int); // 函数指针类型定义

// 函数模板可以提供默认的模板参数
template <typename T, typename F = FunType>
void testfunc(T i, T j, F funcpoint = mf)
{
    cout << funcpoint(i, j) << endl;
}

// 默认参数可以放在前面
template <typename T = int, typename U>
void testfunc2(U m)
{
    T tmpvalue = m;
    cout << tmpvalue << endl;
}

int main()
{
    testfunc(1, 2); // 调用普通函数
    testfunc2(12);  // 调用带默认参数的函数模板
    return 0;
}
