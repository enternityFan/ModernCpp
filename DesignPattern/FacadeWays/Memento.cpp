#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

// 备忘录模式
class Memento
{
public:
    Memento() : state("") {}
    Memento(string state)
    {
        this->state = state;
    }
    string getState()
    {
        return state;
    }

private:
    string state;
};

class Caretaker
{
public:
    void setMemento(shared_ptr<Memento> memento)
    {
        this->memento = memento;
    }
    shared_ptr<Memento> getMemento()
    {
        return memento;
    }
    string getState()
    {
        return memento->getState();
    }

private:
    shared_ptr<Memento> memento;
};
class Originator
{
public:
    Originator()
    {
        this->state = "State 0";
    }
    shared_ptr<Memento> createMemento()
    {
        return std::make_shared<Memento>(state);
    }
    string getState()
    {
        return state;
    }
    void setState(string state)
    {
        this->state = state;
    }
    void setMemento(shared_ptr<Memento> memento)
    {

        this->state = memento->getState();
    }
    void print()
    {
        cout << "Current state: " << state << endl;
    }

private:
    string state;
    Memento memento;
};

class Client
{
public:
    void run()
    {
        Originator originator;
        originator.setState("State 1");
        originator.print();

        shared_ptr<Memento> memento = originator.createMemento();
        Caretaker caretaker;
        caretaker.setMemento(memento);

        originator.setState("State 2");
        originator.print();

        originator.setMemento(caretaker.getMemento());
        originator.print();
    }
};

int main()
{
    Client client;
    client.run();
    return 0;
}