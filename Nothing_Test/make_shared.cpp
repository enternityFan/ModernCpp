#include <iostream>
#include <memory>

using namespace std;


void* operator new(size_t size) //重载全局operator new
{
    cout << "operator new called" << endl;
return malloc(size);
}

int main() {
    shared_ptr<int> p1(new int(10)); //会调用两次new
    printf("============\n");
    auto p2 = make_shared<int>(20);
    printf("============\n");
    shared_ptr<int> p3(new int(30)); //会调用两次new
    return 0;
}