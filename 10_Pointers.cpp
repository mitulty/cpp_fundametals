/*
  @Author: Mitul Tyagi
  @Date:   2023-11-04 23:09:26
  @Description: Pointers and References
  @Last Modified time: 2024-02-17 00:06:56
*/
/*
- For a type T, T* is the type "pointer to T". That is, a variable of type T* can hold the address of an object of type T. The fundamental operation
  on a pointer is dereferencing, that is, referring to the object pointed to by the pointer. This operation is also called indirection. The
  dereferencing operator is unary *. The implementation of pointers is intended to map directly to the addressing mechanisms of the machine on which
  the program runs. Most machines can address a byte. Those that can't tend to have hardware to extract bytes from words.
- The *, meaning "pointer to", is used  as a suffix for a type name. A void* is a pointer to an object of unknown type. A pointer to any type of
  object can be assigned to a variable of type void*, but a pointer to function or a pointer to member cannot. A void* can be assigned to another
  void*, void* can be compared for equality and inequality, and a void* can be explicitly converted to another type. To use a void*, it must be
  explicitly converted to a pointer to a specific type.
- The primary use for void* is for passing pointers to functions that are not allowed to make assumptions about the type of the object and for
  returning untyped objects from functions. To use such an object, explicit type conversion is needed.
- The literal nullptr represents the null pointer, that is, a pointer that does not point to an object. It can be assigned to any pointer type, but
  not to other built-in types. There is just one nullptr, which can be used for every pointer type, rather than a null pointer for each pointer type.
  Before nullptr was introduced, zero(0) was used as a notation for the null pointer.
- The pointer and arrays are closely related. The name of an array can be used as a pointer to its initial element. The result of taking the address
  of the element before the initial element or beyond one-past-the-last element is undefined and should be avoided. The implicit conversion of the
  array argument to a pointer means that the size of the array is lost to the called function. There is no implicit or explicit conversion from a
  pointer to an array.
- Subscripting a built-in array is defined in terms of the pointer operations + and *. For every built-in array a and integer j within the range of a:
         a[j] == *(&a[0]+j) == *(a+j) == *(j+a) == j[a]
- The result of applying the arithmetic operators +,-,++, or -- to pointers depends on the type of the object pointed to. When an arithmetic operator
  is applied to a pointer p of type T*, p is assumed to point to an element of an array of objects of type T; p+1 points to the next element of that
  array, and p-1 points to the previous element. Subtraction of pointers is defined only when both pointers point to elements of the same array. When
  subtracting a pointer p from another pointer q, (q-p), the result is the number of array elements in the sequence [p:q). One can add an integer to
  a pointer or subtract an integer from a pointer; in both cases, the result is a pointer value. If that value does not point to an element of the
  same array as the original pointer or one beyond, the result of using that value is undefined.
- Arrays can not directly be passed by value. Instead, an array is passed as a pointer to its first element. When used as a function argument, the
  first dimension of an array is simply treated as a pointer. To pass a sequence of elements without losing the size informatino, it should not be
  pass as a built-in array. Instead, the array can be placed inside a class as a member(as is done for std::array) or define a class that acts as a
  handle (as is done for std::string and std::vector).
- Multidimensional arrays are represented as arrays of arrays. A matrix represented as a multidimensional array is passed as a pointer. The first
  dimension of an array is irrelevant to finding the location of an element; it simply states how many elements of the appropriate type are present.
  The first dimension can therefore be passed as an argument. The argument declaration m[][] is illegal because the second dimension of a
  multidimensional array must be known in order to find the location of an element. However, the expression m[i][j] is interpreted as *(*(m+i)+j).
- In constant pointers, the memory address stored inside the pointer is constant and cannot be modified once it is defined. It will always point to
  the same memory address. The value at the memory address can be changed though.
                        data_type * const pointer_name;
- The pointers pointing to a constant value that cannot be modified are called pointers to a constant. Here the data can be only accessed pointed by
  the pointer, but cannot modify it. Although, the address stored in the pointer to constant can be changed.
                        const data_type * pointer_name;
- If the variable is a constant then the pointer should be declared as a pointer to a const.
*/
#include <iostream>

