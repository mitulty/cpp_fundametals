/*
  @Author: Mitul Tyagi
  @Date:   2023-10-28 16:18:17
  @Description: Functions
*/
/*
- A function is a block of code that performs a specific task. Functions are used to group together related code, and they can be called from other parts of
  the program. This makes code more modular and reusable.
- A function declaration gives the name of the function, the type of the value returned (if any), and the number and the type of the arguments that must be
  supplied in a call.
- Defining a function is the way to specify how an operation is to be done. A function cannot be called unless it has been previously declared. It may contain
  argument names.
- The semantics of argument passing are identical to the semantics of copy initialisation. Argument types are checked and implicit argument type conversion
  takes place when necessary.
- As a return type, void means that the function does not return a value. The type of a function consists of the return type and the argument types.
- The following are the parts of the function:
    -> The name of the function.
    -> The argument list, which may be empty
    -> The return type, which may be void and which may be prefix or suffix (using auto)
    -> inline, indicating a desire to have function calls implemented by inlining the function body.
    -> constexpr, indicating that it should be possible to evaluate the function at compile time if given a constant expression as arguments.
    -> noexcept, indicating that the function may not throw an exception.
    -> A linkage specification (like static)
    -> [[noreturn]], indicating that the function will not return using the normal call/return mechanism.
- A member function may be specified as:
    -> virtual, indicating that it can be overridden in a derived class.
    -> override, indicating that it must be overriding a virtual function from a base class.
    -> final, indicating that it cannot be overriden in a derived class.
    -> static, indicating that it is not associated with a particular object.
    -> const, indicating that it may not modify its object.
- Ways of exiting a function:
    -> Executing a return statement.
    -> "Fallling off the end" of a function.
    -> Throwing an exception that isn't caught locally.
    -> Terminating because an exception was thrown and not caught locally in a noexcept function.
    -> Directly or indirectly invoking a system function that does not return (exit())
- Every functinon that is called must be defined somewhere (only once). A function definition is a function declaration in which the body of the function is
  presented. The definiton and all declarations for a function must specify the same type. A const is ignored at the highest level of argument type. Function
  argument names are not part of the function type and need to be identical in different declarations. Naming arguments in declaration that are not definitions
  is optional. An argument is unused in a function defintion by not naming it.
- Every function declaration contains a specification of the function's return type. Traditionally the return type comes first in a function declaration.
  However, a function declaration can also be written using a syntax that places the return type after the argument list. A prefix "auto" indicates that the
  return type is placed after the argument list. The suffix return type is preceded by ->.
- A function that does not retrun a  value has a "return type" of void. A value must be returned from a function that is not declared void. Conversely, a
  value can not be returned from a void function. A return value is specified by a return-statement. There can be more than one return-statement in a function.
  A return-statement intializes a variable of the returned type. The type of a return expression is checked against the type of the returned type, and all
  standard and user-defined type conversions are performed.
- Each time a function is called, a new copy of its arguments and local (automatic) variables are created. The store is reused after the function returns, so
  a pointer or a reference to a non-static variable should never be returned. The contents of the location will change unpredictably.
- There are no void values. However, a call of a void function may be used as the return value of a void function. A return statment is one of five ways of
  exiting a function.
- A function can be defined to be inline. It is hint to the compiler that it should generate the code for a call rather than laying down the code for the
  function once and then calling through the usual function call mechanism. An inline function still has a unique address, and so do static variables of an
  inline function. The defintion of an inline function in different translation units must be identical.
- If a function is inline, the compiler places a copy of the specified functions' code at each point where the function is called at the compile time. To
  reduce the overhead of control transfer the functions are inlined.
- In general, a function cannot be evaluated at compile time and therefore can not be called in a constant expression. When constexpr is used in a function
  defintion, it means "should be usable in a constant expression when given constant expression as arguments." When used in an object defintion, it means
  "evaluate the initializer at compile time."
- A constexpr function must consist of a single return-statement; no loops and no local variables are allowed. Also, a constexpr function may not have side
  effects. It is a pure function. It allows recursion and conditional expressions. The defintion of a constexpr function in different translation units must
  be identical.
- A constexpr function can not have side effects, so writing to nonlocal objects is not possible. However, a constexpr function can refer to nonlocal objects
  as long as it does not write to them. A constexpr function can take reference arguments but it can not write through such references, but const reference
  parameters are as useful as ever. It is possible for a constexpr function to return a reference or a pointer.
- A branch of a conditional expression that is not taken in a constexpr function is not evaluated. This implies that a branch not taken can require run-time
  evaluation.
- A construct [[...]] is called an attribute that specifies some implementation-dependent property about the syntactic entity that precedes it. In addition, an
  attribute can be placed in front of a declaration. There are only two standard attributes: [[noreturn]] and [[carries_dependency]].
- Placing [[noreturn]] at the start of a function declaration indicates that the function is not expected to return. What happens if the function returns
  despite a [[noreturn]] attribute is undefined.
- Local Variables: A name defined in a function is commonly referred to as a local name. A local variable or constant is intialized when a thread of execution
  reached its definition. Unless declared static, eacch invocation of the function has its own copy of the variable. If a local variable is declared static, a
  single, statically allocated object will be used to represent that variable in all calls of the function. It will be initialized only the first time a thread
  of execution reaches its definition. A staic local variable allows the function to preserve infromation between the calls without introducing a global
  variable that might be accessed and corrupted by other functions.
- Initialization of a static local variable does not lead to a data race unless the function is entered recursively or a deadlock occurs. The implementation
  must guard the intialization of a local static variable. The effect of initializing a local static recursively is undefined. A static local variable is
  useful for avoiding order dependencies among nonlocal variables.
- When a function is called (using the suffix(), known as the call operator or application operator), store is set aside for its formal arguments (also known
  as its parameters), and each formal argument is initialized by its corresponding actual argument. The semantics of argument passing are identical to the
  semantics of copy initialization. The type of an actual argument is checked agains the type of the corresponding formal argument, and all standard and
  user-defined type conversions are performed. Unless a formal argument is a reference, a copy of the actual argument is passed to the funciton. It is more
  efficient to pass a large object by reference than to pass it by value. The argument mught be declared a const reference to indicate that the reference is
  used for efficiency reasons only and not to enable the called function to change the value of the object. The absence of const in the declaration of a
  reference argument is taken as a statement of intent to modify the variable. Similarly, declaring a pointer argument const indicates that the value of
  an object pointed to by that argument is not changed by the function.
- Following the rules for reference initialization, a literal, a constant, and an argument that requires conversion can be passed as a "const T&" argument,
  but not as a plain (non-const) T& argument. Allowing conversions for "const T&" argument ensures that such an argument can be given exactly the same set of
  values as a T argument by passing the value in a temporary.
- Thumb rule:
    -> Use pass-by-value for small objects.
    -> Use pass-by-const-reference to pass large values that will not be modified
    -> Return a result as a return value rather than modifying an object through an argument.
    -> Use rvalue reference to implement "move" and "forwarding".
    -> Pass by a pointer if "no object" is a valid alternative.
    -> Use pass-by-reference only if required.
- If an array is used as a function argument, pointer to its initial element is passed. An argument of type T[] will be converted to a T* when passed as an
  argument. This implies that an assignment to an element of an array argument changes the value of an element of the argument array. Array is not passed by
  value. Instead, a pointer is passed (by value). A parameter of array type is equivalent to a parameter of pointer type. The size of an array is not
  available to the called function but can be passed as a second argument. It is usually preferable to pass a reference to some container, such as vector,
  array, or map.
- To pass an array, rather than a container or a pointer to the first element of an array, a parameter of type reference to array can be declared. The number
  of elements is part of a reference-to-array type. The main use of references to arrays is in templates, where the number of elements is then deduced.
- A {}-delimited list can be used as an argument to a paramter of:
    -> Type std::initializer_list<T>, where the values of the list can be implicitly converted to T.
    -> A type that can be initialized with the values provided in the list.
    -> A reference to an array of T, where the values of the list can be implicitly converted to T.
  If there is an ambiguity, an initializer_list parameter takes priority.
- For some functions, it is not possible to specify the number and type of all arguments expected in a call. To implement such interfaces, we have three
  choices:
    -> Use a variadic template.
    -> Use an initializer_list as the argument type.
    -> Terminate the argument list with the ellipsis (...), which means " and may be some more arguments." This allows to handle an arbitrary number of
       (almost) arbitrary types by using some macros from <cstdarg>
- A default argument is type checked at the time of the function declaration and evaluated at the time of the call. It may be provided for trailing arguments
  only. It can not be repeated or changed in a subsequent declaration in the same scope. Declaring a name in a nested scope so that the name hides a
  declaration of the same name in an outer scope is error-prone.
*/

