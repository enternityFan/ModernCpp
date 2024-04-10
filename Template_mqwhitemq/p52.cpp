#include <iostream>



template<typename T>
concept Addable = requires(T a, T b) {
    a + b;
};


template <typename T,class U>
concept Swappable = requires(T&& t, U&& u){
    swap(std::forward<T>(t), std::forward<U>(u));
    swap(std::forward<U>(u), std::forward<T>(t));
};


template<typename T>
    requires(Addable<T>&& Swappable<T,T>)
struct Test{};

namespace loser{
    struct X{
        X opereator+(const X&) const{
            return *this;
        }
    };
    void swap(X& a, X& b){}
}

int main(){

    Test<int> t;
    Test<loser::X> l;
    return 0;
}