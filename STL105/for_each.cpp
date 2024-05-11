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
    std::vector<int> v2 = {1, 2, 3, 4, 5, 4, 5};
    vector<int> results;
    transform(v.begin(), v.end(), back_inserter(results),[](int x) { return x * 2; });
    display(results);
    //一个不为人知的重载
    transform(v.begin(), v.end(),v2.begin(), back_inserter(results),[](int x) { return x * 2; });
    display(results);
    return 0;
}