#include <iostream>
#include <string>
using namespace std;
/*
struct  S
{
    [[noreturn]] virtual inline auto f(const unsigned long int * const) -> void const noexcept;
};
*/
int globe;
constexpr void bad1(int a)
{
  globe = a;
}
constexpr int bad2(int a)
{
  if (a > 0)
    return a;
  else
    return -a;
  // return (a > 0) ? a : -a;
}
constexpr int bad3(int a)
{
  int sum = 0;
  for (int i = 0; i < a; i++)
    sum += a;
  return sum;
}
// Function declarations
void swap(int *, int *);
int *next_elem();                                   // no argument; return an int*
[[noreturn]] void exit_(int);                       // int argument; return nothing and it will never return
double sqrt_(double);                               // double argument; return double
int &max(int &a, int &b, int &c);                   // Different argument names in declaration and defintion
void f(int);                                        // type is void(int)
void f(const int);                                  // type is void(int)
string to_string(int a);                            // prefix return type
auto to_string(int a) -> string;                    // suffix return type
inline int triple(int);                             // Inline Function
int f_default_args(int, int = 0, char * = nullptr); // OK
// int f_default_args(int, int = 10, char * = nullptr); // error: cannot repeat or change default arguments

// int g_default_args(int = 0, int = 0, char *);       // error
// int h_default_args(int = 0, int, char *= nullptr);  // error
extern void error(int...); // Unspecified Number of Arguments
constexpr int fac(int n)   // constant expression
{
  return (n < 2) ? 1 : n * fac(n - 1);
}
constexpr const int *addr(const int &r) { return &r; }
static const int x = 5;
constexpr const int *p1 = addr(x); // ok
constexpr int xx = *p1;            // ok
static int y;
constexpr const int *p2 = addr(y); // ok
// constexpr int yy = *p2;            // error: the value of ‘y’ is not usable in a constant expression
// constexpr const int *tp = addr(5); // error: ‘&<anonymous>’ is not a constant expression
constexpr const int *tp = addr(x);

