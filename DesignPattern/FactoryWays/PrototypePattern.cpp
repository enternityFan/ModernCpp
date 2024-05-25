#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

/*
应用场景，简历修改仅修改几个字段,深拷贝实现。


*/
class ICloneable
{
public:
    virtual shared_ptr<ICloneable> clone() const { return nullptr; };
    virtual void setInfo(string name, int age) {};
    virtual void setWorkExperience(int time, string company) {};
    virtual void display() const {};
};

class Resume : public ICloneable
{
    string name_;
    int age_;
    vector<string> workExperiences_;

public:
    Resume(string name, int age) : name_(name), age_(age) {}
    shared_ptr<ICloneable> clone() const override
    {
        auto resume = make_shared<Resume>(name_, age_);
        resume->workExperiences_ = workExperiences_;
        return resume;
    }
    void setInfo(string name, int age) override
    {
        name_ = name;
        age_ = age;
    }
    void setWorkExperience(int time, string company) override
    {
        workExperiences_.push_back(company + " " + to_string(time));
    }
    void display() const override
    {
        std::cout << "Name: " << name_ << "\tAge: " << age_ << "\tworkExperiences: ";
        for (auto exp : workExperiences_)
        {
            cout << exp << "\t";
        }
        std::cout << std::endl;
    }
};

int main()
{
    std::shared_ptr<ICloneable> resume = make_shared<Resume>("John Doe", 30);
    resume->setWorkExperience(10, "Google");
    resume->display();
    auto clonedResume = resume->clone();
    clonedResume->setInfo("Jane Doeeeeee", 35);
    clonedResume->setWorkExperience(5, "Facebook");
    clonedResume->display();
    resume->display();
    return 0;
}