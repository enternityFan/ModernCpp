#include <iostream>
#include <type_traits>

template <typename T, typename SFINAE =
                          std::void_t<decltype(std::declval<T>() + std::declval<T>()), typename T::type, decltype(&T::value), decltype(&T::f)>>
auto add(const T &t1, const T &t2)
{

    return t1 + t2;
}

struct Test
{
    int operator+(const Test &other) const
    {
        return this->value + other.value;
    }
    using type = void;
    void f() const {};
    int value = 0;
};
struct Test2
{
    int operator+(const Test &other) const
    {
        return this->value + other.value;
    }
    Test(int val) : value(val) {}
    using type = void;
    void f() const {};
    int value = 0;
};
int main()
{

    Test t{1};
    add(t, t);
    Test2 t2{2};
    add(t2,t2);
    // add(1,2);

    return 0;
}