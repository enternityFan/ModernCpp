#include <iostream>
#include <type_traits> 


template<typename T, typename T2>
auto f(const T& a,const T2& b){
    return a + b;
}

template<>
auto f(const double& a, const int& b){
    return a - b;
}

struct X{
    void f()const{}
};
struct X2{
    void f2()const{}
};

template<typename T>
void test(const T& t){
    t.f();
}

template<>
void test(const X2& t){
    t.f2();
}

int main(){

    std::cout << f(1,2) << std::endl;
    std::cout << f(1.0,2) << std::endl;
    test(X{});
    test(X2{});

    
}