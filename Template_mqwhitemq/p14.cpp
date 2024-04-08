#include <iostream>
#include <tuple>
template<typename ...Args>
struct X{
    X(Args... args):value(args...){

    }


    std::tuple<Args...> value;

};




int main(){
    std::tuple<int,double> t{1,1.2};
    X x{1,"2",'3',4.};
    std::cout << std::get<1>(x.value) << std::endl;
    std::cout << std::get<0>(x.value) << std::endl;




    return 0;
}