#include <iostream>

using namespace std;

class A
{
public:
    A();
    ~A();

    void func()
    {
        printf("Hello, world!\n");
    }
};

int main()
{

    cout << sizeof(A) << endl;
    return 0;
}