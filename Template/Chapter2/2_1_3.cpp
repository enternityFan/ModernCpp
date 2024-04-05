#include <iostream>



using namespace std;

// 模板参数推断

template<typename V, typename T,typename U>
V Sub(T a, U b){
    return a - b;
}

template<typename T,typename U>
auto Add(T a, U b) -> decltype(a + b){
    return a + b;
}

template<typename T>
T mydouble(T a){
    return a * 2;
}

double mydouble(double a){
    return a * 2;
}

int main(){
    int a = 10;
    int b = 5;
    cout << Sub<int,int,double>(a,b) << endl; // 推断为double类型
    // 仅推断V为double，其他的让编译器推断
    cout << Sub<double>(a,b) << endl; 

    //各种推断说明
    cout << mydouble(a) << endl; // 自动推断,推断为int类型(若无普通函数)
    cout << mydouble<double>(a) << endl; // 显式指定类型,推断为double类型
    cout << mydouble(a) << endl; // 调用普通函数
    cout << mydouble<>(a) << endl;//指定空模板参数列表,则调用模板函数
    return 0;
}