/*
  @Author: Mitul Tyagi
  @Date:   2023-11-08 22:52:52
  @Description: Templates and STL
  @Last Modified time: 2023-11-27 19:06:33
*/
/*
- A template is a simple yet very powerful tool in C++. The simple idea is to pass the data type as a parameter so that the same code is not written for different data types.
- C++ adds two new keywords to support templates: ‘template’ and ‘typename’. The second keyword can always be replaced by the keyword ‘class’.
- Templates are expanded at compiler time. This is like macros. The difference is, that the compiler does type-checking before template expansion. The idea is simple, source code contains only
  function/class, but compiled code may contain multiple copies of the same function/class.
- These are generally defined for functions and classes. More than one data type as arguments can be passed to templates. Also default arguments can be provided to the templates.
- Both function overloading and templates are examples of polymorphism features of OOP. Function overloading is used when multiple functions do quite similar (not identical) operations, templates
  are used when multiple functions do identical operations.
- Each instantiation of function template has its own copy of local static variables.Also, each instantiation of class template has its own copy of member static variables.
- Template specialization allows us to have different codes for a particular data type. It is possible in C++ to get a special behavior for a particular data type. This is called template
  specialization. If a specialized version is present, compiler first checks with the specialized version and then the main template. Compiler first checks with the most specialized version by
  matching the passed parameter with the data type(s) specified in a specialized version.
- Non-type arguments can be passed to templates. Non-type parameters are mainly used for specifying max or min values or any other constant value for a particular instance of a template. They
  must be const. The compiler must know the value of non-type parameters at compile time. Because the compiler needs to create functions/classes for a specified non-type value at compile time.
- Template argument deduction automatically deduces the data type of the argument passed to the class or function templates. This allows to instantiate the template without explicitly  specifying
  the data type.
*/
#include <iostream>

using namespace std;
// Function Template
template <typename T>
T myMax(T x, T y)
{
    return (x > y) ? x : y;
}
template <typename T>
void func(const T &x)
{
    static int i = 10;
    std::cout << ++i << std::endl;
    return;
}
template <class T>
void getMax(T a, T b)
{
    T result;
    result = (a > b) ? a : b;
    std::cout << "Maximum:" << result << std::endl;
}
// Specialized Templates
template <class T>
void fun(T a)
{
    std::cout << "The main template fun(): " << a << std::endl;
}

template <>
void fun(int a)
{
    std::cout << "Specialized Template for int type: "
              << a << std::endl;
}
// Non-Type Parameters
template <class T, int max>
int arrMin(T arr[], int n)
{
    int m = max;
    for (int i = 0; i < n; i++)
        if (arr[i] < m)
            m = arr[i];

    return m;
}
// Class Template
template <typename T>
class Array
{
private:
    T *ptr;
    int size;

public:
    Array(T arr[], int s);
    void print();
};

template <typename T>
Array<T>::Array(T arr[], int s)
{
    ptr = new T[s];
    size = s;
    for (int i = 0; i < size; i++)
        ptr[i] = arr[i];
}

template <typename T>
void Array<T>::print()
{
    for (int i = 0; i < size; i++)
        std::cout << *(ptr + i) << " ";
    std::cout << std::endl;
}
template <class T, class U = char>
class A
{
    T x;
    U y;

public:
    A() { std::cout << "Constructor Called" << endl; }
};

template <class T>
class Test
{
private:
    T val;

public:
    static int count;
    Test()
    {
        count++;
    }
};

template <class T>
int Test<T>::count = 0;
// defining a class template
template <class T>
class info
{
public:
    // constructor of type template
    info(T A)
    {
        cout << "A = " << A << ", size of data in bytes:" << sizeof(A) << std::endl;
    }
    // end of info()
}; // end of class

int main(int argc, char const *argv[])
{
    std::cout << myMax<int>(3, 7) << std::endl;
    // call myMax for double
    std::cout << myMax<double>(3.0, 7.0) << std::endl;
    // call myMax for char
    std::cout << myMax<char>('g', 'e') << std::endl;
    int arr[5] = {1, 2, 3, 4, 5};
    Array<int> array_class(arr, 5);
    array_class.print();
    func<int>(1);      // prints 11
    func<int>(2);      // prints 12
    func<double>(1.1); // prints 11

    A<char, char> a;
    A<int, double> b;
    A<float> c;

    Test<int> d;                         // value of count for Test<int> is 1 now
    Test<int> e;                         // value of count for Test<int> is 2 now
    Test<double> f;                      // value of count for Test<double> is 1 now
    cout << Test<int>::count << endl;    // prints 2
    cout << Test<double>::count << endl; // prints

    fun<char>('a');
    fun<int>(10);
    fun<float>(10.14);
    getMax(2, 5);
    getMax(2.6, 7.6);
    getMax('A', 'D');

    int arr1[] = {10, 20, 15, 12};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    char arr2[] = {1, 2, 3};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    // Second template parameter
    // to arrMin must be a
    // constant
    std::cout << arrMin<int, 10000>(arr1, n1) << std::endl;
    std::cout << arrMin<char, 256>(arr2, n2) << std::endl;
    // passing character value by creating an objects
    info<char> p('x');

    // passing integer value by creating an object
    info<int> q(22);

    // passing float value by creating an object
    info<float> r(2.25);

    return 0;
}
/*
7
7
g
1 2 3 4 5
11
12
11
Constructor Called
Constructor Called
Constructor Called
2
1
The main template fun(): a
Specialized Template for int type: 10
The main template fun(): 10.14
Maximum:5
Maximum:7.6
Maximum:D
10
1
A = x, size of data in bytes:1
A = 22, size of data in bytes:4
A = 2.25, size of data in bytes:4
*/