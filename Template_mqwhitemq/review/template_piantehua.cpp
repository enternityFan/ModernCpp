
#include <iostream>
#include <vector>
#include <type_traits>
#include <string>
using namespace std;

// 变量模板偏特化
template <typename T>
constexpr const char *s = "?";
template <typename T>
constexpr const char *s<T *> = "pointer";
template <typename T>
constexpr const char *s<T &> = "reference";

// 类模板偏特化
template <typename T, typename U>
struct X
{
    void f_T_U();
};
template <typename T, typename T2>
void X<T, T2>::f_T_U()
{
    cout << "X<T,T2>::f_T_U()" << endl;
}

template <typename T>
struct X<T, int>
{
    void f_T_int();
};
template <typename T>
void X<T, int>::f_T_int()
{
    cout << "X<T,int>::f_T_int()" << endl;
}

int main()
{
    X<int, char> x;
    x.f_T_U(); // OK!
    X<void, int> x2;
    x2.f_T_int(); // OK!
    return 0;
}