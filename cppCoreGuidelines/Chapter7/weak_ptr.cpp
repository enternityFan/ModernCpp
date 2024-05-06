#include <iostream>
#include <memory>

struct Son;
struct Daughter;

struct Mother {
    ~Mother() {
        std::cout << "Mother is destroyed" << std::endl;
    }
    void setSon(const std::shared_ptr<Son> son) {
        m_son = son;
    }



    void setDaughter(const std::shared_ptr<Daughter> daughter) {
        m_daughter = daughter;
    }


private:
    std::shared_ptr<Son> m_son; //son和mother循环引用最终不会释放。
    std::weak_ptr<Daughter> m_daughter;
};


struct Son {
    ~Son() {
        std::cout << "Son is destroyed" << std::endl;
    }
    void setMother(const std::shared_ptr<Mother> mother) {
        m_mother = mother;
    }

private:
    std::shared_ptr<Mother> m_mother;
};

struct Daughter {
    ~Daughter() {
        std::cout << "Daughter is destroyed" << std::endl;
    }
    void setMother(const std::shared_ptr<Mother> mother) {
        m_mother = mother;
    }

private:
    std::shared_ptr<Mother> m_mother;
};

int main() {
    std::shared_ptr<Mother> mother = std::make_shared<Mother>();
    std::shared_ptr<Son> son = std::make_shared<Son>();
    std::shared_ptr<Daughter> daughter = std::make_shared<Daughter>();

    mother->setSon(son);
    mother->setDaughter(daughter);

    son->setMother(mother);
    daughter->setMother(mother);

    mother.reset();

    // son and daughter are still alive because they are shared_ptrs
    // mother is destroyed, but son and daughter are still alive


    return 0;

}