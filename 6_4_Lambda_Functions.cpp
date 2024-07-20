/*
  @Author: Mitul Tyagi
  @Date:   2024-01-29 22:33:13
  @Description: Lambda Functions
  @Last Modified time: 2024-03-03 19:35:04
*/
/*
- Lambda function is a mechanism to set up anonymous functions (without names). Once setup, they can be named and called or called directly.
- Moving the declaration of the lambda out of the main function and in front won't cause a compilation failure. It can be considered a global variable and
  in can be used anywhere in the file containing the main function.
- Values captured by value can't be modified in the body of the lambda function by default.
*/
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int global_var{55};
    { // Declaring and Using Labmda Functions
        /*
        Lambda function signature :
                                [capture list] (parameters) ->return type{
                                        // Function body
                                }
        */
        // Declaring a lambda function and calling it through a name
        auto func = []()
        {
            std::cout << "Hello World!" << std::endl;
        };
        func();
        func();

        // Declare a lambda function and call it directly
        []()
        {
            std::cout << "Hello World!" << std::endl;
        }();

        // Lambda function that takes parameters

        [](double a, double b)
        {
            std::cout << "a + b : " << (a + b) << std::endl;
        }(10.0, 50.0);

        auto func1 = [](double a, double b)
        {
            std::cout << "a + b : " << (a + b) << std::endl;
        };

        func1(10, 20);
        func1(5, 7);

        // Lambda function that returns something
        auto result = [](double a, double b)
        {
            return a + b;
        }(10, 60);

        std::cout << "result : " << result << std::endl;
        std::cout << "result : " << [](double a, double b)
        {
            return a + b;
        }(10, 60) << std::endl;

        auto func2 = [](double a, double b)
        {
            return a + b;
        };

        auto result1 = func2(23, 7);
        auto result2 = func2(9, 45);

        std::cout << "result1 : " << result1 << std::endl;
        std::cout << "result2 : " << result2 << std::endl;
        std::cout << "direct call : " << func2(5, 2) << std::endl;

        // Explicitly specify the return type
        auto func3 = [](double a, double b) -> int
        {
            return a + b;
        };

        auto func4 = [](double a, double b)
        {
            return a + b;
        };

        double a{6.9};
        double b{3.5};

        auto result3 = func3(a, b);
        auto result4 = func4(a, b);

        std::cout << "result3 : " << result3 << std::endl;
        std::cout << "result4 : " << result4 << std::endl;
        std::cout << "sizeof(result3) : " << sizeof(result3) << std::endl; // 4
        std::cout << "sizeof(result4) : " << sizeof(result4) << std::endl; // 8

        std::cout << "Done!" << std::endl;
    }
    { // Capture Lists
        double a{10};
        double b{20};

        auto func0 = [a, b]()
        {
            std::cout << "a + b : " << a + b << std::endl;
        };
        func0();

        // Capturing by value
        int c{42};

        auto func = [c]()
        {
            std::cout << "Inner value : " << c << " &inner : " << &c << std::endl;
        };

        for (size_t i{}; i < 5; ++i)
        {
            std::cout << "Outer value : " << c << " &outer : " << &c << std::endl;
            func();
            ++c;
        }

        // Capture by reference
        int d{142};

        auto func1 = [&d]()
        {
            std::cout << "Inner value : " << d << " &inner : " << &d << std::endl;
        };

        for (size_t i{}; i < 5; ++i)
        {
            std::cout << "Outer value : " << d << " &outer : " << &d << std::endl;
            func1();
            ++d;
        }
    }
    { // Capture All Lists

        int c{42};

        auto func = [=]()
        {
            std::cout << "Inner value : " << c << std::endl;
            std::cout << "Inner Global value : " << global_var << std::endl;
        };

        for (size_t i{}; i < 5; ++i)
        {
            std::cout << "Outer value : " << c << std::endl;
            std::cout << "Outer Global value : " << global_var << std::endl;
            func();
            ++c;
            global_var += 5;
        }

        // Capturing all reference
        int e{120};
        int d{5};

        auto func1 = [&]()
        {
            std::cout << "Inner value(c) : " << c << std::endl;
            std::cout << "Inner value(d) : " << d << std::endl;
            std::cout << "Inner value(e) : " << e << std::endl;
            std::cout << "Inner Global value : " << global_var << std::endl;
        };

        for (size_t i{}; i < 5; ++i)
        {
            std::cout << "Outer value(c) : " << c << std::endl;
            std::cout << "Outer value(d) : " << d << std::endl;
            std::cout << "Outer value(e) : " << e << std::endl;
            std::cout << "Outer Global value : " << global_var << std::endl;
            func1();
            ++e;
            c += 17;
            --d;
            global_var -= 5;
        }
    }

    return 0;
}
