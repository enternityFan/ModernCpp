#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

class Target
{
public:
    virtual void request()
    {
        std::cout << "普通请求!" << std::endl;
    }
};

class Adaptee
{
public:
    void specificRequest()
    {
        std::cout << "特殊请求!" << std::endl;
    }
};

class Adapter : public Target
{
public:
    Adapter() : adaptee_(make_unique<Adaptee>()) {}
    void request() override
    {

        adaptee_->specificRequest();
    }

private:
    unique_ptr<Adaptee> adaptee_;
};

class Client
{
public:
    Client(unique_ptr<Target> target) : target_(move(target)) {}
    void call()
    {
        target_->request();
    }

private:
    unique_ptr<Target> target_;
};

int main()
{
    unique_ptr<Target> target = make_unique<Adapter>();
    Client client(move(target));
    client.call();
    return 0;
}