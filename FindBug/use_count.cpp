#include <iostream>
#include <memory>

int main() {
    std::shared_ptr<int> p(new int(10));

    long use_count = p.use_count(); // count = 1
    //其他的代码
    //过程中其他的线程也可能对p进行了操作，改变了真实的引用计数
    // 此时 use_count  ?? p.use_count();
    std::cout << "use_count: " << use_count << std::endl; // 线程不安全



    return 0;

}