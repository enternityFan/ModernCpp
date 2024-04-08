#include <iostream>



template<typename T>
struct Test{
    Test(T v):t{v}{}
private:
    T t;
};

template<class Ty,std::size_t size>
struct array{
    Ty arr[size];
};

template<typename T, typename... Args>
array(T t,Args...)->array<T,sizeof...(Args)+1>;//+1是为了把T算进去

//用户自定义推导
Test(int) -> Test<std::size_t>;
// 模板名称实际被推导的类型a-->模板名称<想要让类型a被推导为的类型>

int main(){
    Test t{1};
    array a{1,2,3};
    return 0;
}