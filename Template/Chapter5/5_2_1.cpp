#include <iostream>
using namespace std;

// 值萃取
class A
{
public:
    A(int x) : m_x(x) {}
    A& operator+=(const A& rhs)
    {
        m_x += rhs.m_x;
        return *this;
    }
    int m_x;
};

template <typename T>
struct SumFixedTraits; // 不需要实现

template <>
struct SumFixedTraits<char>
{
    using sumT = int;
    static constexpr sumT initValue = 0;
};
template <>
struct SumFixedTraits<int>
{
    using sumT = __int64_t;
    static constexpr sumT initValue = 0;
};
template <>
struct SumFixedTraits<A>
{
    using sumT = A;
    inline static const sumT initValue = {0};
};
template <typename T>
auto funcsum2(const T *begin, const T *end)
{
    using sumT = typename SumFixedTraits<T>::sumT; // 固定萃取的应用.
    sumT sum = SumFixedTraits<T>::initValue;

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

    cout << funcsum2(&myintarray1[0], &myintarray1[2]) << endl;
    cout << funcsum2(&myintarray2[0], &myintarray2[2]) << endl;
    cout << (int)(funcsum2(&mychararray[0], &mychararray[2])) << endl;
    return 0;
}