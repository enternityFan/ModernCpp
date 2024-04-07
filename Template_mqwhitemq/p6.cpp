#include <iostream>
#include <string>

template<typename T>
void test(T){
    std::puts("template");
}

void test(int){
    std::puts("int");
}

int main()
{
    test(1);
    test("1");
    test(1.2);
    return 0;
}