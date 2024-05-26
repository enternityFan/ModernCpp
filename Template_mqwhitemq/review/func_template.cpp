
#include <iostream>
#include <vector>
#include <type_traits>
#include <string>
using namespace std;

template <typename T>
T mymax(const T &a, const T &b)
{
    return a > b ? a : b;
}

struct ValType
{
    int v_{};
    explicit ValType(int v) : v_(v) {}
    bool operator>(const ValType &other) const
    {
        return v_ > other.v_;
    }
};

// 万能引用与引用折叠
template <typename T>
void f(T &&t) {}

template <typename T>
constexpr T &&forward(T &&Arg) noexcept
{
    return static_cast<T &&>(Arg);
}

// 默认实参
template <typename T = int>
void g(T x = 100)
{
    cout << x << endl;
}

template <typename T1, typename T2, typename RT = decltype(true ? T1{} : T2{})>
// decltype(true?T1{}:T2{}) 这里true，false无所谓的，因为三目运算符会默认使用公共的。
RT mymax2(const T1 &a, const T2 &b)
{
    return a > b ? a : b;
}
// way 3
template <typename T1, typename T2>
auto mymax3(const T1 &a, const T2 &b) -> decltype(true ? a : b)
{
    return a > b ? a : b;
}
// way4 cpp20
decltype(auto) mymax4(const auto &a, const auto &b)
{
    return a > b ? a : b;
}

// 非模板类型形参
template <std::size_t N = 100>
constexpr void f2()
{
    std::cout << "N=" << N << std::endl;
}

// 重载函数模板
template <typename T>
void test(T)
{
    std::cout << "test(T)" << std::endl;
}
void test(int)
{

    std::cout << "test(int)" << std::endl;
}

// 可变参数模板
template <typename... Args>
void print(Args... args)
{
    (std::cout << ... << args) << std::endl;
}

template <typename... Args>
void print2(Args... args)
{
    int _[] = {(std::cout << args << " ", 0)...};
}

template <typename... Args>
void print3(Args... args)
{
    int _[] = {(std::cout << args << " ", 0)...};
}

// 实现sum

template <typename... Args, typename RT = std::common_type_t<Args...>>
RT sum(Args... args)
{
    RT _[]{static_cast<RT>(args)...};
    RT n{};
    for (auto &i : _)
    {
        n += i;
    }
    return n;
}

struct TestSum
{
    int a{};
    TestSum() {}
    explicit TestSum(int a) : a(a) {}
    int operator+(const TestSum &other) const
    {
        return a + other.a;
    }
    TestSum &operator+=(const TestSum &other)
    {
        a += other.a;
        return *this;
    }
    friend ostream &operator<<(ostream &os, const TestSum &ts);
};
ostream &operator<<(ostream &os, const TestSum &ts)
{
    os << ts.a;
    return os;
}
int main()
{
    cout << mymax(1, 2) << endl;
    cout << mymax(3.14, 2.71) << endl;
    // cout << mymax("hello", "world") << endl; // 被推断为了const char [6]
    cout << mymax(string("hello"), string("world")) << endl; // 正确的调用方式
    cout << mymax<string>("hello", "world") << endl;         // 正确的调用方式
    ValType v(mymax(ValType(1), ValType(2)));
    cout << v.v_ << endl;

    int x = 10;
    f(x);               // 万能引用
    f(forward<int>(x)); // 引用折叠

    g();

    cout << mymax4(string("hello"), string("world")) << endl; // 正确的调用方式
    f2();                                                     // 输出 N=100

    test(1);
    test("");
    print(1, 2, 3, "hello");
    print2(1, 2, 3, "hello");
    std::cout << "sum(1, 2, 3, 4, 5) = " << ::sum(1, 2, 3, 4, 5) << std::endl;
    std::cout << "sum(TestSum(1), TestSum(2)) = " << ::sum(TestSum(1), TestSum(2)) << std::endl;
    std::cout << "sum(1,2.3,3.f,'h') = " << ::sum(1, 2.3, 3.f, 'h') << std::endl;
    return 0;
}