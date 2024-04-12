#include <iostream>

template <typename T>
struct my_array
{
    T arr[10];
};

template <typename Ty, template <typename T> typename C = my_array>
struct Array
{
    C<Ty> array;
};

int main()
{
    Array<int> arr;

    return 0;
}