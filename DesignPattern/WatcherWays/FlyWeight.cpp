#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <list>
#include <map>
using namespace std;

class FlyWeight
{
public:
    virtual void operation() = 0;
    virtual ~FlyWeight() {}
};

class ConcreteFlyWeight : public FlyWeight
{
public:
    ConcreteFlyWeight(string name) : name_(name) {}
    void operation()
    {
        cout << "ConcreteFlyWeight " << name_ << " operation" << endl;
    }

private:
    string name_;
};

class UnsharedConcreteFlyWeight : public FlyWeight
{
public:
    UnsharedConcreteFlyWeight(string name) : name_(name) {}
    void operation()
    {
        cout << "UnsharedConcreteFlyWeight " << name_ << " operation" << endl;
    }

    ~UnsharedConcreteFlyWeight()
    {
        cout << "UnsharedConcreteFlyWeight " << name_ << " destructor" << endl;
    }

private:
    string name_;
};

class FlyWeightFactory
{
public:
    FlyWeightFactory() {}
    shared_ptr<FlyWeight> getFlyWeight(string name)
    {
        auto it = flyWeights_.find(name);
        if (it == flyWeights_.end())
        {
            if (name == "shared")
            {
                shared_ptr<FlyWeight> flyWeight = make_shared<ConcreteFlyWeight>(name);
                flyWeights_[name] = flyWeight;
                return flyWeight;
            }
            else
            {
                shared_ptr<FlyWeight> flyWeight = make_unique<UnsharedConcreteFlyWeight>(name);
                flyWeights_[name] = flyWeight;
                return flyWeight;
            }
        }
        else
        {
            return it->second;
        }
    }

private:
    map<string, shared_ptr<FlyWeight>> flyWeights_;
};

class Client
{
public:
    Client(FlyWeightFactory *factory) : factory_(factory) {}
    void operation()
    {
        for (int i = 0; i < 10; i++)
        {
            auto flyWeight = factory_->getFlyWeight("shared");
            flyWeight->operation();
        }
    }

private:
    FlyWeightFactory *factory_;
};

int main()
{
    FlyWeightFactory factory;
    Client client(&factory);
    client.operation();
    return 0;
}