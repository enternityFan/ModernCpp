

#include <iostream>

using namespace std;

// 类模板示例
template <typename T>
class myvector
{
public:
    using myiterator = T *; // 定义迭代器类型别名

public:
    myvector();

public:
    myvector(T tmpt) {}
    // 赋值运算符重载并不需要提供模板参数，当然也可以提供
    // 写为myvector<T>& operator=(const myvector<T>& rhs)
    myvector &operator=(const myvector &rhs);

public:
    void myfunc()
    {
        cout << "myfunc() is running!" << endl;
    }

public:
    static void mystaticfunc() { cout << "mystaticfunc()被调用" << endl; }

public:
    myiterator begin();
    myiterator end();
};

// 类外构造函数的实现
template <typename T>
myvector<T>::myvector()
{
}

template <typename T>
struct A
{

    A(T val1, T val2) { cout << "A::A(T val1, T val2)执行了!" << endl; };
    A(T val) { cout << "A::A(T val)执行了!" << endl; }
};
template <typename T>
A(T, T) -> A<double>; // 显式指定模板推断

int main()
{
    myvector<int> tmpvec; // T被替换为int
    tmpvec.myfunc();      // 调用类模板中一个普通的成员函数
    myvector<string>::mystaticfunc();
    myvector tmpvec2(12); // cpp17 自动推断。无须指定模板参数
    tmpvec2.myfunc();     // 调用类模板中一个普通的成员函数

    A aobj2(12.8);      // 推断指南cpp17
    A aobj(12.8, 12.8); // 显式指定模板参数
    return 0;
}
