#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

class PersonBuilder {
public:
    virtual void buildName() = 0;
    virtual void buildAge() = 0;
    virtual void buildGender() = 0;
};

class PersonTom: public PersonBuilder {
    public:
        void buildName() {
            std::cout << "Name: Tom" << std::endl;
        }
        void buildAge() {
            std::cout << "Age: 25" << std::endl;
        }
        void buildGender() {
            std::cout << "Gender: Male" << std::endl;
        }
};


class PersonJerry: public PersonBuilder {
    public:
        void buildName() {
            std::cout << "Name: Jerry" << std::endl;
        }
        void buildAge() {
            std::cout << "Age: 30" << std::endl;
        }
        void buildGender() {
            std::cout << "Gender: Female" << std::endl;
        }
};



class PersonDirector {
public:
    PersonDirector(shared_ptr<PersonBuilder> builder) : builder_(builder) {}

    void createPerson() {
        builder_->buildName();
        builder_->buildAge();
        builder_->buildGender();
    }

private:
    shared_ptr<PersonBuilder> builder_;
};




int main() {
    shared_ptr<PersonBuilder> builder = make_shared<PersonTom>();
    shared_ptr<PersonDirector> director = make_shared<PersonDirector>(builder);
    director->createPerson();
    std::cout << std::endl;
    builder = make_shared<PersonJerry>();
    director = make_shared<PersonDirector>(builder);
    director->createPerson();

    return 0;
}