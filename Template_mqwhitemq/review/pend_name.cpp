
#include <iostream>
#include <vector>
#include <type_traits>
#include <string>
using namespace std;

// 消除歧义
template <typename T>
typename T::type f(const T &t)
{
    return 0;
}

struct X
{
    using type = int;
};

template <typename T>
struct S
{
    template <typename U>
    void f() {}
};

template <typename T>
void bar()
{
    S<T> s;
    s.template f<int>();
};

int main()
{
    int a = f(X{});

    return 0;
}