#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <list>
using namespace std;

class Component
{
public:
    Component(string name) : name(name) {}
    virtual void add(shared_ptr<Component> c) = 0;
    virtual void remove(shared_ptr<Component> c) = 0;
    virtual void display(int depth) = 0;
    virtual string getName() { return name; }
    virtual ~Component() {}

protected:
    string name;
};

class Leaf : public Component
{
public:
    Leaf(string name) : Component(name) {}
    void add(shared_ptr<Component> c) override
    {
    }
    void remove(shared_ptr<Component> c) override
    {
    }
    void display(int depth) override
    {
        cout << string(depth * 2, '-') << name << endl;
    }
};

class Composite : public Component
{
public:
    Composite(string name) : Component(name) {}
    void add(shared_ptr<Component> c) override
    {
        children.push_back(c);
    }
    void remove(shared_ptr<Component> c) override
    {
        // std::cout << "Removing " << c->getName() << " from " << name << std::endl;
        children.remove_if([c](shared_ptr<Component> p)
                           { return p->getName() == c->getName(); });
        for (auto child : children)
        {
            child->remove(c);
        }
    }
    void display(int depth) override
    {
        cout << string(depth, '-') << name << endl;
        for (auto c : children)
        {
            c->display(depth + 1);
        }
    }

private:
    list<shared_ptr<Component>> children;
};

int main()
{

    shared_ptr<Component> root = make_shared<Composite>("root");
    shared_ptr<Component> composite1 = make_shared<Composite>("composite1");
    shared_ptr<Component> composite2 = make_shared<Composite>("composite2");
    shared_ptr<Component> leaf1 = make_shared<Leaf>("leaf1");
    shared_ptr<Component> leaf2 = make_shared<Leaf>("leaf2");
    shared_ptr<Component> leaf3 = make_shared<Leaf>("leaf3");

    root->add(composite1);
    root->add(composite2);
    composite1->add(leaf1);
    composite1->add(leaf2);
    composite2->add(leaf3);

    root->display(0);

    root->remove(leaf2);

    root->display(0);

    return 0;
}