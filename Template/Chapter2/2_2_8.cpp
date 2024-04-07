

#include <iostream>

using namespace std;

// 模板变量
template <typename T>
T g_myvar{};

// 模板特化
template <>
char g_myvar<double>{};

// 模板参数默认值
template <typename T = int>
T g_myvar;

template <typename T, int value>
T g_myvar3[value];

// 模板参数的另外一种形式
template <typename T>
struct B
{
    const static T value = {160}; // const也可以写成constexpr，{}可以不加
};

int main()
{
    g_myvar<float> = 15.6f;
    g_myvar<int> = 13;
    cout << g_myvar<float> << endl; // 15.6 cout << g_myvar<int> << endl; //13
    return 0;
}
