

#include <iostream>

using namespace std;

// 函数模板可以提供非类型模板参数
template <typename T, typename U, int val>
auto Add(T a, U b)
{
    return a + b + val;
}

// cpp17
template <typename T, typename U, auto val = 40.3>
auto Add(T a, U b)
{
    return a + b + val;
}
int main()
{
    int a = 10, b = 20;
    cout << Add(a, b) << endl;
    ;
    return 0;
}
