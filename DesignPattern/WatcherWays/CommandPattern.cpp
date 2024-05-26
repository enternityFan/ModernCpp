#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <list>
using namespace std;

class Receiver
{
public:
    void action()
    {
        cout << "执行请求!" << endl;
    }
};
class Command
{
public:
    virtual void execute() = 0;
};
class ConcreteCommand : public Command
{
public:
    ConcreteCommand(Receiver* receiver) : _receiver(receiver) {}
    void execute()
    {
        _receiver->action();
    }

    Receiver* _receiver;
};
class Invoker
{
public:
    void setCommand(Command* command)
    {
        _command = command;
    }
    void action()
    {
        _command->execute();
    }

    Command* _command;
};

class Client
{
public:
    void run()
    {
        Receiver* receiver = new Receiver();
        Command* command = new ConcreteCommand(receiver);
        Invoker* invoker = new Invoker();
        invoker->setCommand(command);
        invoker->action();
    }
};

int main()
{    
    Client client;
    client.run();
    return 0;
}