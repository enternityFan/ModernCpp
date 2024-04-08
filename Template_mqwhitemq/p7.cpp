#include <iostream>
#include <string>
#include <numeric>

//sum支持任意类型，任意个数
template<typename ... Args,typename RT = std::common_type_t<Args...>>
RT sum(const Args&... args){
    RT _[]{args...};
    //注意，下面用0的方式不好，会造成精度削减。
    //return std::accumulate(std::begin(_),std::end(_),RT(0));
    return std::accumulate(std::begin(_),std::end(_),RT{});


}






void f(const char* ,int, double){std::puts("值");}
void f(const char** ,int*, double*){std::puts("&");}

template<typename... Args> //形参包
void fun2(Args... args){

    f(args...); // f(arg0,arg1,arg2)
    f(&args...);
}

template<typename... Args> 
void print(const Args&... args){
    int _[] = {(std::cout << args << " ",0)...};

}

template<typename T,std::size_t N,typename... Args> 
void f(const T(&array)[N],Args... index){
    print(array[index]...);// array[indx]是模板
}

int main(){
    // 可变参数 printf c语言的，其实是变长实参
    fun2("luse",1,1.2);
    print("hello",1,2.3);
    printf("\n");
    f({1,2,3,4,5},0,1,2,3,4);
    std::common_type_t<int,double,float> a = 1.2;
    std::cout << typeid(a).name() << std::endl;
    double ret = sum(1,2,3.4,5.61);
    std::cout << ret << std::endl;
    return 0;
}