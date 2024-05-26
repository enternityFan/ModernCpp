#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <set>
using namespace std;

class Subject;
class Observer
{
public:
    Observer(string name) : name_(name)
    {
    }

    virtual ~Observer() {}
    virtual void update(Subject *subject) = 0;
    virtual string getName() { return ""; };

protected:
    string name_;
};

class Subject
{
public:
    virtual void attach(shared_ptr<Observer> observer) = 0;
    virtual void detach(shared_ptr<Observer> observer) = 0;
    virtual void notify() = 0;
    virtual string getState() = 0;
    virtual void setState(string state) = 0;
    virtual ~Subject() {}

protected:
    set<shared_ptr<Observer>> observers;
    string state_{""};
};

class ConcreteSubject : public Subject
{
public:
    void attach(shared_ptr<Observer> observer) override
    {
        observers.insert(observer);
    }
    void detach(shared_ptr<Observer> observer) override
    {
        if (observers.count(observer))
            observers.erase(observer);
    }
    void notify() override
    {
        for (auto &observer : observers)
        {
            observer->update(this);
        }
    }
    void setState(string state) override
    {
        state_ = state;
        notify();
    }
    string getState() override
    {
        return state_;
    }
};

class ConcreteObserver : public Observer
{
public:
    ConcreteObserver(string name) : Observer(name)
    {
    }
    void update(Subject *subject) override
    {
        cout << "subject state changed, observer " << getName() << " is notified." << endl;
        cout << "subject state: " << subject->getState() << endl;
    }
    string getName() override{
        return name_;
    }
};

int main()
{
    // create subject and observer
    auto subject = make_shared<ConcreteSubject>();
    auto observer1 = make_shared<ConcreteObserver>("observer1");
    auto observer2 = make_shared<ConcreteObserver>("observer2");

    // attach observer to subject
    subject->attach(observer1);
    subject->attach(observer2);
    std::puts("===============================");
    // change subject state
    subject->setState("new state");
    std::puts("===============================");
    subject->detach(observer2);
    subject->setState("new state 2");

    return 0;
}