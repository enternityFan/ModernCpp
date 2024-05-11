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
    std::vector<int> v = {1, 2, 3, 4, 5};
    std::vector<int> v2 = {6, 7, 8, 9, 10};
    display(v);
    display(v2);
    fill(v2.begin(), v2.end(), 0);
    display(v2);
    generate(v2.begin(), v2.end(), [](){static int i = 0; return i++;});
    display(v2);
    iota(v.begin(), v.end(), 10);// 以10为起始值，将v中每个元素的值设置为其下标+10
    display(v);
    replace_if(v.begin(), v.end(), [](int x){return x % 2 == 0;}, 0); // 将v中偶数元素的值设置为0
    display(v);

    return 0;
}
