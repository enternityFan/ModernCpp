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
    std::vector<int> v = {1, 2, 3, 4, 5,4,5};
    std::vector<int> v2 = {6, 7, 8, 9, 10};
    display(v);
    std::remove(v.begin(), v.end(), 4);
    display(v);
    v.erase(std::remove(v.begin(), v.end(), 5), v.end());
    display(v);
    //等同于下面的
    erase(v,5);
    display(v);
    v = {1, 2, 3, 4, 5,4,5};
    unique(v.begin(), v.end());
    display(v);
    //todo
    //除了上面的还有*_if,*_copy
    return 0;
}