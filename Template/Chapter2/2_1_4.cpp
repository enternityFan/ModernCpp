#include <iostream>



using namespace std;

// 模板函数重载

template<typename T>
void myfunc(T tmpvalue){
    printf("void myfunc(T tmpvalue) is running!\n",__FUNCTION__);
}
template<typename T>
void myfunc(T* tmpvalue){
    printf("void myfunc(T* tmpvalue) is running!\n",__FUNCTION__);
}
void myfunc(int tmpvalue){
    printf("void myfunc(int tmpvalue) is running!\n",__FUNCTION__);
}
int main(){
//当普通函数和函数模板都比较合适的时候，编译器会优先选择普通函数执行。
    myfunc(10);
    myfunc(10.2);
    char* p = nullptr;

    myfunc(p);
    return 0;
}