#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

void display(vector<int> &v)
{
    for (auto i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5, 4, 5};
    // 使用fill copy move 使用的是operator=运算符，也就是说对象已经构造好了。
    // uninitialized_fill,uninitialized_copy,uninitialized_move可以用来在未构造的对象上做操作。
    uninitialized_fill(v.begin(), v.end(), 0);
    display(v);

    destroy(v.begin(), v.end());
    // 使用destroy可以销毁对象，但是不能对已经销毁的对象做操作。
    vector<int> v2 = {1, 2, 3, 4, 5, 4, 5};
    uninitialized_copy_n(v2.begin(), 5, 42); // 填充n个
    display(v);
    return 0;
}