#include <iostream>
using namespace std;

template <typename... T>
using void_t = void;
// 不管传什么参数，多少参数，通通变为void类型

// Example usage:
// 判断是否含有类型
struct NoInnerType
{
    int m_i;
};
struct HaveInnerType
{
    using type = int;
    void myFunc(){};
};

template <typename T, typename U = std::void_t<>>
struct HasTypeMem : std::false_type
{
};

// 特化版本
template <typename T>
struct HasTypeMem<T, std::void_t<typename T::type>> : std::true_type
{
};

//判断是否有某个成员变量
template <typename T, typename U = std::void_t<>>
struct HasMember : std::false_type
{
};

template <typename T>
struct HasMember<T, std::void_t<decltype(T::m_i)>> : std::true_type
{
};

//判断是否有某个成员函数
template <typename T, typename U = std::void_t<>>
struct HasMemberFunc : std::false_type
{
};


template <typename T>
struct HasMemberFunc<T, std::void_t<decltype(std::declval<T>().myFunc())>> : std::true_type
{
};

int main()
{
    cout << HasTypeMem<NoInnerType>::value << endl;   // false
    cout << HasTypeMem<HaveInnerType>::value << endl; // true
    return 0;
}