#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

template <typename T>
// 期望传入的有iterator类型
concept Iterable = requires(T t) {
    typename T::iterator;                                // 检查类型T是否有迭代器类型
    { t.begin() } -> std::same_as<typename T::iterator>; // 检查类型T是否有begin()方法并且返回迭代器类型
    { t.end() } -> std::same_as<typename T::iterator>;   // 检查类型T是否有end()方法并且返回迭代器类型
};
template <Iterable T>
void print(T t)
{
    for (auto i = t.begin(); i != t.end(); ++i)
    {
        cout << *i << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    print(v);

    set<string> s = {"hello", "world"};
    print(s);
    int a[] = {
        3,
        3,
        3,
        3,
        32,
    };
    // print(a);

    return 0;
}