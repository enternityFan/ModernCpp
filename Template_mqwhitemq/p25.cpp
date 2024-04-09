#include <iostream>
// 特化的成员与总结
template <typename T>
struct A
{
    struct B
    {
    };
    template <typename U>
    struct C
    {
    };
};

template <>
struct A<void>
{
    void f();
};

void A<void>::f()
{
    std::cout << "void A::f()" << std::endl;
}

// 特化成员类A<char>的情况下 B类的定义
template <>
struct A<char>::B
{
    void f(); // 类内声明
};
void A<char>::B::f()
{ // 类外定义
    std::cout << "char A::B::f()" << std::endl;
}

// 特化成员类模板A<int>
template <>
template <typename U>
struct A<int>::C
{
    void f();
};

template <>
template <typename U>
void A<int>::C<U>::f()
{
    std::cout << "int A::C<U>::f()" << std::endl;
}

// 类内成员函数模板的特化

struct X
{
    template <typename T>
    void f(T) {}

    template <>
    void f<int>(int x)
    {
        // 类内特化
        std::cout << "int X::f(int)" << std::endl;
    }
};
template <>
void X::f<double>(double x)
{
    // 类内特化
    std::cout << "double X::f(int)" << std::endl;
}






int main()
{
    A<void> a;
    a.f();
    A<char> a_c;
    A<char>::B b_c;
    b_c.f();

    A<int>::C<void> c_v;
    c_v.f();
    X x;
    x.f(1);
    x.f(1.0);
    return 0;
}