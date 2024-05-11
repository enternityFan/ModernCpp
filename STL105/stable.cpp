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
    vector<int> v = {5, 3, 8, 1, 9, 1, 2, 6, 7, 4};
    display(v);
    stable_sort(v.begin(), v.end());
    display(v);
    auto cnt = count(v.begin(), v.end(), 1);
    cout << "count of 1: " << cnt << endl;
    auto val = accumulate(v.begin(), v.end(), 0);
    cout << "sum of all elements: " << val << endl;
    // transform_reduce 是 C++ 17 中引入的新函数，
    // 它结合了 std::transform 和 std::reduce 的功能，用于在给定范围上应用一元或二元操作，并对结果进行累积。 auto val2 = transfrorm_reduce(v.begin(), v.end(), 0, plus<int>(), abs);
    // cout << "sum of absolute values: " << val2 << endl;
    // transform_inclusive_scan

    // transform_exclusive_scan

    // 计算两个向量的内积
    int result = std::inner_product(v.begin(), v.end(), v.begin(), 0);

    std::cout << "Inner product: " << result << std::endl;
    // 计算了这个向量中相邻元素的差值
    adjacent_difference(v.begin(), v.end(), v.begin());
    display(v);

    // 查询属性
    v = {5, 3, 8, 1, 9, 1, 2, 2, 6, 7, 4};
    auto any = any_of(v.begin(), v.end(), [](int x)
                      { return x > 5; });
    auto all = all_of(v.begin(), v.end(), [](int x)
                      { return x > 0; });
    auto none = none_of(v.begin(), v.end(), [](int x)
                        { return x > 5; });
    cout << "any > 5: " << any << endl;
    cout << "all > 0: " << all << endl;
    cout << "none > 5: " << none << endl;
    vector<int> v2 = {5, 3, 8, 1, 9, 1, 2, 6, 7, 4, 6};
    auto equal2 = equal(v.begin(), v.end(), v2.begin());
    cout << "v == v2: " << equal2 << endl;
    auto mismatch2 = mismatch(v.begin(), v.end(), v2.begin());
    // mismath是一个pair，first指向容器1中第一个不一样的，second指向容器2中第一个不一样的
    cout << "first mismatch: " << *mismatch2.first << " " << *mismatch2.second << endl;
    // 字母序比较
    cout << "v < v2: " << lexicographical_compare(v.begin(), v.end(), v2.begin(), v2.end()) << endl;
    // 查找序列中第一对相邻的重复元素,用于未排序的序列
    auto adjacent_find2 = adjacent_find(v.begin(), v.end());
    if (adjacent_find2 != v.end())
    {
        cout << "first adjacent pair: " << *adjacent_find2 << " " << *(adjacent_find2 + 1) << endl;
    }
    puts("");
    // equal_range用于排序的序列中的元素的范围
    sort(v.begin(), v.end());
    auto equal_range2 = equal_range(v.begin(), v.end(), 2);
    cout << "equal range of 2: " << *equal_range2.first << " " << *equal_range2.second << endl;
    // partition用于将序列分成两个子序列，第一个子序列中的元素都小于等于某个值，第二个子序列中的元素都大于某个值
    auto it = lower_bound(v.begin(), v.end(), 2);
    auto it2 = upper_bound(v.begin(), v.end(), 2);
    cout << "partition: " << *it << " " << *it2 << endl; // 查找上下边界
    bool is_find = binary_search(v.begin(), v.end(), 2);
    cout << "is 2 in v: " << is_find << endl; // 二分查找
    auto max_val = max_element(v.begin(), v.end());
    auto min_val = min_element(v.begin(), v.end());
    cout << "max value: " << *max_val << " min value: " << *min_val << endl; // 最大值和最小值
    auto maxmin_val = minmax_element(v.begin(), v.end());
    cout << "min value: " << *maxmin_val.first << " max value: " << *maxmin_val.second << endl; // 最大值和最小值
    return 0;
}