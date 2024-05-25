#include <iostream>
#include <complex>
#include <string>
#include <atomic>
#include <memory>
using namespace std;

// 仍然是模板函数。
void printColl(const auto &coll)
{
    for (const auto &elem : coll)
    {
        cout << elem << " ";
    }
    cout << endl;
}

// 模板有隐式要求所有的操作是支持的。
// 下面内容隐含了T支持比较，二是支持拷贝赋值。
auto mymax(const auto &a, const auto &b)
{
    return a > b ? a : b;
}

template <typename T>
concept SupportLessThan = requires(T x) { x < x; };

template <typename T>
    requires copyable<T> && SupportLessThan<T>
T mymax2(const T &a, const T &b)
{
    return a > b ? a : b;
}

template <typename T>
concept Integral = std::is_integral_v<T>;

auto mymax3(const Integral auto a, const Integral auto b)
{
    return a > b ? a : b;
}

template <typename T1, typename T2>
auto mymax4(const T1 &a, const T2 &b)
{
    return a > b ? a : b;

}

int main()
{
    std::shared_ptr<int> p1(new int(10));
    int arr[] = {1, 2, 3, 4, 5};
    printColl(arr);
    string str = "Hello, world!";
    printColl(str);
    // complex<double> c1(1, 2), c2(3, 4);
    // cout << mymax(c1, c2) << endl; // error,不支持 <
    // atomic<int> a1{8},a2{10};
    // cout << mymax(a1, a2) << endl; // error,不支持拷贝
    mymax2(1, 2);

    mymax2(1.0, 2.0);
    // mymax3(1.0, 2.0);
    mymax3(1, 2);

    return 0;
}