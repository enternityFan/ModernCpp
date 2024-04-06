
#include <iostream>

// 借助void_t和declval实现is_copy_assignable
template <typename T, typename U = std::void_t<>>
struct is_copy_assignable : std::false_type
{
};

template <typename T>
struct is_copy_assignable<T, std::void_t<decltype(std::declval<T &>() = std::declval<const T &>())>> : std::true_type
{
};

int main()
{
    // 测试
    static_assert(is_copy_assignable<int>::value, "int is copy assignable");
    static_assert(is_copy_assignable<int &>::value, "int& is copy assignable");
    //static_assert(is_copy_assignable<const int>::value, "const int is copy assignable");
    //static_assert(is_copy_assignable<const int &>::value, "const int& is copy assignable");
    static_assert(!is_copy_assignable<void>::value, "void is not copy assignable");
    static_assert(!is_copy_assignable<int[3]>::value, "int[3] is not copy assignable");
    return 0;
}