#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Person
{
public:
    virtual void show() {};
    virtual ~Person() {}
};

class Finery : public Person
{
public:
    Finery(shared_ptr<Person> component) : _component(component) {}
    void show()
    {
        if (_component)
            _component->show();
    }

    shared_ptr<Person> _component;
};

class TShirsA : public Finery
{
public:
    TShirsA(shared_ptr<Person> component) : Finery(component) {}
    void show()
    {
        std::cout << "大T恤" << std::endl;
        Finery::show();
    }
};
class TShirsB : public Finery
{
public:
    TShirsB(shared_ptr<Person> component) : Finery(component) {}
    void show()
    {
        std::cout << "小T恤" << std::endl;
        Finery::show();
    }
};

// 牛仔裤类
class Jeans : public Finery
{

public:
    Jeans(shared_ptr<Person> component) : Finery(component) {}
    void show()
    {
        std::cout << "牛仔裤" << std::endl;
        Finery::show();
    }
};

// 衬衫类
class Shirt : public Finery
{
public:
    Shirt(shared_ptr<Person> component) : Finery(component) {}
    void show()
    {
        std::cout << "衬衫" << std::endl;
        Finery::show();
    }
};

// 裙子类
class Suit : public Finery
{
public:
    Suit(shared_ptr<Person> component) : Finery(component) {}
    void show()
    {
        std::cout << "裙子" << std::endl;
        Finery::show();
    }
};

// 鞋子类
class SportsShoes : public Finery
{
public:
    SportsShoes(shared_ptr<Person> component) : Finery(component) {}
    void show()
    {
        std::cout << "运动鞋" << std::endl;
        Finery::show();
    }
};
class LeatherShoes : public Finery
{

public:
    LeatherShoes(shared_ptr<Person> component) : Finery(component) {}
    void show()
    {
        std::cout << "皮鞋" << std::endl;
        Finery::show();
    }
};

int main()
{
    shared_ptr<Person> person = make_shared<Person>();
    shared_ptr<TShirsA> tshirsa = make_shared<TShirsA>(person);
    shared_ptr<TShirsB> tshirsb = make_shared<TShirsB>(person);
    shared_ptr<Jeans> jeans = make_shared<Jeans>(person);
    shared_ptr<Shirt> shirt = make_shared<Shirt>(person);
    shared_ptr<Suit> suit = make_shared<Suit>(person);
    shared_ptr<SportsShoes> sportsshoes = make_shared<SportsShoes>(person);
    shared_ptr<LeatherShoes> leathershoes = make_shared<LeatherShoes>(person);

    // 一号穿搭
    std::cout << "----------------------一号穿搭------------------------------" << std::endl;
    tshirsa->show();
    jeans->show();
    sportsshoes->show();
    std::cout << "----------------二号穿搭-----------------------" << std::endl;
    shirt->show();
    suit->show();
    leathershoes->show();

    return 0;
}