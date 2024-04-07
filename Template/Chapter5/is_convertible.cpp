// #include <iostream>
// #include <type_traits>
// using namespace std;

// // is_convertible
// class A
// {
// };
// class B : public A
// {
// };

// template <typename T>
// void testfunc(T);

// template <typename FROM, typename TO, typename = void>
// struct IsConvertibleHelper : std::false_type
// {
// };

// template <typename FROM, typename TO>
// struct IsConvertibleHelper<FROM, TO, decltype(testfunc(std::declval<FROM>()), void())> : std::true_type
// {
// };

// template <typename FROM, typename TO>
// using IsConvertible = IsConvertibleHelper<FROM, TO>;

// int main()
// {
//     cout << std::is_convertible<float, int>::value << endl;
//     cout << std::is_convertible<int, float>::value << endl;
//     cout << std::is_convertible<A, B>::value << endl;
//     cout << std::is_convertible<B, A>::value << endl;
//     cout << IsConvertible<A, B>::value << endl;
//     cout << IsConvertible<B, A>::value << endl;
//     return 0;
// }
