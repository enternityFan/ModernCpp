#include <iostream>
#include <vector>
#include <algorithm>

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
    vector<int> v = {5, 3, 8, 1, 9, 2, 6, 7, 4};
    make_heap(begin(v), end(v));
    display(v);

    v.push_back(10);
    push_heap(begin(v), end(v));
    display(v);
    pop_heap(begin(v), end(v)); // 此时并不会删除，而是给他放到了最后。
    display(v);
    // 注意，使用sort_heap()函数会使序列失去堆的属性。
    sort_heap(begin(v), end(v));
    display(v);
    return 0;
}
