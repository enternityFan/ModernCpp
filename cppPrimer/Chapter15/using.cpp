
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Base{
public:
	std::size_t size() const {return n;}
protected:
	std::size_t n;

};
class Derived: private Base{
public:
	using Base::size; // 本来该是private的，转换为了public，和父类保持了一直。
protected:
	using Base::n;
};

int main(){



    return 0;
}