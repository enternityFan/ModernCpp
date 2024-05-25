#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

/*
应用场景:
在一个论坛中已注册用户和游客的权限不同，
已注册的用户拥有发帖、修改自己的注册信息、修改自己的帖子等功能；
而游客只能看到别人发的帖子，没有其他权限。使用保护代理来设计该权限管理模块。
*/

enum class UserType
{
    Guest,
    Registered
};

class AbstractPermission
{
public:
    virtual void process(UserType){};
    virtual ~AbstractPermission() {}
};

class RealPermission : public AbstractPermission
{
public:
    void process(UserType user_type)
    {
        switch (user_type)
        {
        case UserType::Guest:
            cout << "游客类型为:" << "Guest" << endl;
            break;
        case UserType::Registered:
            cout << "游客类型为：" << "Registered" << endl;
            break;
        default:
            break;
        }
        cout << "可以进行发帖、修改注册信息、修改帖子等操作。。。。" << endl;
    }
};

class ProxyPermission : public AbstractPermission
{
private:
    shared_ptr<AbstractPermission> permission;

public:
    ProxyPermission(shared_ptr<AbstractPermission> _permission)
    {
        permission = _permission;
    }
    void process(UserType user_type)
    {
        if (preprocess(user_type))
        {
            permission->process(user_type);
        }
    }
    bool preprocess(UserType user_type)
    {
        if (user_type == UserType::Guest)
        {
            cout << "游客权限不足，无法进行操作。。。" << endl;
            return false;
        }
        return true;
    }
};

int main()
{
    shared_ptr<AbstractPermission> permission = make_shared<ProxyPermission>(make_shared<RealPermission>());
    permission->process(UserType::Guest);      // 输出：游客权限不足，无法进行操作。。。
    permission->process(UserType::Registered); // 输出：可以进行发帖、修改注册信息、修改帖子等操作。。。。
    return 0;
}