#include <iostream>
#include <type_traits>



//第一个SFINAE要求支持加法，第二个要求有type的别名
//template<typename T,typename SFINAE = decltype(T{} + T{}),typename SFINAE2 = typename T::type>
//上面写的也没问题，下面更简单一些，并且要求更多一些:
//当void_t的条件都满足，会返回void，否则返回false_type
template <typename T,typename SFINAE = std::void_t<decltype(T{} + T{}),typename T::type,decltype(&T::value),decltype(&T::f)>>

auto add(const T& t1, const T& t2){

    return t1 + t2;
}
//这里其实隐含了要求支持默认构造
struct Test{
    int operator+(const Test& other) const{
        return this->value + other.value;
    }
    using type = void;
    void f() const{};
    int value = 0;
};

int main() {

    Test t{1};
    add(t,t);
    //add(1,2);



    return 0;
}