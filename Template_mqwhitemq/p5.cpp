#include <iostream>
#include <string>

//非类型模板参数
template<std::size_t N>
void f(){
    std::cout << "N = " << N << std::endl;
}

int main(){
    f<100>();
}