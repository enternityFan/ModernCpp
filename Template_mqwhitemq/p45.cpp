#include <iostream>
#incluude < type_traits>

template <typename T, typename = void>
struct X
{
    static void f()
    {
        std::puts("主模板");
    }
};

template <typename T>
// 要求有f
struct X<T, std::void_t<typename T::type, decltype(&T::f)>>
{
    using type = typename T::type;
    static void f() { std::puts("偏特化模板"); }
};

struct Test
{
    using type = int;
    void f() const
    {
        std::puts("Test::f()");
    }
};

struct Test2
{
};

int main()
{
    X<Test>::f();
    X<int>::f();

    return 0;
}