/*
  @Author: Mitul Tyagi
  @Date:   2024-01-29 22:33:35
  @Description: Functions: The Misfits
*/
/*
- Both global and static variables have static storage duration. They live throughout the entire lifetime of the program.
- Static variables are scoped to the function in which they are declared and used.
- Global variables are scoped to the global scope of the file where they are declared. They are accessible and usable through out the entire
  file.
- Inlining is just a suggestion to the compiler. The compiler could agree and expand the function calls in place, but it could also completely
  ignores inlining and just initiate regular function calls.
- Inline functions can increase the size of the application binary
- It is recommended to use inline functions for short, frequently used functions.
*/
#include <iostream>

using namespace std;

size_t dog_count{0}; // Global scope

unsigned int add_student()
{
    static unsigned int student_count{0}; // The scope of this var is in add_student, but it's lifetime goes beyond the function execution.
    student_count++;
    ++dog_count;
    return student_count;
}

void do_something()
{
    //--student_count; // Compiler error
    ++dog_count;
}
inline int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
size_t sum_up_to_zero(size_t value)
{
    if (value != 0)
        return value + sum_up_to_zero(value - 1);
    return 0;
}

int main(int argc, char const *argv[])
{
    { // Static Variables

        std::cout << "student count : " << add_student() << std::endl; // 1
        std::cout << "student count : " << add_student() << std::endl; // 2
        std::cout << "student count : " << add_student() << std::endl; // 3

        for (size_t i{}; i < 20; ++i)
        {
            std::cout << "student count : " << add_student() << std::endl;
        }
    }
    { // Inline Functions
        int a{15};
        int b{8};

        std::cout << "max : " << max(a, b) << std::endl;

        // What the compiler might do to inline your function call
        std::cout << "max : ";
        if (a > b)
        {
            std::cout << a << std::endl;
        }
        else
        {
            std::cout << b << std::endl;
        }
    }
    { // Recursive Functions
        std::cout << "result : " << sum_up_to_zero(10) << std::endl;
    }
    return 0;
}
