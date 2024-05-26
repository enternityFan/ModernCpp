#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <list>
#include <map>
using namespace std;

class ConcreteElementA;
class ConcreteElementB;
class Visitor
{
public:
    virtual void VisitConcreteElementA(ConcreteElementA *element) = 0;
    virtual void VisitConcreteElementB(ConcreteElementB *element) = 0;
};

class ConcreteVisitorA : public Visitor
{
public:
    void VisitConcreteElementA(ConcreteElementA *element)
    {
        cout << "ConcreteVisitorA visit ConcreteElementA" << endl;
    }
    void VisitConcreteElementB(ConcreteElementB *element)
    {
        cout << "ConcreteVisitorA visit ConcreteElementB" << endl;
    }
};

class ConcreteVisitorB : public Visitor
{
public:
    void VisitConcreteElementA(ConcreteElementA *element)
    {
        cout << "ConcreteVisitorB visit ConcreteElementA" << endl;
    }
    void VisitConcreteElementB(ConcreteElementB *element)
    {
        cout << "ConcreteVisitorB visit ConcreteElementB" << endl;
    }
};

class Element
{
public:
    virtual void Accept(Visitor *visitor) = 0;
};

class ConcreteElementA : public Element
{
public:
    void Accept(Visitor *visitor)
    {
        visitor->VisitConcreteElementA(this);
    }
};

class ConcreteElementB : public Element
{
public:
    void Accept(Visitor *visitor)
    {
        visitor->VisitConcreteElementB(this);
    }
};

int main()
{
    ConcreteVisitorA visitorA;
    ConcreteVisitorB visitorB;

    ConcreteElementA elementA;
    ConcreteElementB elementB;

    elementA.Accept(&visitorA);
    elementA.Accept(&visitorB);
    std::cout << "=============================" << std::endl;
    elementB.Accept(&visitorB);
    elementB.Accept(&visitorA);

    return 0;
}
