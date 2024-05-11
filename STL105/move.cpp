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
    copy(v.begin(), v.end(), v.begin() + 2);
    display(v);
    std::vector<int> tmp_v(v);
    std::move(tmp_v.begin(), tmp_v.end(), v.begin() + 2);
    display(v);
    std::swap_ranges(v.begin(), v.end(), v2.begin());
    display(v);
    display(v2);
    
    return 0;
}