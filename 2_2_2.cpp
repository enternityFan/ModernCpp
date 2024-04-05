

#include <iostream>

using namespace std;

// 类模板的特化
template <typename T, typename U>
struct TC
{
    TC() { cout << "TC泛化版本构造函数" << endl; }
    void functest1() { cout << "functest1泛化版本" << endl; }
    static int m_stc; // 声明一个静态成员变量
};

template <>
void TC<double, int>::functest1() { cout << "TC<double, int>::functest1特化版本" << endl; }

template <typename T, typename U>
int TC<T, U>::m_stc = 50;

template <>
struct TC<int, int>
{
    TC() { cout << "TC泛化版本构造函数" << endl; }
    // 按照普通函数的方式写即可。
    void functest1() { cout << "functest1特化版本" << endl; }
    // 特化版本可以新增成员等。
    void functest2() { cout << "functest2特化版本" << endl; }
    static int m_stc; // 声明一个静态成员变量
};
int TC<int, int>::m_stc = 100;

template <typename U>
struct TC<float, U>
{
    TC() { cout << "TC<float, U>偏特化版本构造函数" << endl; }
    void functest1() { cout << "functest1<float, U>特化版本" << endl; }
};

template <typename T, typename U>
struct TC<const T, U *>
{
    TC() { cout << "TC<const T, U*>参数范围偏特化版本构造函数" << endl; }
    void functest1() { cout << "functest1<const T, U*>参数范围特化版本" << endl; }
};
int main()
{
    TC<int, float> mytc;
    mytc.functest1();
    TC<double, int> mytc1;
    cout << "mytc1.m_stc = " << mytc1.m_stc << endl;
    mytc1.functest1();
    TC<int, int> mytc2;
    mytc2.functest1();
    mytc2.functest2();
    TC<int, int> mytc3;
    cout << "mytc3.m_stc = " << mytc3.m_stc << endl;

    TC<float, int> mytc4;
    mytc4.functest1(); // 偏特化
    TC<const float, int *> mytc5;
    mytc5.functest1();
    return 0;
}
