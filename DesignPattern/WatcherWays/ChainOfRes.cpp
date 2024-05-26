#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <list>
using namespace std;

enum class EventType
{
    kGeneral,
    kWarning,
    kError
};

class Handler
{

protected:
    shared_ptr<Handler> nextHandler;

public:
    virtual void HandleRequest(EventType type) = 0;

    void SetNext(shared_ptr<Handler> handler)
    {
        nextHandler = handler;
    }
};

class GeneralHandler : public Handler
{
public:
    void HandleRequest(EventType type)
    {
        if (type == EventType::kGeneral)
        {
            cout << "GeneralHandler: Handling general event" << endl;
        }
        else
        {
            if (nextHandler)
            {
                nextHandler->HandleRequest(type);
            }
        }
    }
};

class WarningHandler : public Handler
{
public:
    void HandleRequest(EventType type)
    {
        if (type == EventType::kWarning)
        {
            cout << "WarningHandler: Handling warning event" << endl;
        }
        else
        {
            if (nextHandler)
            {
                nextHandler->HandleRequest(type);
            }
        }
    }
};

class ErrorHandler : public Handler
{
public:
    void HandleRequest(EventType type)
    {
        if (type == EventType::kError)
        {
            cout << "ErrorHandler: Handling error event" << endl;
        }
        else
        {
            if (nextHandler)
            {
                nextHandler->HandleRequest(type);
            }
        }
    }
};

int main()
{
    shared_ptr<Handler> general = make_shared<GeneralHandler>();
    shared_ptr<Handler> warning = make_shared<WarningHandler>();
    shared_ptr<Handler> error = make_shared<ErrorHandler>();

    general->SetNext(warning);
    warning->SetNext(error);

    general->HandleRequest(EventType::kGeneral);
    general->HandleRequest(EventType::kWarning);
    general->HandleRequest(EventType::kError);

    return 0;
}