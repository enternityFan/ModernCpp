#include <iostream>

// remove_all_extents 把数组的数组类型部分去除，只保留元素类型
template<typename T>
struct remove_all_extents {
    using type = T;
};

template<typename T, size_t N>
struct remove_all_extents<T[N]> {
    using type = typename remove_all_extents<T>::type;//元编程的写法，递归调用自己
};

template<typename T>
struct remove_all_extents<T[]> {
    //无界数组
    using type = typename remove_all_extents<T>::type; //元编程的写法，递归调用自己
};




int main()
{
    int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};
    std::cout << typeid(std::remove_all_extents<decltype(arr)>::type).name() << std::endl; // 输出：i

    return 0;
}