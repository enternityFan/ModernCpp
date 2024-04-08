#include <iostream>

template<typename T>
T v;



int main(){

    //没有任何关系，是两个对象
    std::cout << &v<int> << std::endl;
    std::cout << &v<double> << std::endl;

    return 0;
}