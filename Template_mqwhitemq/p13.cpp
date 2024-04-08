#include <iostream>

// 成员函数模板。
template <typename T>
struct Class_template
{
    void f(T) {}
    template <typename... Args>
    void g(Args...) {}
};

int main()
{

    Class_template<int> c;
    c.f(10);
    c.g(1, 2, 3);

    return 0;
}