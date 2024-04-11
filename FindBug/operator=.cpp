#include <iostream>

struct X {
    X() {
        std::cout << "X()" << std::endl;
    }



    X(const X&) {
        std::cout << "X(const X&)" << std::endl;
    }


    X& operator=(const X&) {
        std::cout << "X& operator=(const X&)" << std::endl;
        return *this;
    }
    X& operator=(X&&) {

        std::cout << "X& operator=(X&&)" << std::endl;
        return *this;
    }
    ~X() {
        std::cout << "~X()" << std::endl;
    }
};

template<typename... Args>
void foo(Args&&... args) {
    (std::cout <<... << args) << std::endl;
    std::cout << "foo()" << std::endl;
}


int main() {

    X b;
    X a = b; //这是拷贝构造
    X c;
    c = b; // 这是赋值构造

    return 0;
}