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
    std::vector<int> v1 = {1, 2, 3, 4, 5};
    std::vector<int> v2 = {3, 4, 5, 6, 7};

    // 定义一个向量用于存储差集
    std::vector<int> difference;

    // 计算两个向量的差集
    std::set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(difference));

    // 输出差集
    std::cout << "Difference of v1 and v2: ";
    display(difference);


    // 定义一个向量用于存储并集
    std::vector<int> union_set;

    // 计算两个向量的并集
    std::set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(union_set));
    display(union_set);


    // 定义一个向量用于存储交集
    std::vector<int> intersection_set;

    // 计算两个向量的交集
    std::set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(intersection_set));
    display(intersection_set);
    //返回在A中不在B中和在B中不在A中的元素


    // 定义一个向量用于存储A中不在B中和在B中不在A中的元素
    std::vector<int> symmetric_difference_set;

    // 计算两个向量的对称差集
    std::set_symmetric_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(symmetric_difference_set));
    display(symmetric_difference_set);
    //includes
    std::vector<int> includes_set;
    std::includes(v1.begin(), v1.end(), v2.begin(), v2.end());
    display(includes_set);//A是否包含B的所有元素
    //merge
    std::vector<int> merge_set;
    std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(merge_set));
    display(merge_set);//合并两个集合


    return 0;
}