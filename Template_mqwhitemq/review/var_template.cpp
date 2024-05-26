
#include <iostream>
#include <vector>
#include <type_traits>
#include <string>
using namespace std;

template <typename T>
T v;

template <typename T>
constexpr T v2{};

// 实现is_same_v
template <typename T, typename U>
struct is_same2 : false_type
{
};

template <typename T>
struct is_same2<T, T> : true_type
{
};

template <typename T, typename U>
constexpr bool is_same_v = is_same2<T, U>::value;

// 默认实参的模板形参
template <typename T = int>
constexpr T v3{};
int b = v3<>;

template <std::size_t N = 10>
constexpr int arr[N] = {0};

// 可变参数模板
template <std::size_t... values>
constexpr std::size_t array[] = {values...};

// 类静态数据成员模板
struct limits
{
    template <typename T>
    static const T min; // 声明
};

template <typename T>
const T limits<T>::min = 0; // 定义

int main()
{
    cout << ::is_same_v<decltype(v<int>), int> << endl;
    cout << ::is_same_v<decltype(v2<bool>), const bool> << endl;
    for (auto i : arr<10>)
        cout << i << " ";
    cout << endl;
    for (auto i : array<1, 2, 3, 4, 5>)
    {
        cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}