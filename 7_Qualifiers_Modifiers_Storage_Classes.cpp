/*
  @Author: Mitul Tyagi
  @Date:   2023-10-28 16:18:11
  @Description: Play with variables
  @Last Modified time: 2023-12-29 22:13:14
*/
/*
- A type qualifier is used to refine the declaration of a variable, a function, and parameters, by specifying whether:
        -> The value of an object can be changed
        -> The value of an object must always be read from memory rather than from a register
        -> More than one pointer can access a modifiable memory address
- The const type qualifier declares an object to be nonmodifiable. The volatile type qualifier declares an item whose value can legitimately be changed by
  something beyond the control of the program in which it appears, such as a concurrently executing thread.
- const: Type specifier “const” is to define the objects of type const. A const object or variable cannot be modified once declared. If an attempt is made to
  modify const object or variable, then the compiler raises an error. It must always be initialized when it defined. They are local to a file by default. To
  share constant object among multiple files, it must be defined as an external.
- volatile: The type qualifier “volatile” means that the value of the variable marked volatile may be changed in other ways that are not specified by the
  program. The variables that are volatile change usually due to some external factors and not necessarily because of the program. In other words, they are
  volatile in nature.
- When the const and volatile keywords are used with pointers, the placement of the qualifier is critical in determining whether it is the pointer itself that
  is to be qualified, or the object to which the pointer points. For a pointer that is to be qualified as volatile or const, the keyword is put between the *
  and the identifier.
- For a pointer to a volatile or const data object, the type specifier and qualifier can be in any order, provided that the qualifier does not follow the *
  operator.
|--------------------------|----------------------------------------------------------------------------------------------------------------------------|
|Declaration               |      Description                                                                                                           |
|--------------------------|----------------------------------------------------------------------------------------------------------------------------|
|const int * ptr1;	       |    Defines a pointer to a constant integer: the value pointed to cannot be changed.                                        |
|--------------------------|----------------------------------------------------------------------------------------------------------------------------|
|int * const ptr2;	       |    Defines a constant pointer to an integer: the integer can be changed, but ptr2 cannot point to anything else.           |
|--------------------------|----------------------------------------------------------------------------------------------------------------------------|
|const int * const ptr3;   |    Defines a constant pointer to a constant integer: neither the value pointed to nor the pointer itself can be changed.   |
|--------------------------|----------------------------------------------------------------------------------------------------------------------------|
- Storage classes specify how the variable or a function is to be treated by the compiler and how storage is to be allocated for a variable. It defines the
  visibility or scope and lifetime of a variable. The lifetime of the variable is how long the variable is going to remain active. The visibility or scope of
  the variable is to which functions or modules the variable will be accessible. These storage classes are specified before the data type of variable.
        -> Auto: This is the default storage class. The storage class “Auto” is applied to the local variables and is automatically assigned by the compiler to
                 local variables. Local variables preceded by the ‘auto’ keyword remain active in the function in which they are declared and go out of scope
                 once the function exits. If the variables having an “auto” storage class are not initialized or assigned any value, then they have garbage or
                 undefined values.
        -> Extern: The extern storage class is required when the variables need to be shared across multiple files. Extern variables have global scope and
                   these variables are visible outside the file in which they are declared. As extern variables are the variables declared and defined outside
                   in another file they are not initialized. Extern variables have global scope and the lifetime of extern variables is as long as the program
                   in which it is declared as terminated.
        -> Static: The static storage class tells the compiler to maintain the value of the variable throughout the lifetime of the program. Static variables
                   are similar to the local variables but are preceded by a ‘static’ keyword. Unlike local variables which go out of scope after the function
                   exits, static variables do not go out of scope when a function or block exits, and their values are preserved between function calls. Static
                   variables are initialized and storage is allocated to them only once in the lifetime of a program. Static variables are initialized to 0 if
                   not already initialized during declaration.
        -> Register: The variables are stored in the CPU register and have a size equal to that of a register. Additionally, as these variables do not have a
                     memory location,the ‘&’ operator can not be used with these variables. Having a variable with a Register storage class does not guarantee
                     that the variable will always be stored in the register. Instead, it just assumes that the variable may be stored in a register and is
                     completely dependent on hardware and implementation. Register variables have a scope and lifetime similar to auto variables.
        -> Mutable: The mutable storage class is applied to the class objects only. By applying the mutable storage class, a member of an object can override
                    the ‘const’ member function. This means a mutable member or object can be modified by a member function which is ‘const’.
- Type Modifiers: Modifiers are used in C++ to change or give extra meaning to already existing data types. It’s added to primitive data types as a prefix to
                  change their meaning. A modifier is used to change the meaning of a basic type so that it better matches the requirements of different
                  circumstances. Following are the C++ data type modifiers: signed, unsigned, short and long.
- Constant Expressions: A constant expression is an expression whose value cannot change and that can be evaluated at compile time. A literal is a constant
                        expression. A const object that is initialized from a constant expression is also a constant expression. Whether a given object (or
                        expression) is a constant expression depends on the types and the initializers. A variable can be declared as constexpr to verify that
                        it is a constant expression. Variables declared as constexpr are implicitly const and must be intialised by constant expressions.
- The protection from const is on the variable only and not on the data in the memory. The data in the memory can be changed using pointers.
- constinit is a keyword introduced in C++20. It says that a variable should be initialized at compile time. It can only be applied to variables with static or
  thread storage duration. This, in part means outside the scope of main function.
- constinit is in place in part to help in avoiding problems with the order of intialization of global variables outside the main function.
- constinit variables must be initialized with constants or literals. const and constinit can be combined, but const and constexpr can not be combined in an
  expression. constinit desn't imply that the variable is const. It just implies that the compiler enforces intialization at compile time.
- Only one of constinit, constexpr and consteval can appear in a declaration.

*/

