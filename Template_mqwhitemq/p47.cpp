#include <iostream>
#include <type_traits>


//利用约束与概念实现函数模板add

// 定义个概念
template<typename T>
//等号左边是概念，等号右边是约束表达式。
concept Add = requires(T a){
    a + a; // 这就要求传入的对象必须支持 operator+
};
template<Add T>
auto add(const T& a, const T& b){
    return a + b;
}







int main() {

    //谓词
    constexpr bool v = Add<int>; //true,因为int可以加
    std::cout << std::boolalpha << v << std::endl; //true

    return 0;
}