#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <list>
using namespace std;

// 单例模式
class Singleton
{
private:
    static shared_ptr<Singleton> instance;
    Singleton() {}

public:
    static shared_ptr<Singleton> getInstance()
    {
        if (!instance)
        {
            instance = shared_ptr<Singleton>(new Singleton());
        }
        return instance;
    }
};
shared_ptr<Singleton> Singleton::instance = nullptr;

int main()
{
    shared_ptr<Singleton> s1 = Singleton::getInstance();
    shared_ptr<Singleton> s2 = Singleton::getInstance();
    if (s1 == s2)
    {
        cout << "s1 and s2 are the same instance" << endl;
    }
}