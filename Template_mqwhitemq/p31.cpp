#include <iostream>

void g(double) { std::cout << "g(double)\n"; }
// 对待决名和非待决名的名字查找和绑定有所不同的。
// 非待决名在模板定义点查找并绑定，即使模板实例化点有更好的匹配，也保持该绑定。

template <typename T>
struct S
{
    void f() const
    {
        g(1); // g(double)
    }
};

void g(int) { std::cout << "g(int)\n"; }

int main()
{
    g(1); // g(int)
    S<int> s;
    s.f();
    return 0;
}