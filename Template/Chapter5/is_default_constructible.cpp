
#include <iostream>

// is_default_constructible

template <typename T, typename U>
struct is_same
{
    static const bool value = false;
};
template <typename T>
struct is_same<T, T>
{
    static const bool value = true;
};
template <typename T1, typename T2>
const bool IsSame_v = is_same<T1, T2>::value;

class A
{
};
class B
{
public:
    B(int x) : x_(x){};

private:
    int x_;
};

template <typename T>
struct is_default_constructible
{
private:
    template <typename U, typename = decltype(U())>
    // 如果U()是可用的，走这个函数。
    static std::true_type test(int);

    template <typename>
    static std::false_type test(...);

public:
    static constexpr bool value = decltype(test<T>(0))::value;
};

template <typename T>
class IsDefaultConstructibleHelper
{
private:
    template <typename U, typename = decltype(U())>
    static std::true_type test(int);

    template <typename>
    static std::false_type test(...);

public:
    using type = decltype(test<T>(0));
};

template <typename T>
class IsDefConstructible : public IsDefaultConstructibleHelper<T>::type
{
};

int main()
{
    std::cout << is_default_constructible<int>::value << std::endl;    // 1
    std::cout << is_default_constructible<double>::value << std::endl; // 1
    std::cout << is_default_constructible<A>::value << std::endl;      // 1
    std::cout << is_default_constructible<B>::value << std::endl;      // 0
    std::cout << IsDefConstructible<B>::value << std::endl;            // 0
    std::cout << std::is_default_constructible<B>::value << std::endl; // 0
    return 0;
}