#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <list>
using namespace std;

class Iterator
{
public:
    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool isDone() = 0;
    virtual string currentItem() = 0;
};

class ConcreteIterator : public Iterator
{
public:
    ConcreteIterator(vector<string> &vec) : _vec(vec), _index(0)
    {
        first();
    }
    void first()
    {
        _index = 0;
    }
    void next()
    {
        _index++;
    }
    bool isDone()
    {
        return _index >= _vec.size();
    }
    string currentItem()
    {
        return _vec[_index];
    }

private:
    vector<string> &_vec;
    int _index;
};

class Aggregate
{
public:
    virtual shared_ptr<Iterator> createIterator() = 0;
};

class ConcreteAggregate : public Aggregate
{
public:
    ConcreteAggregate(vector<string> &vec) : _vec(vec)
    {
    }
    shared_ptr<Iterator> createIterator()
    {
        return shared_ptr<Iterator>(new ConcreteIterator(_vec));
    }

private:
    vector<string> &_vec;
};

void print(Iterator *it)
{
    while (!it->isDone())
    {
        cout << it->currentItem() << " ";
        it->next();
    }
    cout << endl;
}

int main()
{
    vector<string> vec{"apple", "banana", "orange"};
    Aggregate *agg = new ConcreteAggregate(vec);
    shared_ptr<Iterator> it = agg->createIterator();
    print(it.get());

    return 0;
}