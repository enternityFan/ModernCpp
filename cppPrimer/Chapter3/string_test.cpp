#include <iostream>
#include <string>

using namespace std;


class mystring: public string{
    public:
        mystring(): string(){printf("default constructor\n");} // 默认构造
        mystring(const char* s): string(s){printf("constructor with char*\n");} // 构造函数
        mystring(const mystring& s): string(s){printf("copy constructor\n");} // 拷贝构造
        mystring& operator=(const mystring& s){ // 赋值运算符
            printf("assignment operator\n");
            string::operator=(s);
            return *this;
        }
        mystring(int a,char b): string(a,b){printf("constructor with int and char\n");} // 构造函数

        mystring(const mystring&& s): string(s){printf("move constructor\n");} // 移动构造



};

int* func(){
    int* a = new int(10);

    return a;
}

int main()
{
    mystring s1; // 默认构造
    mystring s2(s1); // 拷贝构造
    mystring s3("hello");
    mystring s4 = s1;
    mystring s6 = "world";
    mystring s5(10,'c');
    string s7 = "world";
    auto p = begin(s7); // 指针
    auto q = end(s7); // 指针
    printf("begin: %c, end: %c\n", *p, *(q-1));
    auto c = q - p;
    int&& a = 2;
    std::cout << a << std::endl; // 输出 2
    a = 4;
    std::cout << a << std::endl; // 输出 4
    int* b = func();
    std::cout << *b << std::endl; // 输出 10`2
    return 0;
}
