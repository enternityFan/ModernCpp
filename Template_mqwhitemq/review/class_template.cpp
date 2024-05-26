
#include <iostream>
#include <vector>
#include <type_traits>
#include <string>
using namespace std;

template <typename T>
struct Test
{
    T t;
    Test(T t_) : t(t_) {}
};

// 用户自定义的推导指引
template <typename T>
Test(int) -> Test<std::size_t>; // 推导指引: 对于int类型，推导为Test<std::size_t>
template <typename T>
Test(T *) -> Test<T[]>; // 推导指引: 对于*类型，推导为数组

template <class Ty, std::size_t size>
struct array
{
    Ty arr[size];
};

template <typename Ty, typename... Args>
array(Ty t, Args... args) -> array<Ty, sizeof...(Args) + 1>;

// 模板模板形参
template <typename T>
struct X
{
};
template <template <typename T> typename C>
struct Test2
{
};

Test2<X> t1; // 实例化Test<X>模板模板参数
// Test2<X> t2;      // 实例化Test<X>模板模板参数

// 有名字的模板模板形参
template <typename T>
struct my_array
{
    T arr[10];
};

template <typename Ty, template <typename T> typename C = my_array>
struct Array
{
    C<Ty> arr;
};

Array<int, my_array> arr2; // 实例化Array<int,my_array>模板模板参数
Array<int> arr3;           // 实例化Array<int,my_array>模板模板参数,my_array为默认模板模板参数

// 有名字的模板模板形参包

template <typename T>
struct X2
{
};

template <template <typename T> typename... C>
struct Test4
{
};
Test4<X, X2, X, X, X> tt;

// 类模板中的成员函数模板

template <typename T>
struct class_template
{
    template <typename U>
    void print(U u)
    {
        cout << u << endl;
    }
};

// 普通类中的成员函数模板
struct normal_class
{
    template <typename T>
    void print(T t)
    {
        cout << t << endl;
    }
};

template <typename... Args>
struct TTest
{
    X(Args... args) : t(args...)
    {
        cout << "TTest" << endl;
    }
    std::tuple<Args...> t;
};

int main()
{

    Test<int> ti(10);
    Test t3{10}; // cpp17 类模板实参推导,不单单是聚合体

    ::array<int, 10> arr1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (auto i : arr1.arr)
    {
        cout << i << " ";
    }

    return 0;
}