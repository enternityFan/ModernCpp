#include <iostream>

template<typename T = int>

struct X{};

struct Test{
    //X x;//类中不允许省略<>
    //static inline X x2; // 也不行
    X<> x; // 允许
};

int main(){
    X<> x1;
    X x2;
    return 0;
}