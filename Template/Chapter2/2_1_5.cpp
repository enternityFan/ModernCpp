#include <iostream>



using namespace std;

// 模板函数特化
template<typename T, typename U>
void myfunc(T& t, U& u){
    printf("void myfunc(T& t, U& u)[泛化版本] is running!\n");
}

template<>
void myfunc<int,double>(int& p,double& q){
    printf("void myfunc<int,double>(int& p,double& q)[全特化版本] is running!\n");
}

//通过重载实现模板参数数量上的偏特化
template<typename U>
void myfunc(double& p,U& q){
    printf("void myfunc(double& p,U& q)[偏特化版本] is running!\n");
}




int main(){
//当普通函数和函数模板都比较合适的时候，编译器会优先选择普通函数执行。
    int a = 1;
    double b = 2.0;
    char* c = "hello";
    char* d = "world";
    myfunc(c, d); // 调用普通函数

    myfunc<int,double>(a, b); // 调用全特化版本
    myfunc(a, b); // 调用全特化版本
    myfunc(b,d); // 调用偏特化版本
    return 0;
}