#include <iostream>
#include <string>
#include <type_traits>
using namespace std::string_literals;

template <typename T = int>
void f()
{
}
// decltype(true ? T1{} : T2{})这是一个不求值语境

auto max(const auto &a, const auto &b)
{ // cpp20特性
    return (a > b) ? a : b;
}

// 第二垃圾的版本，比较麻烦
template <typename T1, typename T2>
// 这时会保留const &的限定符
decltype(auto) max2_1(const T1 &a, const T2 &b)
{ // cpp14特性
    return (a > b) ? a : b;
}
// 第二垃圾的版本，比较麻烦
template <typename T1, typename T2>
// auto的话会没有const &，按照模板实参推导去做
auto max2(const T1 &a, const T2 &b)
{ // cpp14特性
    return (a > b) ? a : b;
}

// 第三垃圾的版本，比较麻烦
template <typename T1, typename T2>
auto max3(const T1 &a, const T2 &b) -> decltype(true ? a : b)
{
    // 注意这里decltype(true?a:b)，会导致有const &的限定符的代入。
    return (a > b) ? a : b;
}
// 第四垃圾的版本，比较麻烦
template <typename T1, typename T2, typename RT = decltype(true ? T1{} : T2{})>
RT max4(const T1 &a, const T2 &b)
{
    return (a > b) ? a : b;
}
// 最垃圾的版本
template <typename RT = double, typename T1, typename T2>
RT max5(const T1 &a, const T2 &b)
{
    return (a > b) ? a : b;
}

int main()
{
    f();         // calls f<int>()
    f<double>(); // calls f<double>()

    std::cout << ::max(1, 1.2) << std::endl;
    std::cout << ::max<std::string>("1", "2"s) << std::endl;
    std::cout << ::max2(1, 1.2) << std::endl;
    std::cout << ::max2<std::string>("1", "2"s) << std::endl;
    std::cout << ::max3(1, 1.2) << std::endl;
    std::cout << ::max3<std::string>("1", "2"s) << std::endl;
    std::cout << ::max4(1, 1.2) << std::endl;
    std::cout << ::max4<std::string>("1", "2"s) << std::endl;

    // 下面两行代码结果相等是因为三目运算符不会影响这个表达式的类型
    // 三目运算符会做一个复杂的转换来找到一个公共类型。
    using T = decltype(true ? 1 : 2.0);   // double
    using T2 = decltype(false ? 1 : 2.0); // double
    std::cout << std::is_same_v<T, double> << std::endl;
    std::cout << std::is_same_v<T2, double> << std::endl;

    return 0;
}