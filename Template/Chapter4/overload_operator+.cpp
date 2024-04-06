
#include <iostream>
#include <vector>

// template <typename T, typename U>
// std::vector<T> operator+(std::vector<T> const &vec1, std::vector<U> const &vec2);
template <typename T, typename U, typename V = std::void_t<>>
struct IfCanAdd : std::false_type
{
};

template <typename T, typename U>
struct IfCanAdd<T, U, std::void_t<decltype(std::declval<T>() + std::declval<U>())>> : std::true_type
{
};

// 实现数量相同类型不同的vector的加法
template <typename T, typename U, bool ifcando = IfCanAdd<T, U>::value>
struct VecAddResult
{
    using type = decltype(std::declval<T>() + std::declval<U>());
};

template <typename T, typename U>
struct VecAddResult<T, U, false>
{
};

template <typename T, typename U>
using VecAddResult_t = typename VecAddResult<T, U>::type;

template <typename T, typename U>
std::vector<VecAddResult_t<T, U>> operator+(std::vector<T> const &vec1, std::vector<U> const &vec2)
{ // 随便写几句代码，防止出现链接错误
    std::vector<VecAddResult_t<T, U>> tmpvec;
    return tmpvec;
}

struct elemC
{
    elemC(int tmpvalue);
    elemC operator+(const elemC &tmppar);
};

int main()
{
    std::vector<elemC> veca;
    std::vector<elemC> vecb;
    veca + vecb; // 编译没有问题

    return 0;
}