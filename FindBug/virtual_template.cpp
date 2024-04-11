#include <iostream>

// 基类
class Base
{
public:
    // 虚函数模板
    template <typename T>
    // templates may not be ‘virtual’
    virtual void print(T value)
    {
        std::cout << "Base: " << value << std::endl;
    }
};

// 派生类
class Derived : public Base
{
public:
    // 虚函数模板的特化版本
    template <typename T>
    void print(T value) override
    {
        std::cout << "Derived: " << value << std::endl;
    }
};

int main()
{
    Base *ptr = new Derived();
    ptr->print(5);       // 调用 Derived::print<int>(5)
    ptr->print("hello"); // 调用 Derived::print<const char*>("hello")
    delete ptr;
    return 0;
}
