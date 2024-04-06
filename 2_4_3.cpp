#include <iostream>

using namespace std;

// 可变参表达式
template <typename... T>
auto print_result(T const&... args)
{
    (cout << ... << args) << "结束" << endl;
    return (... + args);
}


template <typename... T>
void print_calc(T const&... args)
{
    //cout << print_result(2 * args...) << endl;
    //下面两个和上面等价
    //cout << print_result(args * 2 ...) << endl;
    cout << print_result(args + args ...) << endl;
}

int main()
{
    cout << print_result(1, 2, 3, 4, 5) << endl;  // 12345结束 15
    print_calc(1, 2, 3, 4, 5);  // 30

    return 0;
}