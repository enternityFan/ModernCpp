#include <iostream>
#include <string>
using namespace std::string_literals;
template <typename T>
T max(T a, T b)
{
    return a > b ? a : b;
}

template <typename T>
void f(T &&t)
{
}
// 右值引用的右值引用折叠成右值引用，所有其他组合均折叠为左值引用
template <class Ty>
constexpr Ty &&forward(Ty &arg) noexcept
{
    return static_cast<Ty &&>(arg);
}

int main()
{

    std::cout << max(3, 5) << std::endl;
    std::cout << max<double>(3.3, 5) << std::endl;
    // 下面报错的主要原因是ADL，std:string是在std::下的
    // 那么也会看到std::max,这就有问题了，
    // std::cout << max<std::string>("luse"s, "1") << std::endl;
    std::cout << ::max<std::string>("luse"s, "1") << std::endl;
    int a = 10;
    f(a);  // f<int&>
    f(10); // f<int&&>

    ::forward<int>(a);    // 返回int&&,因为Ty是int，所以返回int&&
    ::forward<int &>(a);  // 返回int&,因为Ty是int&,所以返回int&
    ::forward<int &&>(a); // 返回int&&,因为Ty是int&&，所以返回int&&
    return 0;
}