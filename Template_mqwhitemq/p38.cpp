#include <iostream>


template<typename T,typename T2 = typename T::type>
void f(int){std::cout << "int\n";}

template<typename T2>
void f(double){std::cout << "double\n";}


int main(){
    f<int>(1); // 代换失败。所以看编译错误是没有找到重载模板函数，
    //匹配到double当我写了double后。
    std::cout << int{} << std::endl;
    return 0;
}