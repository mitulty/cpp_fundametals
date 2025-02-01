/*
  @Author: Mitul Tyagi
  @Date:   2024-01-29 22:32:35
  @Description: Function Overloading
*/
/*
- Function overloading is a mechanism to setup multiple functions of the same name but different parameter list.
- Function overloading is done with signature of the function and the return type of the function is not a part of the signature of the function.
- For function overloadiing, changing the order of the parameters, the number of the parameters and the type of the parameters will result in
  overloaded functions.
- Pointers to different types are treated as different types and hence can be overloaded.
- Followig are equivalent declarations:
                   int max(int * numbers, size_t count);
                   int max(int numbers[], size_t count);
                   int max(int numbers[10], size_t count);
*/
#include <iostream>
#include <string>
using namespace std;

// Overloading with Different Parameters
int max(int a, int b)
{
    std::cout << "int overload called" << std::endl;
    return (a > b) ? a : b;
}
// Changing the return type will not overload the functions
/*
double max(int a, int b)
{
    std::cout << "int overload called" << std::endl;
    return (a > b) ? a : b;
}*/
// Adding a const will not overload the function. A workaround is to add the const in definitions only.
/*
int max(const int a, const int b)
{
    std::cout << "(int,double) overload called" << std::endl;
    return (a > b) ? a : b;
}
*/

double max(double a, double b)
{
    std::cout << "double overload called" << std::endl;
    return (a > b) ? a : b;
}

double max(int a, double b)
{
    std::cout << "(int,double) overload called" << std::endl;
    return (a > b) ? a : b;
}

double max(double a, int b)
{
    std::cout << "(double,int) overload called" << std::endl;
    return (a > b) ? a : b;
}

double max(double a, int b, int c)
{
    std::cout << "(double,int,int) overload called" << std::endl;
    return a;
}

std::string_view max(std::string_view a, std::string_view b)
{
    std::cout << "(string_view,string_view) overload called" << std::endl;
    return (a > b) ? a : b;
}

// Overloading with Pointer Parameters
double max(double *numbers, size_t count)
{
    std::cout << "doubles overload called" << std::endl;
    double maximum{0};

    for (size_t i{0}; i < count; ++i)
    {
        if (numbers[i] > maximum)
            maximum = numbers[i];
    }
    return maximum;
}

int max(int *numbers, size_t count)
{
    std::cout << "ints overload called" << std::endl;

    int maximum{0};

    for (size_t i{0}; i < count; ++i)
    {
        if (numbers[i] > maximum)
            maximum = numbers[i];
    }
    return maximum;
}
// These are same as above
/*
int max(int numbers[], size_t count)
{
    std::cout << "ints overload called" << std::endl;

    int maximum{0};

    for (size_t i{0}; i < count; ++i)
    {
        if (numbers[i] > maximum)
            maximum = numbers[i];
    }
    return maximum;
}
int max(int numbers[10], size_t count)
{
    std::cout << "ints overload called" << std::endl;

    int maximum{0};

    for (size_t i{0}; i < count; ++i)
    {
        if (numbers[i] > maximum)
            maximum = numbers[i];
    }
    return maximum;
}
*/

// Overloading with Reference Parameters
// Ambiguous calls
void say_my_name(const std::string &name)
{
    std::cout << "Your name is (ref) : " << name << std::endl;
}

void say_my_name(std::string name)
{
    std::cout << "Your name is (non ref) : " << name << std::endl;
}

// Implicit conversions with references
double max_imcref(double a, double b)
{
    std::cout << "double max called" << std::endl;
    return (a > b) ? a : b;
}

// int& max(int& a, int& b){ // Because of temporaries
const int &max_imcref(const int &a, const int &b)
{
    std::cout << "int max called" << std::endl;
    return (a > b) ? a : b;
}

// Overloading with const paramaters by value
void say_my_age(int age);

// Overloading with Const Pointer and Pointer to Const Paramters
int max_cp(int *a, int *b)
{
    std::cout << "max with int* called" << std::endl;
    return (*a > *b) ? *a : *b;
}

int max_cp(const int *a, const int *b)
{
    std::cout << "max with cont int* called" << std::endl;
    return (*a > *b) ? *a : *b;
}

/*
Same as below. The pointer is passed by value.
int min(const int* a, const int* b){
    return (*a < *b)? *a : *b;
}
*/

int min(const int *const a, const int *const b)
{
    std::cout << "&a : " << &a << std::endl;
    std::cout << "&b : " << &b << std::endl;
    return (*a < *b) ? *a : *b;
}

// Overloading with const references
int max_ref(int &a, int &b) // Parameters by non-const references
{
    std::cout << "max with int& called" << std::endl;

    // Can change a and b through the reference
    // a = 200;// This change will be visible outside the function

    return (a > b) ? a : b;
}

int max_ref(const int &a, const int &b) // Parameters by const references
{
    std::cout << "max with const int& called" << std::endl;

    // Can NOT change a and b through the reference
    // a = 200; // Will give a compiler error.
    return (a > b) ? a : b;
}
// Declarations
void print_age(int age = 33);
void print_age(long int age = 44);

int main(int argc, char const *argv[])
{
    { // Overloading with Different Parameters
        int x{4};
        int y{9};
        double a{5.4};
        double b{7.4};

        auto result = max(b, x, y);
        result = max(x, y);
        result = max(a, b);
        result = max(x, b);
        result = max(a, y);
        max("Hello", "World");
    }
    { // Overloading with Pointer Parameters
        double doubles[]{10.0, 30.0, 12.3};
        int ints[]{1, 2, 5, 2, 8, 4};

        auto result = max(ints, std::size(ints));
        std::cout << "result : " << result << std::endl;
        auto result2 = max(doubles, std::size(doubles));
        std::cout << "result2 : " << result2 << std::endl;
    }
    { // Overloading with Reference Parameters
        std::string name{"Daniel"};
        /*
        error: call of overloaded ‘say_my_name(std::string&)’ is ambiguous
        say_my_name(name);
        say_my_name("Daniel");
        */

        char a{6};
        char b{9};

        auto result = max_imcref(a, b);
    }
    { // Overloading with const paramaters by value
        say_my_age(20);
    }
    { // Overloading with Const Pointer and Pointer to Const Paramters
        int a{10};
        int b{12};

        const int c{30};
        const int d{15};

        auto result_a = max_cp(&a, &b);
        auto result_b = max_cp(&c, &d);

        const int c1{30};
        const int d1{15};

        const int *p_c{&c1};
        const int *p_d{&d1};

        std::cout << "&p_c : " << &p_c << std::endl;
        std::cout << "&p_d : " << &p_d << std::endl;

        auto result_min = min(p_c, p_d);
    }
    { // Overloading with const references
        int a{45};
        int b{85};

        int max1 = max_ref(a, b);
        std::cout << "max1 : " << max1 << std::endl;

        const int &ref_a = a;
        const int &ref_b = b;

        int max2 = max_ref(ref_a, ref_b);
        std::cout << "max2 : " << max2 << std::endl;
    }
    { // Overloading with default parameters
      // print_age(); Error: Ambiguous call
    }

    return 0;
}
// Definitions
void print_age(int age)
{
    std::cout << "Your age is( int version)  : " << age << std::endl;
}

void print_age(long int age)
{
    std::cout << "Your age is (long int version) : " << age << std::endl;
}
void say_my_age(const int age)
{
    std::cout << "You are " << age << " years old!" << std::endl;
}