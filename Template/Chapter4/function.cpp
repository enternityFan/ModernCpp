#include <iostream>

// 实现类似的function

template <typename T, typename... Args>
class CFObjHandler
{
public:
    virtual T invoke(Args &&...args) const {};
};

template <typename U, typename T, typename... Args>
class CFObjHandlerChild : public CFObjHandler<T, Args...>
{
public:
    // 构造函数

    CFObjHandlerChild(U &&tmpfuncobj) : functor(std::forward<U>(tmpfuncobj))
    {
    }
    virtual T invoke(Args &&...args) const override
    {
        return functor(std::forward<Args>(args)...);
    }

private:
    U functor;
};

// 泛化版本,实际用不到，只是为了可以编译通过
template <typename T>
class CallFuncObj;

// 特化版
template <typename T, typename... Args>
class CallFuncObj<T(Args...)>
{
public:
    template <typename U>
    CallFuncObj(U &&acobj)
    {
        m_nextHandler = new CFObjHandlerChild<U, T, Args...>(std::forward<U>(acobj));
    }
    ~CallFuncObj()
    {
        delete m_nextHandler;
    }
    T operator()(Args &&...args) const
    {
        return m_nextHandler->invoke(std::forward<Args>(args)...);
    }

private:
    CFObjHandler<T, Args...> *m_nextHandler = nullptr;
};

void callObjFunc2(CallFuncObj<void(int)> obj) { obj(120); }

void myfunc(int val)
{
    std::cout << "myfunc val = " << val << std::endl;
}

int main()
{

    callObjFunc2(myfunc);
    callObjFunc2([](int tmpval)
                 { std::cout << "tmpval = " << tmpval << std::endl; });
    CallFuncObj<void(int)> f1 = myfunc;
    f1(1200);
    CallFuncObj<void(int)> f2 = [](int tmpvalue)
    { std::cout << "lambda表达式执行了，tmpvalue = " << tmpvalue << std::endl; };
    f2(1200);
    return 0;
}