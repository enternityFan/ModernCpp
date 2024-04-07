#include <iostream>
using namespace std;

// 原始的方式，不过我们需要指定一个U
template <typename U, typename T>
U funcsum(const T *begin, const T *end)
{
    U sum{};
    for (;;)
    {
        sum += (*begin);
        if (begin == end)
            break;
        ++begin;
    }
    return sum;
}

// 固定萃取类模板的版本
template <typename T>
struct SumFixedTraits; // 不需要实现

template <>
struct SumFixedTraits<char>
{
    using sumT = int;
};
template <>
struct SumFixedTraits<int>
{
    using sumT = __int64_t;
};

template <typename T>
auto funcsum2(const T *begin, const T *end)
{
    using sumT = typename SumFixedTraits<T>::sumT; // 固定萃取的应用.
    sumT sum{};
    for (;;)
    {
        sum += (*begin);
        if (begin == end)
            break;
        ++begin;
    }
    return sum;
}

int main()
{
    int myintarray1[] = {10, 15, 20};
    int myintarray2[] = {1000000000, 1500000000, 2000000000}; // 10亿，15亿，20亿
    char mychararray[] = "abc";                               // 97,98,99
    cout << funcsum<__int64_t>(&myintarray1[0], &myintarray1[2]) << endl;
    cout << funcsum<__int64_t>(&myintarray2[0], &myintarray2[2]) << endl;
    cout << (int)(funcsum<__int64_t>(&mychararray[0], &mychararray[2])) << endl;

    cout << funcsum2(&myintarray1[0], &myintarray1[2]) << endl;
    cout << funcsum2(&myintarray2[0], &myintarray2[2]) << endl;
    cout << (int)(funcsum2(&mychararray[0], &mychararray[2])) << endl;
    return 0;
}