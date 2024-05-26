#include <iostream>
#include <memory>

// 上下文类
class Context;

// 抽象状态基类
class State
{
public:
    virtual void handle(Context &context) = 0;
    virtual ~State() {}
};

// 具体状态类1
class ConcreteState1 : public State
{
public:
    void handle(Context &context) override;
};

// 具体状态类2
class ConcreteState2 : public State
{
public:
    void handle(Context &context) override;
};

// 上下文类
class Context
{
public:
    Context(std::shared_ptr<State> state) : state_(state) {}

    void setState(std::shared_ptr<State> state)
    {
        state_ = state;
    }

    void request()
    {
        if (state_)
        {
            state_->handle(*this);
        }
        else
        {
            std::cout << "未设置状态" << std::endl;
        }
    }

private:
    std::shared_ptr<State> state_;
};

// 具体状态类1的处理方法
void ConcreteState1::handle(Context &context)
{
    std::cout << "处理具体状态1" << std::endl;
    // 在这里根据具体情况切换状态
    context.setState(std::make_shared<ConcreteState2>());
}

// 具体状态类2的处理方法
void ConcreteState2::handle(Context &context)
{
    std::cout << "处理具体状态2" << std::endl;
    // 在这里根据具体情况切换状态
    context.setState(std::make_shared<ConcreteState1>());
}

int main()
{
    // 创建具体状态对象
    std::shared_ptr<ConcreteState1> state1 = std::make_shared<ConcreteState1>();

    // 创建上下文对象并设置初始状态
    Context context(state1);

    // 请求处理
    context.request(); // 输出：处理具体状态1
    context.request(); // 输出：处理具体状态2
    context.request(); // 输出：处理具体状态1
    context.request(); // 输出：处理具体状态2

    return 0;
}
