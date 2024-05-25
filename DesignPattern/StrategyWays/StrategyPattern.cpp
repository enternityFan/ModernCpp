#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class CashSuper
{

public:
    virtual double acceptCash(double) = 0;
     CashSuper() = default;
    virtual ~CashSuper() {printf("CashSuper destructor\n");}
};

class CashNormal : public CashSuper
{

public:
    double acceptCash(double price)
    {
        return price;
    }
};

class CashRebate : public CashSuper
{

public:
    double acceptCash(double price)
    {
        // 打8折
        return price * 0.8;
    }
};
class CashReturn : public CashSuper
{

public:
    double acceptCash(double price)
    {
        // 每满300返100
        return price - (price / 300) * 100;
    }
};

class CashContext
{

public:
    CashContext(std::unique_ptr<CashSuper> cs)
    {
        this->cs = std::move(cs);
    }
    void setStrategy(std::unique_ptr<CashSuper> cs){
        this->cs = std::move(cs);
    }

    double GetResult(double price)
    {
        return cs->acceptCash(price);
    }

private:
    std::unique_ptr<CashSuper> cs;
};

int main()
{
    double price = 1000;
    std::unique_ptr<CashContext> c1 = std::make_unique<CashContext>(std::make_unique<CashNormal>());
    cout << c1->GetResult(price) << endl;
    c1->setStrategy(std::make_unique<CashRebate>());
    cout << c1->GetResult(price) << endl;
    c1->setStrategy(std::make_unique<CashReturn>());
    cout << c1->GetResult(price) << endl;
    return 0;
}