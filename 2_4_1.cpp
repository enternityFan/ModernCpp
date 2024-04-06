#include <iostream>

using namespace std;

// 可变参数模板
template <typename... T>
void myvtfunct(T... args)
{
    cout << "-----------start--------" << endl;
    cout << sizeof...(args) << endl;
    cout << sizeof...(T) << endl;
    cout << "-----------end-----------" << endl;
}
void myvtfunct2() // 这是一个普通函数，而不是函数模板
{
    cout << "参数包展开时执行了递归终止函数myvtfunct2()" << endl;
}
template <typename T, typename... U>
void myvtfunct2(T arg1, U... args)
{
    cout << "收到的参数值为: " << arg1 << endl;
    myvtfunct2(args...);
}

// cpp17利用 if constexpr 实现可变参数模板
template <typename T, typename... U>
void myvtfunct3(T arg1, U... args)
{
    cout << "收到的参数值为: " << arg1 << endl;
    if constexpr (sizeof...(args) == 0)
    {
        cout << "参数包为空" << endl;
    }
    else
    {
        myvtfunct3(args...);
    }
}

// 可变参数模板的重载
template <typename... T>
void myfunc(T... args)
{
    cout << "myfunc(T... args) is running" << endl;
}

template <typename... T>
void myfunc(T *...args)
{
    cout << "myfunc(T*... args) is running" << endl;
}

void myfunc(int arg)
{

    cout << "myfunc(int arg) is running" << endl;
}

int main()
{
    myvtfunct();
    myvtfunct(10, 20);
    myvtfunct(10, 25.8, "abc", 68);
    myvtfunct<double, double>(10, 25.8, "abc", 68, 73);

    // 下面会自动展开
    myvtfunct2(10, "abc", 12.7);
    myvtfunct3(10, "abc", 12.7);

    myfunc(1);
    myfunc(nullptr);
    myfunc(nullptr,23);
    myfunc((int *)nullptr);
    return 0;
}