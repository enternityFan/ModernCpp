
#include <iostream>
#include <vector>
#include <type_traits>
#include <string>
using namespace std;

template <typename T>
concept Add = requires(T a) {
    a + a;
};

template <Add T>
auto add(const T &a, const T &b)
{

    return a + b;
};


decltype(auto) max(const auto& a, const auto& b)  { // const T&
    return a > b ? a : b;
}

int main()
{

    std::cout << Add<int> << std::endl;
    std::cout << Add<double> << std::endl;
    std::cout << Add<std::string> << std::endl;
    std::cout << Add<std::vector<int>> << std::endl;

    return 0;
}
