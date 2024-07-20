/*
  @Author: Mitul Tyagi
  @Date:   2023-11-03 22:11:43
  @Description: Arrays
  @Last Modified time: 2024-07-13 12:51:49
*/
/*
- An array is a data structure that is used to store multiple values of similar data types in a contiguous memory location. For a type T, T[size] is the type
  "array of size elements of type T". The elements are indexed from 0 to size-1. It is a fundamental way of representing a sequence of objects in memory.
- Properties of Arrays in C++
        - An Array is a collection of data of the same data type, stored at a contiguous memory location.
        - Indexing of an array starts from 0. It means the first element is stored at the 0th index, the second at 1st index, and so on.
        - Elements of an array can be accessed using their indices.
        - Once an array is declared its size remains constant throughout the program.
        - An array can have multiple dimensions.
        - The number of elements in an array can be determined using the sizeof operator.
        - The size of the type of elements stored in an array can be obtained by subtracting adjacent addresses.
- An array can be declared by specifying its name, the type of its elements, and the size of its dimensions. The compiler allocates the memory block of the
  specified size to the array name.
                data_type array_name [size];
- The C arrays are static in nature, i.e., they are allocated memory at the compile time.
- When the array is declared or allocated memory, the elements of the array contain some garbage value. So, the array is to be initialized to some meaningful
  value.There are multiple ways to initialize an array:
    - Array Initialization with Declaration: An initializer list is used to initialize elements of the array. An initializer list is the list of values
                                             enclosed within braces {} separated by comma
                data_type array_name [size] = {val1, val2, val3, ....., valN};
    - Array Initialization with Declaration without Size: The size of the array can be skipped when initializing using the initializer list. The compiler
                                                          automatically deduces the size.
                data_type array_name [] = {val1, val2, val3, ....., valN};
    - Array Initialization after Declaration (Using Loops): The initialization is done after the declaration by assigning the initial value to each element
                                                            individually. Loops can be used.
    - Initialize an Array Partially: The initializer list can be partial. The rest of the values will be intialized to 0.
    - Initialize the array with zero: All the elements can be initialized to '0' by specifying '0' inside the curly braces.
- Elements of an array can be accessed by specifying the name of the array, then the index of the element enclosed in the array subscript operator [].
- To update an element in an array, the index which is to be updated can be enclosed within the array subscript operator and assign the new value.
- Access out of the range of an array is undefined and usually disastrous. In particular, run-time range checking is neither guaranteed nor common. The number
  of elements of the array, the array bound, must be a constant expression.
- Multidimensional arrays are represented as arrays of arrays.
- An array can be allocated statically, on the stack, and on the free store.
- There is no array assignment, and the name of an array implicitly converts to a pointer to its first element at the slightest provocation.
- A zero(null)-terminated array of char is often called a C-style string. C++ string literals follow that convention, and some standard-library functions rely
  on it. Often, a char* or a const char* is assumed to point to a zero(null)-terminated sequence of characters.
- An array can be initialized by a list of values. When an array is declared without a specific size, but with an intializer list, the size is calculated by
  counting the elements of the initializer list. If a size is explicitly specified, it is an error to give surplus elements in an intializer list. If the
  initializer supplies too few elements for an array, 0 is used for the rest.
- There is no built-in copy operation for arrays. One array can not be initialized with another. There is no array assignment. Arrays can not be pass by value.
- An array of characters can be conveniently initialized by a string literal.
- A string literal is a character sequence enclosed within double quotes. A string literal contains one more character than it appears to have, it is terminated
  by the null character: '\0', with the value 0. The type of a string literal is "an array of the appropiate number of const characters". The string literals
  are immutable. To modify the string characters, they must be placed in a non-const array.
- A string literal is statically allocated so that it is safe to return one from a function. Whether two identical strings are allocated as one array or as two
  is implementation defined.
- The empty string is written as a pair of adjacent double quotes, "", and has the type const char[1]. The one character of the empty string is the terminating
  '\0'. The backslash convention for representing nongraphic characters can also be used within a string. Long strings can be broken by whitespace to make the
  program text neater. The compiler will concatenate adjacent strings.
- It is possible to have the null character in a string, but most programs will not suspect that there are characters after it. Also, "real" newline string
  literal can not be present.
- A raw string literal is a string literal where a backslash is just a backslash and a double quote is just a double quote. Raw string literals use the
  R"(ccc)" notation for a sequence of characters ccc. The delimiters can be added before the ( and after the ) in "(...)". The character sequence after the )
  must be identical to the sequence before the (. A raw string literal can contain a new line in contrast to non-raw string literals.
- A string with prefix L is a string of wide characters. Its type is const wchar_t[]. Similarly, a string with the prefix LR is a raw string of wide characters
  of type const wchar_t[]. Such a string is terminated by a L'\0' character.
*/
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
int a1[10]; // 10 ints in static storage
void f()
{
  int a2[20];           // 20 ints on the stack
  int *p = new int[40]; // 40 ints on the free store or heap
}
void g()
{
  int a[10];
  a[6] = 9;      // assign to a's 7th element
  int x = a[99]; // undefined behaviour
}
const char *error_message()
{
  return "range error";
}
int main(int argc, char const *argv[])
{
  float v[3];
  char *a[32];
  int arr[3];

  int v1[] = {1, 2, 3, 4};
  char v2[] = {'a', 'b', 'c', 0};
  // char v3[3] = {'a', 'b', 'c', 0}; // error: too many initializers
  char v4[6] = {'a', 'b', 'c', 0}; // ok
  char *str = "this is a string";  // warning: ISO C++ forbids converting a string constant to 'char*'
  // str[5] = 'e';// error: segmentation fault as str is a const
  std::cout << "String Literal: " << str << std::endl;
  char p[] = "Zeno"; // p is an array of 5 char
  p[0] = 'R';        // ok
  std::cout << "String Literal: " << p << std::endl;
  const char *mess = error_message();
  std::cout << "String Literal Statically Allocated: " << mess << std::endl;
  const char *messp = "AON";
  const char *messq = "AON";
  (messp == messq) ? std::cout << "Equal" << std::endl : std::cout << "Unequal" << std::endl; // Implementation Defined.

  std::cout << "Beep at the end of message\a\n"
            << std::endl;
  char alpha[] = "asfdhdasfshgfsdfshngdh"
                 "dhythterysadfshadfshDFSDGHDSEFGEDSFsgdth";
  // Inserting elements in an array
  arr[0] = 10;
  arr[1] = 20;
  arr[2] = 30;

  // Accessing and printing elements of the array
  std::cout << "arr[0]: " << arr[0] << std::endl;
  std::cout << "arr[1]: " << arr[1] << std::endl;
  std::cout << "arr[2]: " << arr[2] << std::endl;
  // Initialize the array
  int table_of_two[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};

  // Traverse the array using for loop
  for (int i = 0; i < 10; i++)
  {
    // Print the array elements using indexing
    std::cout << table_of_two[i] << " ";
  }

  {
    int arr[] = {1, 2, 3, 4, 5};

    // Size of one element of an array
    std::cout << "\nSize of arr[0]: " << sizeof(arr[0]) << std::endl;

    // Size of array 'arr'
    std::cout << "Size of arr: " << sizeof(arr) << std::endl;

    // Length of an array
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Length of an array: " << n << std::endl;
  }
  {
    // Declare an array of ints
    int scores[10]; // Junk data

    // Read data
    std::cout << " scores [0] : " << scores[0] << std::endl;
    std::cout << " scores [1] : " << scores[1] << std::endl;

    // Read with a loop
    for (size_t i{0}; i < 10; ++i)
    {
      std::cout << "scores [" << i << "] : " << scores[i] << std::endl;
    }

    scores[0] = 20;
    scores[1] = 21;
    scores[2] = 22;

    // Print the data out
    for (size_t i{0}; i < 10; ++i)
    {
      std::cout << "scores [" << i << "] : " << scores[i] << std::endl;
    }

    // Write data in a loop
    for (size_t i{0}; i < 10; ++i)
    {
      scores[i] = i * 10;
    }

    // Print the data out
    for (size_t i{0}; i < 10; ++i)
    {
      std::cout << "scores [" << i << "] : " << scores[i] << std::endl;
    }

    // Declare and initialize at the same time
    double salaries[5]{12.7, 7.5, 13.2, 8.1, 9.3};
    for (size_t i{0}; i < 5; ++i)
    {
      std::cout << "salary[" << i << "] : " << salaries[i] << std::endl;
    }

    // If you don't initialize all the elements, those you leave out
    // are initialized to 0
    int families[5]{12, 7, 5};

    for (size_t i{0}; i < 5; ++i)
    {
      std::cout << "families[" << i << "] : " << families[i] << std::endl;
    }

    // Omit the size of the array at declaration
    int class_sizes[]{10, 12, 15, 11, 18, 17, 23, 56};

    // Will print this with a range based for loop
    for (auto value : class_sizes)
    {
      std::cout << "value : " << value << std::endl;
    }

    // Read only arrays
    const int birds[]{10, 12, 15, 11, 18, 17, 23, 56};
    // birds[2] = 8; //error

    // Sum up scores array, store result in sum
    int marks[]{2, 5, 8, 2, 5, 6, 9};
    int sum{0};

    for (int element : marks)
    {
      sum += element;
    }
    std::cout << "Score sum : " << sum << std::endl;
  }
  {
    // size of an array
    int scores[]{1, 2, 5};

    int count{std::size(scores)}; // std::size (C++17)

    std::cout << "sizeof(scores) : " << sizeof(scores) << std::endl;
    std::cout << "sizeof(scores[0]) : " << sizeof(scores[0]) << std::endl;
    std::cout << "count : " << count << std::endl;

    int count_elements{sizeof(scores) / sizeof(scores[0])};

    for (size_t i{0}; i < count_elements; ++i)
    {
      std::cout << "scores [" << i << "] : " << scores[i] << std::endl;
    }

    for (size_t i{0}; i < std::size(scores); ++i)
    {
      std::cout << "scores [" << i << "] : " << scores[i] << std::endl;
    }

    // Range based for loop
    for (int count_elem{std::size(scores)}; auto i : scores)
    {
      std::cout << "Total Elements: " << count_elem << " value  : " << i << std::endl;
    }
  }
  { // Arrays of characters
    // Declare array
    char message[5]{'H', 'e', 'l', 'l', 'o'};
    int data[5]{1, 2, 3, 3, 3};

    std::cout << "data : " << data << std::endl;

    // Print out the array through looping
    std::cout << "message : ";
    for (auto c : message)
    {
      std::cout << c;
    }
    std::cout << std::endl;

    // Change characters in our array
    message[1] = 'a';

    // Print out the array through looping
    std::cout << "message : ";
    for (auto c : message)
    {
      std::cout << c;
    }
    std::cout << std::endl;

    // Will probably print garbage after your char array
    std::cout << "message : " << message << std::endl;
    // message = {'H','e', 'l', 'l', 'o','\0'}; //Expression must be a modifiable l-value
    // If a character array is null terminated, it's called as C-String
    char message1[]{'H', 'e', 'l', 'l', 'o', '\0'};
    std::cout << "message1 : " << message1 << std::endl;
    std::cout << "sizeof(message1) : " << sizeof(message1) << std::endl;
    char message11[]{'H', 'e', 'l', 'l', 'o', 0};
    std::cout << "message11 : " << message11 << std::endl;
    std::cout << "sizeof(message11) : " << sizeof(message11) << std::endl;

    // Auto Filled in null characters
    char message2[6]{'H', 'e', 'l', 'l', 'o'};
    std::cout << "message2 : " << message2 << std::endl;
    std::cout << "sizeof(message2) : " << sizeof(message2) << std::endl;

    char message3[]{'H', 'e', 'l', 'l', 'o'}; // This is not a c string , as there is no null character
    std::cout << "message3 : " << message3 << std::endl;
    std::cout << "sizeof(message3) : " << sizeof(message3) << std::endl;

    // String literals
    char message4[]{"Hello"};
    // char message41[5]{"Hello"}; //Error: initializer-string for ‘char [5]’ is too long
    // char message42[5] = {"Hello"}; // Error: initializer-string for ‘char [5]’ is too long
    std::cout << "message4 : " << message4 << std::endl;
    std::cout << "sizeof(message4) : " << sizeof(message4) << std::endl;
    char message5[6] = {"Hello"}; // This works fine as there is a space to hold an extra character.
    std::cout << "message5 : " << message5 << std::endl;
    std::cout << "sizeof(message5) : " << sizeof(message5) << std::endl;

    char message6[]{"Hello World!!"};
    std::cout << "message6 : " << message6 << std::endl;
    std::cout << "sizeof(message6) : " << sizeof(message6) << std::endl;

    // Can't safely print out arrays other than those of characters
    int numbers[]{1, 2, 3, 4, 5};
    std::cout << "numbers :  " << numbers << std::endl;
  }
  {
    // Array Bounds
    int numbers[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

    // Read beyond bounds : Will read garbage or crash your program
    // std::cout << "numbers[12] : " << numbers[12] << std::endl;

    // Write beyond bounds. The compiler allows it. But you don't own
    // the memory at index 12, so other programs may modify it and your
    // program may read bogus data at a later time. Or you can even
    // corrupt data used by other parts of your ptogram

    // numbers[129] = 1000;
    // std::cout << "numbers[129] : " << numbers[129] << std::endl;

    // std::cout << "Program ending...." << std::endl;
  }
  {
    auto a = std::time(0);    // Time since January 1st,1970 at 00:00:00 AM. The type of a is type_t (typedef long type_t)
    std::srand(std::time(0)); // Seed to make sure each new run gives a different sequence
    std::cout << "Time Val: " << a << std::endl;
    std::cout << "Size of time_t: " << sizeof(time_t) << std::endl;
    int random_num = std::rand();

    std::cout << "RAND_MAX: " << RAND_MAX << std::endl; // RAND_MAX

    std::cout << "random_num : " << random_num << std::endl; // 0 ~ RAND_MAX

    random_num = std::rand();
    std::cout << "random_num : " << random_num << std::endl; // 0 ~ RAND_MAX

    // Generate random numbers in a loop
    for (size_t i{0}; i < 20; ++i)
    {
      random_num = std::rand();
      std::cout << "random_num " << i << ":" << random_num << std::endl; // 0 ~ RAND_MAX
    }

    // Generate a range between 0 and 10. % controls the upper bound.
    random_num = std::rand() % 11; // [ 0 ~10]

    for (size_t i{0}; i < 20; ++i)
    {
      random_num = std::rand() % 11;
      std::cout << "random_num " << i << "  :   " << random_num << std::endl; // 0 ~ RAND_MAX
    }

    // Adding a constant changes both the upper and lower bound.
    random_num = (std::rand() % 10) + 1; // [1~10]
    for (size_t i{0}; i < 20; ++i)
    {
      random_num = (std::rand() % 10) + 1;
      std::cout << "random_num " << i << "  :   " << random_num << std::endl; // 0 ~ RAND_MAX
    }
  }
  return 0;
}
/*
String Literal: this is a string
String Literal: Reno
String Literal Statically Allocated: range error
Equal
Beep at the end of message

arr[0]: 10
arr[1]: 20
arr[2]: 30
2 4 6 8 10 12 14 16 18 20
Size of arr[0]: 4
Size of arr: 20
Length of an array: 5
*/