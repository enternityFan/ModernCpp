#include <iostream>


// 表现一种编译器的分支逻辑
template<bool b,class T,class U>
struct conditional {
    using type = T;
};

template<class T,class U>
struct conditional<false,T,U> {
    using type = U;
};

int main()
{
    conditional<true,int,double>::type x;
    std::cout << typeid(x).name() << std::endl; // int


    conditional<false,int,double>::type y;
    std::cout << typeid(y).name() << std::endl; // double
    return 0;
}