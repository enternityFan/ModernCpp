#include <iostream>



using namespace std;

// 简单的模板示例

template<typename T>
T Sub(T a,T b){
    return a - b;
}

int main(){
    int a = 10;
    int b = 5;
    cout << Sub(a,b) << endl;
    cout << Sub(10.0,5.0) << endl;

    cout << Sub('a','b') << endl;

    //cout << Sub("hello","world") << endl; // 编译错误，类型不支持减法`2
    return 0;
}