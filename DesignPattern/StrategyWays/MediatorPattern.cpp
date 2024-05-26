#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <list>
using namespace std;

class Colleague;
class Mediator
{
public:
    virtual void notify(string message, const vector<string> &targets) = 0;
    virtual void registerColleague(Colleague *colleague) = 0;
};

class ConcreteMediator : public Mediator
{
public:
    void notify(string message, const vector<string> &targets)
    {
        for (auto &target : targets)
        {
            cout << "Mediator: " << message << " to " << target << endl;
        }
    }
    void registerColleague(Colleague *colleague)
    {
        _colleagues.push_back(colleague);
    }

private:
    vector<Colleague *> _colleagues;
};

class Colleague
{
public:
    Colleague(Mediator *mediator) : _mediator(mediator)
    {
        _mediator->registerColleague(this);
    }
    virtual void send(string message, const vector<string> &targets) = 0;

protected:
    Mediator *_mediator;
};

class ConcreteColleagueA : public Colleague
{
public:
    ConcreteColleagueA(Mediator *mediator) : Colleague(mediator)
    {
    }
    void send(string message, const vector<string> &targets)
    {
        _mediator->notify(message, targets);
    }
};

class ConcreteColleagueB : public Colleague
{
public:
    ConcreteColleagueB(Mediator *mediator) : Colleague(mediator)
    {
    }
    void send(string message, const vector<string> &targets)
    {
        _mediator->notify(message, targets);
    }
};

class ConcreteColleagueC : public Colleague
{
public:
    ConcreteColleagueC(Mediator *mediator) : Colleague(mediator)
    {
    }
    void send(string message, const vector<string> &targets)
    {
        _mediator->notify(message, targets);
    }
};

int main()
{
    auto mediator = make_shared<ConcreteMediator>();
    auto colleagueA = make_shared<ConcreteColleagueA>(mediator.get());
    auto colleagueB = make_shared<ConcreteColleagueB>(mediator.get());
    auto colleagueC = make_shared<ConcreteColleagueC>(mediator.get());

    colleagueA->send("Hello", {"ColleagueB", "ColleagueC"});
    colleagueB->send("World", {"ColleagueA", "ColleagueC"});
    colleagueC->send("!", {"ColleagueA", "ColleagueB"});

    return 0;
}