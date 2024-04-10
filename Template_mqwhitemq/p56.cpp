#include <iostream>

// 约束实现偏特化
template <typename T>
concept have_type = requires {
    typename T::type;
};

template <typename T>
struct X
{
    static void f()
    {
        std::cout << "X<T>::f()" << std::endl;
    }
};

// 满足have_type，才可以匹配上这个偏特化。
template <have_type T>
struct X<T>
{
    using type = typename T::type;
    static void f()
    {
        std::puts("偏特化 T::type");
    }
};

struct Test
{
    using type = int;
};

struct Test2
{
};

int main()
{
    X<Test>::f();
    X<Test2>::f();

    return 0;
}