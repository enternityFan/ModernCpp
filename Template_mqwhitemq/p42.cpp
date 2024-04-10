#include <iostream>

#include <type_traits>

// enable_if
// 要求T必须是int，通过SFINAE
template <typename T, typename SFINAE = std::enable_if_t<std::is_same_v<T, int>>>
void f(T) {}

// 应用示例
template <class Ty, std::size_t size>
struct array
{
    Ty arr[size];
};

// 用户自定义推导规则
template <class Type, class... Args>
//这里使用了enable_if_t来判断Args中的所有元素是否相同，如果相同，则返回Type，否则返回void
array(Type, Args...) -> array<std::enable_if_t<(std::is_same_v<Type, Args> && ...), Type>, sizeof...(Args) + 1>;

int main()
{

    f(1);
    // f(1u); // 不能编译，根据SFINAE
    // f(1.0); // 不能编译，根据SFINAE

    return 0;
}