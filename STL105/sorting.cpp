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
    display(v);
    // 部分排序
    partial_sort(v.begin(), v.begin() + 5, v.end());
    display(v);
    // 对第n个进行排序，用于将序列中的第 n 个元素（按升序或降序排列）
    // 放置在其在完全排序后应该处于的位置，而不必对整个序列进行排序。
    nth_element(v.begin(), v.begin() + 3, v.end());
    display(v);
    sort_heap(v.begin(), v.end());
    display(v);
    printf("======================\n");
    v = {5, 3, 8, 1, 9, 2, 6, 7, 4};
    display(v);
    //用于在给定范围内执行原地归并操作，即将两个已经
    //有序的序列合并成一个有序序列，将结果存储在原始范围内。
    inplace_merge(v.begin(), v.begin() + 3, v.end());
    display(v);

    return 0;
}