using namespace std;
void f(int *pi)
{
  void *pv = pi; // ok: implicit conversion of int* to void*
  // *pv; // error: can't deference void*
  // ++pv; // error: can't increment void* (the size of the object pointed to is unknown)

  int *pi2 = static_cast<int *>(pv); // explicit conversion back to int*
  // double *pd1 = pv;//error
  // double *pd2 = pi;// error
  double *pd3 = static_cast<double *>(pv); // unsafe
}
int main(int argc, char const *argv[])
{
  {
    int *pi = nullptr;    // pointer to int
    char **ppc = nullptr; // pointer to pointer to char
    int *ap[15];          // array of 15 pointers to int
    int (*fp)(char *);    // pointer to function taking a char* argument; returns an int
    int *f(char *);       // function taking a char* argument; returns a pointer to int

    int v[] = {1, 2, 3, 4};
    int *p1 = v;     // pointer to initial element (implicit conversion)
    int *p2 = &v[0]; // pointer to initial element
    int *p3 = v + 4; // pointer to one-beyond-last element
  }
  { // Declaring a Pointer

    int *p_number{};               // Initialized to nullptr
    double *p_fractional_number{}; // Initialized to nullptr

    int *p_number1{nullptr};
    int *p_fractional_number1{nullptr};
    // Pointers to different variables are  of the same size
    std::cout << "sizeof(int) : " << sizeof(int) << std::endl;                                   // 4
    std::cout << "sizeof(double) : " << sizeof(double) << std::endl;                             // 8
    std::cout << "sizeof(double*) : " << sizeof(double *) << std::endl;                          // 8
    std::cout << "sizeof(int*) : " << sizeof(int *) << std::endl;                                // 8
    std::cout << "sizeof(p_number1) : " << sizeof(p_number1) << std::endl;                       // 8
    std::cout << "sizeof(p_fractional_number1) : " << sizeof(p_fractional_number1) << std::endl; // 8

    // It doesn't matter if you put the * close to data type or to varible name
    int *p_number2{nullptr};
    int *p_number3{nullptr};
    int *p_number4{nullptr};

    int *p_number5{}, other_int_var{};
    int *p_number6{}, other_int_var6{}; // Confusing as you wonder if other_int_var6
                                        // is also a pointer to int. It is not
                                        // The structure is exactly the same for the
                                        // previous statement

    std::cout << "sizeof(p_number5) : " << sizeof(p_number5) << std::endl;
    std::cout << "sizeof(other_int_var) : " << sizeof(other_int_var) << std::endl;
    std::cout << "sizeof(p_number6) : " << sizeof(p_number6) << std::endl;
    std::cout << "sizeof(other_int_var6) : " << sizeof(other_int_var6) << std::endl;

    // It is better to separate these declarations on different lines though
    int *p_number7{};
    int other_int_var7{}; // No room for confusion this time

    // Initializing pointers and assigning them data
    // We know that pointers store addresses of variables
    int int_var{43};
    int *p_int{&int_var}; // The address of operator (&);

    std::cout << "Int var : " << int_var << std::endl;
    std::cout << "p_int (Address in memory)  : " << p_int << std::endl;

    // You can also change the address stored in a pointer any time
    int int_var1{65};
    p_int = &int_var1; // Assign a different address to the pointer
    std::cout << "Int var1: " << int_var1 << std::endl;
    std::cout << "p_int (with different address)  : " << p_int << std::endl;

    // Can't cross assign between pointers of different types
    int *p_int1{nullptr};
    double double_var{33};

    // p_int = &double_var; // Compiler error

    // Dereferencing a pointer :
    int *p_int2{nullptr};
    int int_data{56};
    p_int2 = &int_data;

    std::cout << "value : " << *p_int2 << std::endl; // Dereferencing a pointer
  }
  { // Pointer to Char

    char *p_char_var{nullptr};
    char char_var{'A'};
    p_char_var = &char_var;
    std::cout << "The value stored in p_char_var is: " << *p_char_var << std::endl;

    char char_var1{'A'};
    p_char_var = &char_var1;
    std::cout << "The value stored in p_char_var is: " << *p_char_var << std::endl;

    char *p_message{"Hello World!!!"}; // Array of constant characters
    std::cout << "p_message : " << p_message << std::endl;

    const char *message{"Hello World!"};
    std::cout << "message : " << message << std::endl;

    //*message = "B"; // Compiler error
    std::cout << "*message : " << *message << std::endl;

    // Allow users to modify the string
    char message1[]{"Hello World!"};
    message1[0] = 'B';
    std::cout << "message1 : " << message1 << std::endl;
  }
  { // Const Pointer and Pointer to Const

    // A raw variable that can be modified
    std::cout << std::endl;
    std::cout << "Raw variable that can be modified : " << std::endl;

    int number{5}; // Not constant, can change number any way we want
    std::cout << "number : " << number << std::endl;
    std::cout << "&number : " << &number << std::endl;
    // Modify
    number = 12;
    number += 7;

    // Access - Print out
    std::cout << "number : " << number << std::endl;
    std::cout << "&number : " << &number << std::endl;
    std::cout << std::endl;

    // Pointer : Can modify the data and the pointer itself
    int *p_number1{nullptr};
    int number1{23};

    p_number1 = &number1;
    std::cout << "Pointer and value pointed to : both modifiable : " << std::endl;
    std::cout << "p_number1 :" << p_number1 << std::endl;    // Address
    std::cout << "*p_number1 : " << *p_number1 << std::endl; // 23
    std::cout << "number1 : " << number1 << std::endl;       // 23

    // Change the pointed to value through pointer
    std::cout << std::endl;
    std::cout << "Modifying the value pointed to p_number1 through the pointer : " << std::endl;
    *p_number1 = 432;
    std::cout << "p_number1 : " << p_number1 << std::endl;
    std::cout << "*p_number1  : " << *p_number1 << std::endl;
    std::cout << "number1 : " << number1 << std::endl;

    // Change the pointer itself to make it point somewhere else
    std::cout << std::endl;
    std::cout << "Changing the pointer itself to make it point somewhere else" << std::endl;
    int number2{56};
    p_number1 = &number2;
    std::cout << "p_number1 :" << p_number1 << std::endl;
    std::cout << "*p_number1  : " << *p_number1 << std::endl;
    std::cout << "number1 : " << number1 << std::endl;
    std::cout << "number2 : " << number2 << std::endl;
    std::cout << std::endl;

    // Pointer to const
    // Pointer pointing to constant data : You can't modify the data through pointer
    std::cout << "Pointer is modifiable , pointed to value is constant : " << std::endl;
    int number3{632}; // Although you can omit the const on number3 here and it is still
                      // going to compile, it is advised to be as explicit as possible in
                      // your code and put the const in front. Make your intents CLEAR.

    const int *p_number3{&number3}; // Can't modify number3 through p_number3

    std::cout << "p_number3 :" << p_number3 << std::endl;
    std::cout << "*p_number3 : " << *p_number3 << std::endl;

    std::cout << std::endl;
    // std::cout << "Modifying the value pointed to by p_number3 through the pointer (Compile Error) : " << std::endl;
    //*p_number3 = 444; // Compile error

    // Although we can't change what's pointed to by p_number3,
    // we can still change where it's pointing

    std::cout << std::endl;
    std::cout << "Changing the address pointed to by p_number3 : " << std::endl;
    int number4{872};
    p_number3 = &number4;

    std::cout << "p_number3 :" << p_number3 << std::endl;
    std::cout << "*p_number3 : " << *p_number3 << std::endl;

    std::cout << std::endl;

    // const keyword applies to the variable name.
    std::cout << "const keyword applies to a variable name : " << std::endl;

    int protected_var{10}; // Can make it const to protect it if we want.Show this
    // p_protected_var is a pointer to const data, we can't
    // modify the data through this pointer : regardless of
    // whether the data itself is declared const or not.
    const int *p_protected_var{&protected_var};

    //*p_protected_var = 55;
    protected_var = 66;
    std::cout << "protected_var : " << protected_var << std::endl;
    std::cout << "p_protected_var : " << p_protected_var << std::endl;
    std::cout << "*p_protected_var : " << *p_protected_var << std::endl;
    std::cout << std::endl;

    // You can't set up a modifiable pointer to const data though,
    // You'll get a compiler error :Invalid convertion from 'const type*' to 'type*'.
    const int some_data{55};
    // int * p_some_data {&some_data}; // Compiler error.
    //*p_some_data = 66;

    // Both pointer and pointed to value are constant
    const int number5{459};
    const int *const p_number5{&number5};
    std::cout << "Pointer is constant, value pointed to is constant : " << std::endl;
    std::cout << "p_number5 :" << p_number5 << std::endl;
    std::cout << "*p_number5 : " << *p_number5 << std::endl;

    // Can't modify the pointed to value through the pointer
    std::cout << "Changing value pointed to by p_number5 through the pointer (Compile Error) " << std::endl;
    //*p_number5 = 222; // Error : Trying to assign to read only location

    // Can't change where the pointer is pointing to : The pointer is now itself constant
    std::cout << "Changing the pointer p_number5 address itself (Compile Error) " << std::endl;
    int number6{333};
    // p_number5 = &number6;  // Error : Trying to assign to read only location

    std::cout << std::endl;

    // Pointer is constant (can't make it point anywere else)
    // but pointed to value can change
    std::cout << "Pointer is contant, pointed to value can change : " << std::endl;
    int number7{982};

    int *const p_number7{&number7};

    std::cout << "p_number7 :" << p_number7 << std::endl;
    std::cout << "*p_number7 : " << *p_number7 << std::endl;
    std::cout << "Changing value pointed to through p_number7 pointer : " << std::endl;

    *p_number7 = 456;
    std::cout << "The value pointed to by p_number7 now is : " << *p_number7 << std::endl;

    int number8{2928};
    std::cout << "Changing the address where p_number7 is pointing (Compile Error)." << std::endl;
    // p_number7 = &number8;
  }
  { // General Theory
    int var1{33};
    int *p_var2{&var1};             // Non Const Pointer to Int
    const int *p_var3{&var1};       // Pointer to Const
    const int *const p_var4{&var1}; // Const Pointer to Const
    int *const p_number7{&var1};    // Const Pointer to Non Const
  }
  { // Pointer Arithmetic: Navigation

    // Increment/ decrement pointer addresses manually

    int scores[10]{11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

    // scores++;

    int *p_score{scores};

    std::cout << "Values in scores array (p_score pointer increment) : " << std::endl;

    std::cout << "Address : " << p_score << " value : " << *(p_score) << std::endl;
    ++p_score; // Moves froward by sizeof(int) : 4 bytes

    std::cout << "Address : " << p_score << " value : " << *(p_score) << std::endl;
    ++p_score; // Moves froward by sizeof(int) : 4 bytes

    std::cout << "Address : " << p_score << " value : " << *(p_score) << std::endl;
    ++p_score; // Moves froward by sizeof(int) : 4 bytes

    std::cout << "Address : " << p_score << " value : " << *(p_score) << std::endl;
    ++p_score; // Moves froward by sizeof(int) : 4 bytes

    std::cout << "Address : " << p_score << " value : " << *(p_score) << std::endl;
    ++p_score; // Moves froward by sizeof(int) : 4 bytes

    std::cout << "Address : " << p_score << " value : " << *(p_score) << std::endl;
    ++p_score; // Moves froward by sizeof(int) : 4 bytes

    std::cout << "Address : " << p_score << " value : " << *(p_score) << std::endl;
    ++p_score; // Moves froward by sizeof(int) : 4 bytes

    std::cout << "Address : " << p_score << " value : " << *(p_score) << std::endl;
    ++p_score; // Moves froward by sizeof(int) : 4 bytes

    std::cout << "Address : " << p_score << " value : " << *(p_score) << std::endl;
    ++p_score; // Moves froward by sizeof(int) : 4 bytes

    std::cout << "Address : " << p_score << " value : " << *(p_score) << std::endl;
    ++p_score; // Moves froward by sizeof(int) : 4 bytes
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "Explicit addition of integer : " << std::endl;
    p_score = scores;                                           // Reset the pointer to the start of the array
    std::cout << "scores[4] : " << *(p_score + 4) << std::endl; // Moves forward by 4 * sizeof(int)

    // Can use loops to print these things out : easier
    p_score = scores;

    std::cout << std::endl;
    std::cout << "Pointer arithmetic on p_scores pointer and a for loop: " << std::endl;
    for (size_t i{0}; i < std::size(scores); ++i)
    {
      std::cout << "Value : " << *(p_score + i) << std::endl; // scores[i]
    }

    // Can also do arithmetic on the array name
    // just like any pointer.
    p_score = scores;

    std::cout << std::endl;
    std::cout << "Pointer arithmetic on array name: " << std::endl;
    for (size_t i{0}; i < std::size(scores); ++i)
    {
      std::cout << "Value : " << *(scores + i) << std::endl;
    }

    // Can Print the elements in reverse order
    std::cout << std::endl;
    std::cout << "Elements in reverse order with decrementing pointer arithmetic: " << std::endl;
    for (size_t i{std::size(scores)}; i > 0; --i)
    {
      std::cout << "Value : " << *(scores + i - 1) << std::endl; // Here we do the -1 thing, because
                                                                 // scores is already pointing to the first
                                                                 // element in the array.
    }

    // Print in reverse order with -- operator on p_score
    std::cout << std::endl;
    std::cout << "Elements in reverse order -- arithmetic on the p_scores pointer: " << std::endl;
    p_score = scores + std::size(scores) - 1;
    for (size_t i{std::size(scores)}; i > 0; --i)
    {
      std::cout << "Value : " << *(p_score--) << std::endl; // Here we do the -1 thing, because
                                                            // scores is already pointing to the first
                                                            // element in the array.
    }

    // Can Print the elements in reverse order with array index
    std::cout << std::endl;
    std::cout << "Elements in reverse order with array index notation: " << std::endl;
    for (size_t i{std::size(scores)}; i > 0; --i)
    {
      std::cout << "Value : " << scores[i - 1] << std::endl;
    }

    p_score = scores;

    scores[0] = 31;      // Array index notation
    *(scores + 1) = 32;  // Equivalent to scores[1] = 32 . Pointer arithmetic on array name
    *(p_score + 2) = 33; // Equivalent to scores[2] = 33 . Pointer arithmetic on p_score pointer

    std::cout << std::endl;
    std::cout << "Printing out the array after modification of 3 first elements: " << std::endl;
    for (size_t i{0}; i < std::size(scores); ++i)
    {
      std::cout << "Value : " << scores[i] << std::endl;
    }
  }
  { // Pointer Arithmetic: Distance Between Elements
    int scores[10]{11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

    // Array index notation
    //     int * pointer1 {&scores[0]};
    //     int * pointer2 {&scores[8]};

    // Pointer arithmetic notation
    int *pointer1{scores + 0};
    int *pointer2{scores + 8};

    std::cout << "pointer2 - pointer1 : " << pointer2 - pointer1 << std::endl; // 8
    std::cout << "pointer1 - pointer2 : " << pointer1 - pointer2 << std::endl; // -8

    std::ptrdiff_t pos_diff = pointer2 - pointer1;
    std::ptrdiff_t neg_diff = pointer1 - pointer2;
    std::cout << "pointer2 - pointer1 : " << pos_diff << std::endl; // 8
    std::cout << "pointer1 - pointer2 : " << neg_diff << std::endl; // -8
    std::cout << "sizeof(std::ptrdiff_t) : " << sizeof(std::ptrdiff_t) << std::endl;
  }
  { // Pointer Arithmetic: Comparing Pointers
    int scores[10]{11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

    int *pointer1{&scores[0]};
    int *pointer2{&scores[8]};

    // Can also compare pointers

    // The further you go in the array, the bigger the address

    std::cout << "Comparing pointers : " << std::boolalpha << std::endl;

    std::cout << "pointer1 > pointer2 : " << (pointer1 > pointer2) << std::endl;
    std::cout << "pointer1 < pointer2 : " << (pointer1 < pointer2) << std::endl;
    std::cout << "pointer1 >= pointer2 : " << (pointer1 >= pointer2) << std::endl;
    std::cout << "pointer1 <= pointer2: " << (pointer1 <= pointer2) << std::endl;
    std::cout << "pointer1 == pointer2 : " << (pointer1 == pointer2) << std::endl;
    std::cout << "pointer1 != pointer2 : " << (pointer1 != pointer2) << std::endl;
  }
  { // Array of Const Pointer to Const Char

    const char *const students[]{
        "Daniel Gray",
        "Tuna Philbe",
        "The Rock",
        "Kumar Singh",
        "Sam Ali",
        "Dave Mahoro"};

    // Print out the students
    std::cout << std::endl;
    std::cout << "Printing out the students : " << std::endl;
    for (const char *student : students)
    {
      std::cout << student << std::endl;
    }

    // *students[0] = 'K'; // It is an array of const chars

    // Can swap for new student though.
    const char *new_student{"Bob the Great"};
    // students[0] = new_student; // Compiler error when the students is a const char pointer
  }
  { // Pointer and Arrays

    int scores[10]{11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

    int *p_score{scores}; // Pointer Decaying

    // Print the address
    std::cout << "scores : " << scores << std::endl;   // Array
    std::cout << "p_score : " << p_score << std::endl; // Pointer
    std::cout << "&scores[0]  : " << &scores[0] << std::endl;

    // Print the content at that address
    std::cout << std::endl;
    std::cout << "Printing out data at array address : " << std::endl;
    std::cout << "*scores : " << *scores << std::endl;
    std::cout << "scores[0] : " << scores[0] << std::endl;
    std::cout << "*p_score : " << *p_score << std::endl;
    std::cout << "p_score[0] : " << p_score[0] << std::endl;

    // Differences
    int number{21};
    p_score = &number;

    // scores = &number; // The array name is a pointer, but a special pointer that kind of identifies
    //  the entire array. You'll get the error  : incompatible types in assignment
    // of 'int*' to 'int[10]'

    std::cout << "p_score : " << p_score << std::endl; // Pointer

    // std::size() doesn't work for raw pointers
    std::cout << "size : " << std::size(scores) << std::endl;
    // std::cout << "size : " << std::size(p_score) << std::endl; // Compiler error.
  }
  {
    char *str{"Hello World!!!"}; // The string will be expanded to a character array and the first character is going to be pointed by str.
    // The string will be a const char[15] array. warning: warning: ISO C++ forbids converting a string constant to ‘char*’

    std::cout << "The message is: " << str << std::endl;           // This will point the entire string
    std::cout << "The value stored str is: " << *str << std::endl; /// This will print H
    *str = 'B';
    // std::cout << "The value after the change in str is: " << *str << std::endl; /// This will cause segmentation fault

    const char *str_2{"Hello World!!!"}; // Better to use const in the declaration to make sure the string is not modified and uses regular char
                                         // arrays to have modifiable string.
    // Array of const char pointers
    const char *predictions[]{
        "a lot of kids running in the backyard!",
        "a lot of empty beer bootles on your work table.",
        "you Partying too much with kids wearing weird clothes.",
        "you running away from something really scary",
        "clouds gathering in the sky and an army standing ready for war",
        "dogs running around in a deserted empty city",
        "a lot of cars stuck in a terrible traffic jam",
        "you sitting in the dark typing lots of lines of code on your dirty computer",
        "you yelling at your boss. And oh no! You get fired!",
        "you laughing your lungs out. I've never seen this before."};

    for (const char *pred : predictions)
      std::cout << pred << std::endl;
  }
  return 0;
}
