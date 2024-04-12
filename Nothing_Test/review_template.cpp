#include <iostream>

// 可变参数变量模板

template <std::size_t... Args>
constexpr size_t array[] = {Args...};

template <typename T, T... Args>
constexpr T array2[] = {Args...};


//类的静态成员变量模板
struct X{
    template <typename T>
    static constexpr T value = T();
};

//模板全特化
template <typename T1,typename T2>
auto func(const T1& t1, const T2& t2){
    return t1 - t2;
}

template<>
auto func(const int& t1,const double& t2){
    return t1 + t2;
}

template<typename T>
static constexpr bool value = false;
template<>
static constexpr bool value<void> = true;

int main()
{

    for (const auto &i : array<1, 2, 3, 4, 5>)
    {
        std::cout << i << ' ';
    }

    for (const auto &i : array2<int, 1, 2, 3, 4, 5>)
    {
        std::cout << i << ' ';
    }

    std::cout <<std::endl;
    std::cout << func(1,2) << std::endl;
    std::cout << func(1,2.0) << std::endl;

    return 0;
}