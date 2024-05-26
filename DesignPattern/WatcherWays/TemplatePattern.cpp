#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

/*
模板策略，模板方法模式，定义一个操作中的算法的骨架，
而将一些步骤延迟到子类中。模板方法使得子类可以不改变一个算法的结构即可重定义该算法的某些特定步骤。

*/

class AbstractClass {
    public:
        virtual void templateMethod(){
            primitiveOperation1();
            primitiveOperation2();
            std::cout << "finished template method" << std::endl;
        };
        virtual void primitiveOperation1() = 0;
        virtual void primitiveOperation2() = 0;
        virtual ~AbstractClass() {}
};



class ConcreteClassA : public AbstractClass {
    public:
        void primitiveOperation1(){
            std::cout << "第一题我选A" << std::endl;
        }
        void primitiveOperation2(){
            std::cout << "第二题我选B" << std::endl;
        }
};

class ConcreteClassB : public AbstractClass {
    public:
        void primitiveOperation1(){
            std::cout << "第一题我选C" << std::endl;
        }
        void primitiveOperation2(){
            std::cout << "第二题我选D" << std::endl;
        }
};

int main() {
    auto* objA = new ConcreteClassA();
    auto* objB = new ConcreteClassB();
    objA->templateMethod();
    objB->templateMethod();
    delete objA;
    delete objB;
    return 0;
}