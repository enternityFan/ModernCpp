#include <iostream>
#include <deque>
#include <vector>
using namespace std;



int main(){

    deque<int> myDeque;


    myDeque.push_back(1);
    myDeque.push_back(2);
    myDeque.push_back(3);
    myDeque.push_back(4);
    myDeque[3] = 2;
    std::cout << "myDeque: ";
    for(int i = 0; i < myDeque.size(); i++){
        std::cout << myDeque[i] << " ";
    }
    std::cout << std::endl;
    std::vector<int> myVector(3,0);
    std::cout << myVector.size() << std::endl;
    std::cout << myVector.max_size() << std::endl;
    std::vector<int> vec;
    std::cout << vec.at(0) << std::endl;
    return 0;
}