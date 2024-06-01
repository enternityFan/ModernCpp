
#include <iostream>
#include <vector>
#include <type_traits>
#include <string>
using namespace std;

template <typename A>
struct B
{
    using type = typename A::type;
};

template <class T,
          class U = typename T::type,
          class V = typename B<T>::type>
void foo(int)
{
    std::puts("SFINAE T::type B<T>::type");
}

template <typename T>
void foo(double)
{
    std::puts("SFINAE T");
}

// 利用SFINAE 可以快速的暴露错误
template <typename T>
auto add(const T &t1, const T &t2) -> decltype(t1 + t2)
{
    std::puts("SFINAE +");
    return t1 + t2;
}

// enable_if

template <bool B, class T = void>
struct enable_if2
{
};

template <class T>
struct enable_if2<true, T>
{
    using type = T;
};

template <bool B, class T = void>
using enable_if_t2 = typename enable_if2<B, T>::type;

template <typename T, typename SFINAE = enable_if_t2<std::is_integral<T>::value>>
void foo2(T t)
{
    std::cout << "foo2: " << t << std::endl;
}

int main()
{
    struct C
    {
        using type = int;
    };
    foo<B<C>>(0); // SFINAE T::type B<T>::type
    foo<C>(0.0);  // SFINAE T

    return 0;
}