// Reference as argumets
void m(int, int &); // Reference Arguments
void f_refarg(const int &x)
{
  // the value of the x can not be changed (except by using explicit type conversion)
}
void g_refarg(int &y); // assume that g_refarg() modifies arg
// Contant Pointers as argments
int strlen(const char *);
char *strcpy(char *to, const char *from);
char *strcmp(const char *, const char *);
int main(int argc, char const *argv[])
{
  /* code */
  int x = 5, y = 9, z = 10;
  std::cout << "Before swapping: "
            << "x = " << x << " & y = " << y << std::endl;
  swap(&x, &y);
  std::cout << "After swapping: "
            << "x = " << x << " & y = " << y << std::endl;
  std::cout << "Max: " << max(x, y, z) << std::endl;
  std::cout << "Triple of 6: " << triple(6) << std::endl;
  m(x, y); // x will not be incremented but y will be.
  std::cout << "After incrementing: "
            << "x = " << x << " & y = " << y << std::endl;
  int f_default_args(int, int = 10, char * = nullptr); // OK: this declaration hides the outer one
  constexpr int fact9 = fac(9);
  // constexpr int sum = bad3(cin.get()); /* error: call to non-constexpr function  */
  constexpr int sum = bad3(2); /* error: call to non-constexpr function */
  return 0;
}

// Function defintions
void m(int val, int &ref)
{
  ++val;
  ++ref;
}
int f1() {}            // warning/error: no return statement in function returning non-void [-Wreturn-type]
void f2() {}           // ok
int f3() { return 1; } // ok
// void f4 { return 1; } // error
// int f5() { return; } // error
void f6() { return; }     // ok
double f7() { return 1; } // 1 is implicitly converted to double{1}
inline int triple(int n)
{
  return 3 * n;
}

void search(int *a, const char *key, const int *)
{
  // no use of third argument.
}

int &max(int &x1, int &x2, int &x3)
{
  return ((x1 > x2) ? ((x1 > x3) ? x1 : x3) : ((x2 > x3) ? x2 : x3));
}

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}
