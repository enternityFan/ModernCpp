

#include <iostream>
#include <map>
using namespace std;

template <typename T>
using str_map_t = std::map<std::string, T>;
//模板别名
int main()
{

    str_map_t<int> m;
    m["hello"] = 1;
    return 0;
}
