#include <iostream>

using namespace std;



template <typename T>
void myfunc(const T &t)
{
    cout << "myfunc 函数模板执行了" << endl;
}

void myfunc(int i)
{
    cout << "myfunc 函数执行了" << endl;
}

// 帮手模板
template <typename T>
struct MEB
{
    using type = T;
};
 MEB<int>::type i = 10;







int main()
{
    myfunc(10);
    return 0;
}