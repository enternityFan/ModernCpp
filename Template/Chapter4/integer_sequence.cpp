#include <iostream>
#include <utility>
#include <c++/7/utility>

// integer_sequence 产生序列
template <typename INTSEQ, unsigned int NewElem>
struct IntSeq_PushBack;

template <typename T, unsigned int... Elems, unsigned int NewElem>
struct IntSeq_PushBack<std::integer_sequence<T, Elems...>, NewElem>
{
    using type = std::integer_sequence<T, Elems..., NewElem>;
};

template <typename T, unsigned int N>
struct Integer_sequence
{
    using type = typename IntSeq_PushBack<typename Integer_sequence<T, N - 1>::type, N - 1>::type;
};

template <typename T>
struct Integer_sequence<T, 1>
{
    using type = std::integer_sequence<T, 0>;
};

int main()
{
    std::make_integer_sequence<int, 5> seq;
    std::cout << "size of seq: " << seq.size() << std::endl;

    return 0;
}