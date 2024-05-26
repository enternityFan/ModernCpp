#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;
/*

利用Facade模式，可以将复杂的子系统隐藏在Facade类中，使客户端代码更加简单。

*/

class SubSystemA
{

public:
    void MethodA()
    {

        std::cout << "SubSystemA::MethodA() called" << std::endl;
    }
};

class SubSystemB
{

public:
    void MethodB()
    {

        std::cout << "SubSystemB::MethodB() called" << std::endl;
    }
};

class SubSystemC
{

public:
    void MethodC()
    {

        std::cout << "SubSystemC::MethodC() called" << std::endl;
    }
};

class SubSystemD
{

public:
    void MethodD()
    {

        std::cout << "SubSystemD::MethodD() called" << std::endl;
    }
};

class Facade
{

private:
    std::shared_ptr<SubSystemA> m_subSystemA;
    std::shared_ptr<SubSystemB> m_subSystemB;
    std::shared_ptr<SubSystemC> m_subSystemC;
    std::shared_ptr<SubSystemD> m_subSystemD;

public:
    Facade() : m_subSystemA(std::make_shared<SubSystemA>()),
               m_subSystemB(std::make_shared<SubSystemB>()),
               m_subSystemC(std::make_shared<SubSystemC>()),
               m_subSystemD(std::make_shared<SubSystemD>())
    {
        cout << "Facade created" << endl;
    }

    void MethodA()
    {
        std::cout << "Facade::MethodA() called" << std::endl;
        m_subSystemA->MethodA();
        m_subSystemB->MethodB();
        m_subSystemC->MethodC();
        std::cout << " ======================================" << std::endl;
    }

    void MethodB()
    {
        std::cout << "Facade::MethodB() called" << std::endl;
        m_subSystemB->MethodB();
        m_subSystemD->MethodD();
        std::cout << " ======================================"
                  << std::endl;
    }
};

int main()
{
    auto facade = std::make_shared<Facade>();
    facade->MethodA();
    facade->MethodB();

    return 0;
}