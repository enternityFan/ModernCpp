#include <iostream>

template<typename T>
struct X
{
    T t;

};


int main(){

    X<int> x1; 
    X x{1}; // cpp17 CTAD


    return 0;
}