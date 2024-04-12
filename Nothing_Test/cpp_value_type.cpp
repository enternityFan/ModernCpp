#include <iostream>

// 要求右值表达式，注意是右值表达式，亡值，纯右值
void f(int &&) {}

int main()
{
    int &&p = 1; // p是右值引用，但是是左值表达式
    // f(p); //编译失败
    f(std::move(p)); // move返回了亡值表达式。
    // 下面能编译通过，是因为转换到对象的右值引用类型的，类型转换表达式是亡值表达式

    f(static_cast<int &&>(p));

    // 纯右值表达式
    f(1);
    f([]
      { return 1; }());
    f(1 + 1);
    





    return 0;
}