#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <list>
using namespace std;

// 软件
class SoftWare
{
public:
    virtual void show() const = 0;
};

// 浏览器软件
class BrowserSoftWare : public SoftWare
{
public:
    virtual void show() const = 0;
};

class ChromeSoftWare : public BrowserSoftWare
{
public:
    void show() const override { cout << "This is a Chrome browser." << endl; }
};

class FirefoxSoftWare : public BrowserSoftWare
{
public:
    void show() const override { cout << "This is a Firefox browser." << endl; }
};

// 游戏软件
class GameSoftWare : public SoftWare
{
public:
    virtual void show() const = 0;
};
class LOLSoftWare : public GameSoftWare
{
public:
    void show() const override { cout << "This is a League of Legends game." << endl; }
};

class CSOSoftWare : public GameSoftWare
{
public:
    void show() const override { cout << "This is a Counter-Strike: Global Offensive game." << endl; }
};

// 手机品牌
class Brand
{
public:
    Brand(string name) : m_name(name), m_browserSoftWare(nullptr), m_gameSoftWare(nullptr) {}
    string getName() const { return m_name; }
    void show() const
    {
        cout << "This is a " << m_name << " phone." << endl;
        if (m_browserSoftWare)
        {
            m_browserSoftWare->show();
        }
        if (m_gameSoftWare)
        {
            m_gameSoftWare->show();
        }
    }
    void setBrowserSoftWare(shared_ptr<BrowserSoftWare> browserSoftWare) { m_browserSoftWare = browserSoftWare; }
    void setGameSoftWare(shared_ptr<GameSoftWare> gameSoftWare) { m_gameSoftWare = gameSoftWare; }

protected:
    string m_name;
    shared_ptr<BrowserSoftWare> m_browserSoftWare;
    shared_ptr<GameSoftWare> m_gameSoftWare;
};

// 苹果手机
class AppleBrand : public Brand
{
public:
    AppleBrand() : Brand("Apple") {}
};

// 华为手机
class HuaweiBrand : public Brand
{
public:
    HuaweiBrand() : Brand("Huawei") {}
};

int main()
{
    shared_ptr<HuaweiBrand> huaweiBrand = make_shared<HuaweiBrand>();
    huaweiBrand->setBrowserSoftWare(make_shared<ChromeSoftWare>());
    huaweiBrand->setGameSoftWare(make_shared<LOLSoftWare>());
    huaweiBrand->show();
    std::cout << "========================================" << std::endl;
    shared_ptr<AppleBrand> appleBrand = make_shared<AppleBrand>();
    appleBrand->setBrowserSoftWare(make_shared<FirefoxSoftWare>());
    appleBrand->setGameSoftWare(make_shared<CSOSoftWare>());
    appleBrand->show();

    return 0;
}