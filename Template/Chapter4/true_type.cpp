#include <iostream>
using namespace std;

using true_type = integral_constant<bool, true>;
using false_type = integral_constant<bool, false>;


template <bool val>
struct BoolConstant
{
    using type = BoolConstant; // 写成using type = BoolConstant<val>;也可以 static constexpr bool value = val;
};
using TrueType = BoolConstant<true>;
using FalseType = BoolConstant<false>;

int main()
{
    return 0;
}