#include <iostream>


//虽然加上了->decltype(a+b)仍然不能编译，
//但是通过SFINAE可以避免实例化，减少开销。
//SFINAE
template<typename T>
auto add(const T& a, const T& b)->decltype(a+b) {
    std::puts("SFINAE + ");
    return a + b;
}

struct X{};

int main() {
    add(1,2);
    add(X{}, X{});



    return 0;
}