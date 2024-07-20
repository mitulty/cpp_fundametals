/*
  @Author: Mitul Tyagi
  @Date:   2024-02-05 20:56:49
  @Description: Funtion Templates
  @Last Modified time: 2024-02-07 12:21:38
*/
/*
- Function templates are a mechanism to avoid code repetition in C++. They are just blueprints and not real C++ code. The compiler generates real C++ code
  consumed by the compiler. The compiler generates real C++ code by looking at the arguments of the function.
- The real C++ function generated by the compiler is called template instance.
- A template instance will be reused when a similar function call is issued. No duplicates are generated by the compiler.
- Template specializations are real C++ code. If multiple function template specialization definitions show up in multiple files, this will result in
  redefinition errors.
- Decltype is mechanism in C++ to deduce the type of an expression.
- The auto function template syntax expands to a function template using decltype(auto) without a trailing return type to deduce the return type.
- https://stackoverflow.com/questions/7108033/should-you-prefer-overloading-over-specialization-of-function-templates/7108123#7108123
- This will also not work:
                                    template <typename T> const T& maximum(const T& a, const T& b); // Declaration
                                    template <typename T> T maximum(T a, T b); // Declaration

                                    int main(){

                                        double a {23.5};
                                        double b {51.2};

                                        std::cout << "Out - &a: " << &a << std::endl; // 0x111abc
                                        auto result = maximum<const int&>(a,b);
                                        std::cout << "Out - &a: " << &a << std::endl; // 0x111abc

                                        return 0;
                                    }


                                    //Definition
                                    template <typename T> const T& maximum(const T& a, const T& b){
                                        std::cout << "In - &a: " << &a << std::endl; // // 0x111abc
                                        return (a > b ) ? a : b ;
                                    }


                                    template <typename T> T maximum(T a, T b){
                                        std::cout << "In - &a: " << &a << std::endl; // // 0x111abc
                                        return (a > b ) ? a : b ;
                                    }
                                    main.cpp: In function ‘int main()’:
                                    main.cpp:24:38: error: call of overloaded ‘maximum(double&, double&)’ is ambiguous
                                       24 |     auto result = maximum<const int&>(a,b);
                                          |                   ~~~~~~~~~~~~~~~~~~~^~~~~
                                    main.cpp:15:32: note: candidate: ‘const T& maximum(const T&, const T&) [with T = const int&]’
                                       15 | template <typename T> const T& maximum(const T& a, const T& b); // Declaration
                                          |                                ^~~~~~~
                                    main.cpp:16:25: note: candidate: ‘T maximum(T, T) [with T = const int&]’
                                       16 | template <typename T> T maximum(T a, T b); // Declaration
                                          |                         ^~~~~~~
*/
#include <iostream>
#include <string>
#include <cstring>
#include <type_traits>
using namespace std;

// Declaration
template <typename T>
T maximum(T a, T b);

template <typename T>
const T &maximum_ref(const T &a, const T &b);

template <>
const char *maximum<const char *>(const char *a, const char *b)
{
    return (std::strcmp(a, b) > 0) ? a : b;
}

// Function template
template <typename T>
T max(T a, T b)
{
    std::cout << "Template overload called(T) " << std::endl;
    return (a > b) ? a : b;
}

// A raw overload will take precedence over any template instance if const char* is passed to maximum
const char *max(const char *a, const char *b)
{
    std::cout << "Raw overload called" << std::endl;
    return (std::strcmp(a, b) > 0) ? a : b;
}

// Overload through templates. Will take precedence over raw T if a pointer is passed to maximum
template <typename T>
T *max(T *a, T *b)
{
    std::cout << "Template overload called (T*) " << std::endl;
    return (*a > *b) ? a : b;
}

/*
//Problematic : return depends on the order of the template arguments : BAD!
template <typename T , typename P>
P   larger( T a, P b){
    return ((a > b) ? a : b);
}
*/

