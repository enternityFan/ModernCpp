#include <iostream>

// 全特化细节的补充
//  特化必须在导致隐式实例化的首次使用之前，在每个发生这种使用的翻译单元中声明
template <typename T>
void f(const T &) {}

// 放在隐式实例化之前。
template <>
void f<int>(const int &) {}
void f2()
{
    f(1); // “使用”了函数模板f 隐式实例化了f<int>,如果把特化代码放在前面，就会用特化的了。
}

// 2.只有声明没有定义的模板特化可以像其他不完整类型一样使用(例如可以使用到它的指针和引用
template <class T>
class X;
template <>
class X<int>;
X<int> *p; // 正确，指向不完整类型的指针。
// X<int> x; // 错误，X<int>没有定义

/*
函数模板和变量模板的显式特化是否为 inline/constexpr/constinit/consteval
只与显式特化自身有关，主模板的声明是否带有对应说明符对它没有影响。
模板声明中出现的属性在它的显式特化中也没有效果

*/

int main()
{

    return 0;
}