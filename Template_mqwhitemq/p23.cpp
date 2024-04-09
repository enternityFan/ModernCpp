#include <iostream>

template<typename T>
constexpr const char* s = "??";

template<>
constexpr const char* s<int> = "int";

int main(){
    std::cout << s<int> << std::endl;
    std::cout << s<double> << std::endl;
    return 0;
}