#include <iostream>





int main(){

    int* p1 = new int(10);
    delete p1;
    p1 = nullptr; // 如果置nullptr，下面的delete就不会报错了。
    delete p1;
    delete p1;

    return 0;
}