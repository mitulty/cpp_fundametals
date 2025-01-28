/*
  @Author: Mitul Tyagi
  @Date:   2023-10-21 15:56:40
  @Description: Objects
*/
/*
- An object is a contiguous region of storage.
- An lvalue is an expression that refers to an object. An lvalue is an expression that yields an object reference, such as a variable name, an array subscript
  reference, a dereferenced pointer, or a function call that returns a reference. An lvalue always has a defined region of storage. An lvalue that has not been
  declared const is often called a modifiable lvalue.
- An rvalue is an expression that is not an lvalue. Examples of rvalues include literals, the results of most operators, and function calls that return
  nonreferences. An rvalue does not necessarily have any storage associated with it.
- An lvalue is an object reference and an rvalue is a value. An lvalue can be used on the left side of an assignment statement.
  The term rvalue is a logical counterpart for an expression that can be used only on the righthand side of an assignment.
- & gives the reference for an lvalue and && gives the reference for an rvalue.
- There are two properties that matter for an object when it comes to addressing, copying, and moving.
        -> Has Identity: The program has the name of, pointer to, or reference to the object.
        -> Movable: The object may be moved from.
- The classificarion for the values is:
        -> lvalue: { i & !m }      -> xvalue: { i & m }        -> prvalue: {!i & m }  -> glvalue: { i }  -> rvalue: { m }
- The lifetime of an object starts when its constructor completes and ends when its destructor starts executing.
        -> Automatic: Unless the programmer specifies otherwise, an object declared in a function is created when its definition is encountered
                      and destroyed when its name goes out of scope. They are allocated on the stack, Each call of the funtion gets its own stack frame
                      to hold its automatic objects.
        -> Static: Objects declared in global or namespace scope and static declared in functions or classess are created and initialized only once and live
                   until the program terminates. It has the same address throughout the life of a program execution.
        -> Free Store: Using the new and delete operators, objects are created whose lifetimes are controlled directly.
        -> Temporary Objects: These can be intermediate results in a computation or an object used to hold a value for a reference to const argument.
                              Thier lifetime is determined by their use. They are automatic.
        -> Thread-Local Objects: They are created when their thread is and destroyed when their thread is.
- Array elements and nonstatic class members have their lifetimes determined by the object of which they are part of.
- Static and automatic are referred to as storage classes.

*/
#include <iostream>

using namespace std;
int *ptr{nullptr}; // To store the static value.
int SetValue(int &value)
{
  int j = value;
  std::cout << j << std::endl;
  return j;
}
int SetValueConst(const int &value)
{
  int j = value;
  std::cout << j << std::endl;
  return j;
}
int GetValue()
{
  return 10;
}
int &GetRefValue()
{
  static int val = 10;
  // int val = 10; Error: This will not work as the variable is lost once the function call gets over.
  ptr = &val;
  return val;
}
void printname(std::string &name)
{
  std::cout << name << std::endl;
}
void printnamerval(const std::string &name)
{
  std::cout << name << std::endl;
}
void printnamervalref(std::string &&name) // This will be preffered over const version during overloading
{
  std::cout << name << std::endl;
}
int main(int argc, char const *argv[])
{
  int ival = 9;
  int aval = ival;
  int xval = GetValue();
  // GetValue() = 9; // Error
  GetRefValue() = 4; // Assigning 4 to a reference of an lvalue which gets assigned to the static value.
  std::cout << "Final Value: " << *ptr << std::endl;
  SetValue(ival);
  // SetValue(9); //Error: Initial value of reference to non-const must be an lvalue
  SetValueConst(9); // This will work
  SetValueConst(ival);
  // int& iref =9; // Error: Initial value of reference to non-const must be an lvalue
  const int &iref = 9; // This will work as it creates a temp lvalue and then assigns it to reference
  std::string firstName = "Mike";
  std::string lastname = "Cherry";
  std::string fullnamme = (firstName + lastname); // This is an rvalue
  printname(fullnamme);
  // printname(firstName + lastname); // This is an rvalue.
  printnamerval(fullnamme);
  printnamerval(firstName + lastname);
  printnamervalref(firstName + lastname);
  // printnamervalref(fullnamme); // Error: An rvalue reference can not be bound to an lvalue
  return 0;
}
/*
Final Value: 4
9
9
9
MikeCherry
MikeCherry
MikeCherry
MikeCherry
*/