template <typename ReturnType, typename T, typename P>
// template < typename T,typename ReturnType , typename P>
// template < typename T, typename P,typename ReturnType >
ReturnType larger(T a, P b)
{
    return ((a > b) ? a : b);
}

template <typename T, typename P>
auto minimum(T a, P b)
{
    return (a < b) ? a : b;
}
// Declaration
template <typename T, typename P>
auto higher(T a, P b) -> decltype((a > b) ? a : b);

// Can't split function code.
template <typename T, typename P>
decltype(auto) maximum_of_two(T a, P b)
{
    return (a > b) ? a : b;
}

template <typename T, typename P, typename ReturnType = double>
ReturnType min(T a, P b)
{
    return (a < b) ? a : b;
}

template <int threshold, typename T>
bool is_valid_v1(T collection[], size_t size)
{
    T sum{}; // 0
    for (size_t i{0}; i < size; ++i)
    {
        sum += collection[i];
    }
    return (sum > threshold) ? true : false;
}

// Version making a little more sense for the task
template <typename T>
bool is_valid_v2(T collection[], int threshold, size_t size)
{
    T sum{};
    for (size_t i{0}; i < size; ++i)
    {
        sum += collection[i];
    }
    return (sum > threshold) ? true : false;
}

// Below function and the template are equivalent
template <typename T, typename P>
decltype(auto) func_add_v1(T a, P b)
{
    return a + b;
}

auto func_add_v2(auto a, auto b)
{
    return a + b;
}

template <typename T>
void print_number(T n)
{
    static_assert(std::is_integral_v<T>, "print_number() can only be called with integral types");
    std::cout << "number : " << n << std::endl;
}

void func_floating_point(double d)
{
    std::cout << "func_floating_point called..." << std::endl;
}
void func_integral(int i)
{
    std::cout << "func_integral called..." << std::endl;
}

