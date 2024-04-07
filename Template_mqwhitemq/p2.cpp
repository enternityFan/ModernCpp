#include <iostream>

template <typename T>
T max(T a, T b)
{
    return a > b ? a : b;
}
struct X{};
int main()
{

    std::cout << max(3, 5) << std::endl;
    std::cout << max(X{},X{}) << std::endl;
    
    
    return 0;

}