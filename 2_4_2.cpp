#include <iostream>

using namespace std;

// cpp17 折叠表达式

template<typename...T>
auto add_val(T...args) {
    return (... + args);
}


template<typename...T>
auto sub_val_left(T...args){
    // 一元左折
    //((( 参数1 运算符 参数2 ) 运算符 参数3 ) … 运算符 参数N )
    return (... -args);
}

template<typename...T>
auto sub_val_right(T...args){
    // 一元右折
    //( 参数1 运算符 ( … ( 参数N-1 运算符 参数N )))
    return (args -...);
}

template<typename...T>
auto sub_val_left_b(T...args){
    //二元左折
    //((( init 运算符 参数1 ) 运算符 参数2 ) … 运算符 参数N )
    return (220 - ... - args);
}
template<typename...T>
auto sub_val_right_b(T...args){
    //二元右折
    //( 参数1 运算符 (… ( 参数N 运算符 init )))
    return (args - ... - 220);
}


int main()
{
    cout << add_val(1, 2, 3, 4, 5) << endl; // 15
    cout << sub_val_left(10,20,30,40) << endl;

    cout << sub_val_right(10,20,30,40) << endl;
    cout << sub_val_left_b(10,20,30,40) << endl;
    cout << sub_val_right_b(10,20,30,40) << endl;
    return 0;
}