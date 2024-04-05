#include <vector>
#include <list>
using namespace std;


template<typename T, template<typename W> typename Container = vector>
class myclass
{
public:
    Container<T> data; // 成员变量，使用模板参数定义的容器类型
};






int main()
{
    myclass<int, vector> myvecobj;   // int是容器中的元素类型，vector是容器类型
    myclass<double, list> mylistobj; // double是容器中的元素类型，list是容器类型

    rturn 0;
}