#include <iostream>
using namespace std;

const int val1{33};
constexpr int val2{34};
int val3{35}; // Run time value

constinit int age = 88;         // This is initialized at compile time
const constinit int age1{val1}; // const and constinit can be combined
constinit int age2{age1};       // Initializing with age would lead to a compiler error
                                // age is not const
//constinit int age3 {val3}; // Error : val3 is evaluated at run time and can't const initialize age3

const constinit double weight{33.33};
// constexpr constinit double scale_factor{3.11};// Can't combine constexpr and constinit

extern int temp;
const int buffersize = 256;           /* initialized at compile, It is a constant expression */
extern const int bufferlength = 1024; /* initialized at compile and will be available to other files, It is a constant expression */
constexpr int mf = 20;                /* constant expression */
constexpr int limit = mf + 1;         /* constant expression */
// constexpr int sz = gen_size();        /* ok only if size is a constexpr function */
// constexpr int abc = temp;          /* error: the value of ‘temp’ is not usable in a constant expression */
void printvar()
{
  static int var;
  var++;
  cout << "static variable var = " << var << endl;
}
int get_size()
{
  int x = 12;
  // std::cin >> x;
  return x;
}
int main(int argc, char const *argv[])
{
  int z = 10;
  int *volatile x0;            /* x is a volatile pointer to an int */
  int *const y0 = &z;          /* y is a const pointer to the int variable z */
  volatile int *x1;            /* x is a pointer to a volatile int  */
  int volatile *x2;            /* x is a pointer to a volatile int  */
  const int *y1;               /* y is a pointer to a const int  */
  int const *y2;               /* y is a pointer to a const int  */
  const int size = get_size(); /* intialized at run-time, It is not a constant expression */
  const int a = z;             /* intialized at compile-time, It is a constant expression */
  {
    int i;
    float f;
    cout << "Variable i = " << i << endl;
    cout << "Variable f = " << f << endl;
  }
  {
    int i;
    register float f; // warning: ISO C++17 does not allow ‘register’ storage class specifier [-Wregister]
    cout << "Variable i = " << i << endl;
    cout << "Variable f = " << f << endl;
  }
  {
    cout << "printvar call 1: ";
    printvar();
    cout << "printvar call 2: ";
    printvar();
    cout << "printvar call 3: ";
    printvar();
    cout << "printvar call 4: ";
    printvar();
  }
  {
    // constinit double height{1.72}; // Compile Error: not static or thread local storage

    std::cout << "age : " << age << std::endl;
    std::cout << "age1 : " << age1 << std::endl;
    std::cout << "age2 : " << age2 << std::endl;

    age = 33; // Can change a const init variable
    std::cout << "age : " << age << std::endl;

    // Combining const and constinit
    std::cout << "weight : " << weight << std::endl;
    // weight = 44.44; // Compiler error
  }

  return 0;
}
int temp = 0;
