

#include <iostream>

using namespace std;

// 类模板默认参数
template <typename T = char, typename U = int>
struct TC2
{
    TC2() { cout << "TC泛化版本构造函数" << endl; }
    void functest1() { cout << "functest1泛化版本" << endl; }
};

// 下面是非法的，类模板偏特化版本中的类型模板参数不可以有默认值。
// template <typename T=char> struct TC<T, int> { };

// 非类型模板参数
template <typename T, typename U, size_t arrsize = 8>
struct TC
{
    T m_arr[arrsize];
    void functest2();
};

template <typename T, typename U, size_t arrsize>
void TC<T, U, arrsize>::functest2()
{
    cout << "functest2非类型模板参数版本" << endl;
}

using IF_TCU = TC<int, float>;
int main()
{
    TC2<> mytc5;       // 都使用默认参数，则<>中什么也不用提供
    TC2<double> mytc6; //<>中第1个类型不使用默认参数，第2个类型使用默认参数
    IF_TCU mytc11;     // 等价于 TC<int, float>mytc11

    TC<double, double> mytc30;
    // 默认第3个参数是8
    for (size_t i = 0; i < 8; ++i)
    {
        mytc30.m_arr[i] = static_cast<double>(i);
    }
    cout << mytc30.m_arr[7] << endl;
    TC<double, double, 18> mytc31;
    // 注意第3个模板参数给的是一个值
    mytc31.m_arr[10] = 16.8;
    cout << mytc31.m_arr[10] << endl;
    return 0;
}
