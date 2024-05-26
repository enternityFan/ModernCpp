#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <list>
#include <map>
using namespace std;

class Context
{
public:
    virtual string getInput() = 0;
};
class Interpreter
{
public:
    virtual void interpret(Context *c) = 0;
};

class BashInterpreter : public Interpreter
{
public:
    void interpret(Context *c)
    {
        string input = c->getInput();
        cout << "Bash: " << input << endl;
    }
};

class PythonInterpreter : public Interpreter
{
public:
    void interpret(Context *c)
    {
        string input = c->getInput();
        cout << "Python: " << input << endl;
    }
};

class BashContext : public Context
{
public:
    string getInput()
    {
        return "ls -l";
    }
};

class PythonContext : public Context
{
public:
    string getInput()
    {
        return "print('Hello, world!')";
    }
};

int main()
{
    vector<unique_ptr<Interpreter>> interpreters;
    interpreters.push_back(unique_ptr<Interpreter>(new BashInterpreter()));
    interpreters.push_back(unique_ptr<Interpreter>(new PythonInterpreter()));

    vector<unique_ptr<Context>> contexts;
    contexts.push_back(unique_ptr<Context>(new BashContext()));
    contexts.push_back(unique_ptr<Context>(new PythonContext()));

    for (auto &interpreter : interpreters)
    {
        for (auto &context : contexts)
        {
            interpreter->interpret(context.get());
        }
    }

    return 0;
}