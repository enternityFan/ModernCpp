#include <iostream>
#include <type_traits>
#include <concepts>

template<typename T>
void f(T){
    //只要T::type是合法表达式，就返回true，否则false;
    constexpr bool v = requires{T::type;};
    std::cout << std::boolalpha << v << std::endl;
}

struct X
{
    using type = int;
};

int main()
{

    return 0;
}