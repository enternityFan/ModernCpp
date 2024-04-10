#include <iostream>
#include <type_traits>
#include <concepts>

// 嵌套要求
template <typename T>
concept C3 = requires(T a) {
    // 编译期可以产生bool值就可以了。
    //requires std::is_same_v<T, int>; // 要求是int类型
    //requires std::same_as<T, int>;   // 要求是int类型
    requires requires { a + a; }; // 约束表达式
    requires sizeof(a) > 4; // 要求a > 4
};

int main()
{
    std::cout << C3<int> << std::endl;
    std::cout << C3<double> << std::endl;
    return 0;
}