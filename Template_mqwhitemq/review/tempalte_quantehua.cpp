
#include <iostream>
#include <vector>
#include <type_traits>
#include <string>
using namespace std;

template <typename T, typename T2>
auto f(const T &t, const T2 &t2)
{
    return t + t2;
}

template <>
auto f(const string &s, const string &s2)
{
    return s + s2;
}
// 类模板全特化
template <typename T>
struct is_void2
{

    static constexpr bool value = false;
};

template <>
struct is_void2<void>
{
    static constexpr bool value = true;
};

template <typename T>
struct X
{
    void f()
    {
        cout << "X::f()" << endl;
    }
};
template <>
struct X<void>
{
    void f()
    {
        cout << "X<void>::f()" << endl;
    }
};

// 变量模板全特化
template <typename T>
constexpr const char *s = "??";

template <>
constexpr const char *s<int> = "int";

template <>
constexpr const char *s<double> = "double";

template <>
constexpr const char *s<string> = "string";

template <typename T>
struct A
{
    struct B
    {
    };

    template <class U>
    struct C
    {
    };
};

// 特化模板类
template <>
struct A<void>
{
    void f();
};
void A<void>::f()
{
    cout << "A<void>::f()" << endl;
}

// 特化成员类
template <>
struct A<int>::B
{
    void g();
};

void A<int>::B::g()
{
    cout << "A<int>::B::g()" << endl;
}

int main()
{

    std::cout << f(1, 2) << std::endl;
    std::cout << f(1.0, 2.0) << std::endl;
    std::cout << f<string, string>("hello", "world") << std::endl;
    std::cout << is_void2<void>::value << std::endl;
    std::cout << is_void2<int>::value << std::endl;
    X<int> x;
    x.f();
    X<void> x2;
    x2.f();
    std::cout << s<int> << std::endl;
    std::cout << s<double> << std::endl;
    std::cout << s<string> << std::endl;

    return 0;
}