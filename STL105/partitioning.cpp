#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
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
    // 当你需要将一个序列划分成满足某个条件的元素和
    // 不满足该条件的元素两部分时，std::partition 是一个很有用的算法。
    //  将偶数放在前面，奇数放在后面
    std::partition(v.begin(), v.end(), [](int n)
                   { return n % 2 == 0; });
    display(v);
    sort(v.begin(), v.end());
    display(v);
    // 循环的给rotate到后面
    rotate(v.begin(), v.begin() + 3, v.end());
    display(v);
    // 使用默认的随机数引擎来打乱向量中的元素
    std::random_device rd;                 // 获取随机设备
    std::mt19937 gen(rd());                // 使用随机设备生成种子
    std::shuffle(v.begin(), v.end(), gen); // 打乱向量中的元素
    display(v);
    sort(v.begin(), v.end());
    // std::prev_permutation 函数用于获取序列的前一个排列，如果不存在更小的排列，则返回 false，并将序列转换为最大的排列 return 0;
    //  使用 do-while 循环来生成并输出序列的所有排列
    puts("==================");
    do
    {
        for (int num : v)
        {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    } while (std::prev_permutation(v.begin(), v.end()));
    puts("==================");
    do
    {
        for (int num : v)
        {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    } while (std::next_permutation(v.begin(), v.end()));
    puts("=====================");
    reverse(v.begin(), v.end());
    display(v);
    return 0;

}