template <typename T>
void func(T t)
{
    if constexpr (std::is_integral_v<T>)
        func_integral(t);
    else if constexpr (std::is_floating_point_v<T>)
        func_floating_point(t);
    else
        static_assert(std::is_integral_v<T> || std::is_floating_point_v<T>,
                      "Argument must be integral or floating point");
}
int main(int argc, char const *argv[])
{
    { // Trying Out Function Templates

        std::cout << "----------------------Trying Out Function Templates------------------------\n";
        int x{5};
        int y{7};

        int *p_x{&x};
        int *p_y{&y};

        std::string e{"Hello"};
        std::string f{"World"};

        // For pointers this is not a correct function.
        auto result_pointer = maximum(p_x, p_y);
        std::cout << "result int pointer: " << *result_pointer << std::endl;
        auto result_int = maximum(x, y);
        std::cout << "result int: " << result_int << std::endl;
        auto result_string = maximum(e, f);
        std::cout << "result string: " << result_string << std::endl;
    }
    { // Template Type Deduction And Explicit Arguments

        std::cout << "----------------------Template Type Deduction and Explicit Arguments------------------------\n";
        int a{10};
        int b{23};
        double c{34.7};
        double d{23.4};
        std::string e{"hello"};
        std::string f{"world"};

        // Explicit template arguments

        auto max = maximum<double>(c, d);   // explicitly called double
        auto max_2 = maximum<double>(a, c); // explicitly called double. This will  work
        auto result = maximum<long int>(a, d);
        // auto max = maximum<double>(a, e); // explicitly called double. This will not work
        std::cout << "max : " << max << std::endl;
    }
    { // Template type parameters by reference

        std::cout << "----------------------Template Type Parameters by Reference------------------------\n";
        double a{23.5};
        double b{51.2};

        std::cout << "Out - &a: " << &a << std::endl; // 0x111abc
        auto result = maximum_ref(a, b);
        std::cout << "Out - &a: " << &a << std::endl; // 0x111abc
    }
    { // Function Template Specialization
        std::cout << "----------------------Function Template Specialization------------------------\n";
        const char *g{"wild"};
        const char *h{"animal"};

        const char *result = maximum(g, h);
        std::cout << "max(const char*) : " << result << std::endl;
    }
    { // Function Templates with Overloading

        std::cout << "----------------------Function Template with Overloading------------------------\n";
        const char *g{"wild"};
        const char *h{"animal"};

        const char *result = max(g, h);

        int a{810};
        int b{23};

        auto result_2 = max(&a, &b);
        std::cout << "result_2 : " << *result_2 << std::endl;
    }
    { // Function Templates with Multiple Parameters

        std::cout << "----------------------Function Templates with Multiple Parameters------------------------\n";
        int a{5};
        double b{6.7};
        auto max1 = larger<int, char, long>('c', 12L);
        std::cout << "max1 : " << max1 << " of size: " << sizeof(max1) << std::endl;

        auto max2 = larger<int, char>('d', 12L);
        std::cout << "max2 : " << max2 << " of size: " << sizeof(max2) << std::endl;

        auto max3 = larger<int>('e', 14L);
        std::cout << "max3 : " << max3 << " of size: " << sizeof(max3) << std::endl;

        // auto max4 = larger('e', 14L);// This will not work

        auto result = larger<int>(a, b);
        std::cout << "result: " << result << " of size : " << sizeof(result) << std::endl;
    }
    { // Function Template return type deduction with auto. Before calling the function, compiler should know the definition of the function.

        std::cout << "----------------------Function Templates Return Type Deduction------------------------\n";
        // The largest type involved is going to be deduced as return type
        auto max1 = minimum('e', 33); // int return type deduced
        std::cout << "max1 : " << max1 << std::endl;
        std::cout << "size of max1 : " << sizeof(max1) << std::endl;

        auto max2 = minimum(234.56, 33); // double return type deduced
        std::cout << "max2 : " << max2 << std::endl;
        std::cout << "size of max2 : " << sizeof(max2) << std::endl;

        // Explicit Template Arguments
        auto max3 = minimum<char, char>('c', 90); // char return type deduced
        std::cout << "max3 : " << max3 << std::endl;
        std::cout << "size of max3 : " << sizeof(max3) << std::endl;

        auto max4 = minimum<double, int>('c', 90); // double return type deduced
        std::cout << "max4 : " << max4 << std::endl;
        std::cout << "size of max4 : " << sizeof(max4) << std::endl;
    }
    { // Decltype and Trailing Return Types

        std::cout << "----------------------Decltype and Trailing Return Types------------------------\n";
        int a{9};
        double b{15.8};
        char ch{90};

        std::cout << "size(int,double) : " << sizeof(decltype((a > b) ? a : b)) << std::endl;
        std::cout << "size(int,double) : " << sizeof(decltype((a > b) ? a : ch)) << std::endl;
        std::cout << "size(int,char) : " << sizeof(decltype((a > ch) ? a : b)) << std::endl;
        std::cout << "size(int,char) : " << sizeof(decltype((a > ch) ? a : ch)) << std::endl;

        decltype((a < b) ? a : b) c{7}; // Declaring other variables through declytype
        std::cout << "c : " << c << std::endl;
        std::cout << "sizeof(c) : " << sizeof(c) << std::endl; // 4

        auto result = higher(a, b);
        std::cout << "result : " << result << std::endl;
        std::cout << "sizeof(result) :" << sizeof(result) << std::endl;
    }
    { // Decltype Auto

        std::cout << "----------------------Decltype Auto------------------------\n";
        int x{7};
        double y{45.9};

        auto result = maximum_of_two(x, y);
        std::cout << "max : " << result << std::endl;
        std::cout << "sizeof(result) : " << sizeof(result) << std::endl;
    }
    { // Default Arguments

        std::cout << "----------------------Default Arguments------------------------\n";
        double a{6};
        double b{9.5};

        auto result = min<int, double, int>(a, b);
        std::cout << "result : " << result << std::endl;
        std::cout << "sizeof(result) : " << sizeof(result) << std::endl; // int

        auto min1 = min(a, b);
        std::cout << "min1 : " << min1 << std::endl;
        std::cout << "sizeof(min1) : " << sizeof(min1) << std::endl; // double
    }
    { // Non Type Template Parameters

        std::cout << "----------------------Non Type Template Parameters------------------------\n";
        double temperatures[]{10.0, 20.0, 30.0, 40.0, 50.0, 100.0};

        auto result_v1 = is_valid_v1<200, double>(temperatures, std::size(temperatures));
        std::cout << std::boolalpha;
        std::cout << "result : " << result_v1 << std::endl;

        auto result_v2 = is_valid_v2<double>(temperatures, 200, std::size(temperatures));
        std::cout << std::boolalpha;
        std::cout << "result : " << result_v2 << std::endl;
    }
    { // Auto Function Templates

        std::cout << "----------------------Auto Function Template------------------------\n";
        int a{7};
        double b{78.2};

        auto result = func_add_v1(a, b);
        std::cout << "result : " << result << std::endl;
        std::cout << "sizeof(result) : " << sizeof(result) << std::endl;

        auto result_v2 = func_add_v2(a, b);
        std::cout << "result : " << result_v2 << std::endl;
        std::cout << "sizeof(result_v2) : " << sizeof(result_v2) << std::endl;
    }
    { // Named Template Parameters for Lambdas

        std::cout << "----------------------Named Template Parameters for Lambdas------------------------\n";
        auto func_v0 = []<typename T>(T a, T b)
        {
            return a + b;
        };
        auto func_v1 = []<typename T, typename P>(T a, P b)
        {
            return a + b;
        };
        auto func_v2 = [](auto a, auto b)
        {
            return a + b;
        };

        char a{'c'};
        int b{63};

        auto result_v0 = func_v0(45, b);
        std::cout << "result : " << result_v0 << std::endl;
        std::cout << "sizeof(result) : " << sizeof(result_v0) << std::endl;

        auto result_v1 = func_v1(a, b);
        std::cout << "result : " << result_v1 << std::endl;
        std::cout << "sizeof(result) : " << sizeof(result_v1) << std::endl;

        auto result_v2 = func_v2(a, b);
        std::cout << "result : " << result_v2 << std::endl;
        std::cout << "sizeof(result_2) : " << sizeof(result_v2) << std::endl;
    }
    { // Type Traits

        std::cout << "----------------------Type Traits------------------------\n";
        std::cout << std::boolalpha;
        std::cout << "std::is_integral<int> : " << std::is_integral<int>::value << std::endl;
        std::cout << "std::is_integral<double> : " << std::is_integral<double>::value << std::endl;
        std::cout << "std::is_floating_point<int> : " << std::is_floating_point<int>::value << std::endl;
        // std::cout << "std::is_integral<a> : " << std::is_integral<a>::value << std::endl;

        std::cout << "-------------" << std::endl;

        std::cout << "std::is_integral_v<int> : " << std::is_integral_v<int> << std::endl;
        std::cout << "std::is_floating_point_v<int> : " << std::is_floating_point_v<int> << std::endl;

        /*
        double a{7};
        print_number(a);
        */
        int a{7};
        print_number(a);

        auto func = []<typename T>(T a, T b)
        {
            static_assert(std::is_integral_v<T>, "func can only be called with integral types");
            return a + b;
        };

        /*
        double x{7};
        double y{6};
        func(x, y);
        */
        int x{7};
        int y{6};
        func(x, y);
    }
    { // constexpr if

        std::cout << "----------------------constexpr if------------------------\n";
        func(12);
    }
    return 0;
}

// Definition
template <typename T>
T maximum(T a, T b)
{
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    return (a > b) ? a : b;
}

template <typename T>
const T &maximum_ref(const T &a, const T &b)
{
    std::cout << "In - &a: " << &a << std::endl;
    return (a > b) ? a : b;
}

template <typename T, typename P>
auto higher(T a, P b) -> decltype((a > b) ? a : b)
{
    return (a > b) ? a : b;
}