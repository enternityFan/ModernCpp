#include <iostream>

template <typename T>
const typename T::type &f(const T &t)
{
    //返回值中typename T是复用。
    return 0;
}

struct X
{
    using type = int;
};

int main()
{
    X x;
    f(x);

    return 0;
}