

#include <iostream>

using namespace std;

template <typename T1>
class A
{
public:
    template <typename T2>
    A(T2 v1, T2 v2); // 构造函数模板也可以引入自己的模板参数
    template <typename T3>
    void myft(T3 t)
    {
        cout << t << endl;
    }

    T1 m_ic;
    static constexpr int m_stcvalue = 200;
};

template <typename T1>
template <typename T2>
A<T1>::A(T2 v1, T2 v2) : m_ic(v1 + v2)
{
    cout << "A<T1>::A(T2 v1, T2 v2)" << endl;
}

int main()
{
    A<float> a(1, 2); // 实例化了A< float>这样一个类型，并用int类型实例化构造函数
     a.myft(3); //3 
     A< float> a2(1.1, 2.2);
    /*A< float>类型已经被上面代码行实例化过了，这里用double类型实例 化构造函数，因为1.1和2.2都是double类型*/
    A< float> a3(11.1f, 12.2f);
     //这里用 float类型实例化构造函数，因为以f结尾的数字是 float类型

    return 0;
}
