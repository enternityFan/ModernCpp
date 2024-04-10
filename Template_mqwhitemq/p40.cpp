#include <iostream>

// 代换失败(SFINAE错误)与硬错误。

template <typename T>
struct B
{
    using type = typename T::type;
};

template <typename T>
void foo(double)
{
    std::cout << "SFINAE" << std::endl;
}

template <
    class T,
    class U = typename T::type, // 要求T必须有别名type
    // 如果没有T没有type，就会代换失败。
    class V = typename B<T>::type>
void foo(int){
    std::cout <<"SFINAE T::type B<T>::type"<<std::endl;
}

int main()
{

    struct C{using type = int;};
    foo<void>(1);
    foo<B<C>>(1);



    return 0;
}