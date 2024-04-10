#include <iostream>
#include <type_traits>
#include <concepts>


template<typename T>
concept Integral = std::is_integral_v<T>;

template<typename T>
concept SignedIntegral = Integral<T> && std::is_signed_v<T>;
// 合取，必须两个约束都要瞒住。

template<typename T>
concept SignedIntegral2 = Integral<T> || std::is_signed_v<T>;
// 析取，两个约束满足其一。
void s_f(const SignedIntegral auto& x){

}



int main(){

    s_f(1);
    //s_f(1u);
    return 0;
}