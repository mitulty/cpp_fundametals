/*
  @Author: Mitul Tyagi
  @Description: Declaration and Definition
*/
/*
- Before a name (identifier) can be used in a C++ program, it must be declared.
That is, its type must be specified to inform the compiler what kind of entity
the name refers to. Most of the declarations are also definitions. A definition
is a declaration that supplies all that is needed in a program for the use of an
entity. In particular, if it takes memory to represent something, that memory is
set aside by its definition.
- There must always be exactly one definition for each name in a C++ Program.
However, there can be many declarations. All declarations of an entity must
agree on its type.
- Some definitions explicitly specify a value for the entities they define. For
types, aliase, templates, functions and constants, the value is permanent. For
non-const data types, the initial value may be changed later.
- A definition has five parts(in order):
    1. Optional prefix specifiers ( e.g., static or virtual)
    2. A base type (e.g., vector<double> or const int)
    3. A declarator optionally including a name(e.g., p[7],n, or *(*)[])
    4. Optional suffix function specfiers(e.g., const or noexcept)
    5. An optional initializer or function body(e.g., = {7,5,3} or {return x;})
- Except for function and namespace definitions, a declaration is terminated by
a semicolon. A specifier is an initial keyword that specifies some non-type
attribute of what is being declared. A declarator is composed of a name and
optionally some declarator operators.
- Declarator Operators:
        1. Prefix:*(pointer), *const (constant pointer), *volatile(volatile
        pointer), & (lvalue reference), &&(rvalue reference) and auto.
        2. Postfix: [] (array), () (function) and  -> (returns from function).
- It is possible to declare several names in a single declaration. The
declaration simply contains a list of comma-separated declarations. Operations
apply to individual names only and not to any subsequent names in the same
declaration.
- A name (identifier) consists of a sequence of letters and digits. The first
character must be a letter. The underscore character(_) is considered a letter.
A C++ Keyword can not be used a name of a user-defined entity.
- Nonlocal names starting with an underscore are reserved for special facilities
in the implementation and the run-time environment and should not be used.
Similarly, names starting with a double underscore (__) or an underscore
followed by an uppercase letter are reserved.
- Uppercase and lowercase letters are distinct.
- When reading a program, the compiler always looks for the longest string of
characters that could make up a name.
- Variable is a name (identifier) given to a memory location. It is the basic
unit of storage in a program.
- A declaration introduces a name into a scope; that is, a name can be used only
in a specific part of the program text:
    1. Local Scope: A name declared in a function or lambda is termed as a local
    name. Its scope extends from its point of declaration to the end of the
    block in which its declaration occurs. A block is a section of code
    delimited by a {} pair. Function and lambda parameter names are considered
    local names in the outermost block of their function and lamda.
    2. Class Scope: A name is called a member name (or a class member name) if
    it is defined in a class outside any function, class, enum class, or other
    namespace. Its scope extends from the opening {  of the class declaration to
    the end of the class declaration.
    3. Namespace Scope: A name is called a namespace member name if it is
    defined in a namspace outside any function, lambda, class, enum class, or
    other namespace. Its scope extends from the point of declaration to the end
    of its namespace. A namespace name may also be accessible from other
    translation units.
    4. Global Scope: A name is called a global name if it is defined outside any
    function, lambda, class, enum class, or a namespace. The scope of a global
    name extends from the point of declaration to the end of the file in which
    its declaration occurs.
    5. Statement Scope: A name is in a statement scope if it is defined within
    the () part of a for, while, if, or switch statement. All names in statement
    scope are local names.
    6. Function Scope: A label is in scope from its point of declaration until
    the end of the function.
- A declaration of a name in a block can hide a declaration in an enclosing
block or a global name. That is, a name can be redefined to refer to a different
entity with in a block. After exit from the block, the name resumes its previous
meaning.
- A hidden global name can be referred to using the scope resolution operator,
:: . There is no way to use a hidden local name.
- The scope of a name that is not a class member starts at its point of
declaration, that is, after the complete declarator and before the initializer.
This implies that a name can be used to specify its own initial value. It is
possible to use a single name to refer to two different objects in a block
without using the :: operator.
- The names of function arguments and lambda arguments are considered declared
in the outermost block of a function.
- A declaration is not allowed as the only statement on the branch of an
if-statement.
- If an initializer is specified for an object, that initialiazer determines the
initial value of an object. An initializer can use one of four syntactic styles:
        X a1{v}; X a2 = {v}; X a3 = v; X a4(v);
- Initialization using {}, list initialization, does not allow narrowing. That
is an integer can not be converted to another integer that cannot holds it value
, a floating-point value can not be converted to another floating-point type
that cannot hold its value, a floating-point value cannot be converted to an
integer type and an integer value can not be coverted to a floating-point
type.
- When using auto prefer = .
- The empty initializer list, {}, is used to determine that a default value is
desired. Most types have a default value. For integral types, the default value
is a suitable representation of zero. For pointers, the default value is
nullptr. For user-defined types, the default value (if any) is defined by the
type's constructors.
- For user-defined types, there can be a distinction between direct
initialization (where implicit conversions are allowed) and copy initialization
(where they are not).
- If no initializer is specified, a global, namespace, local static, or static
member is initialized to {} of the appropriate type. Local variables and objects
created on the free store (sometimes called dynamic objects or heap objects)
are not intialized by default unless they are of user-defined types with a
default constructor.
- To initialize local variables of built-in types or objects of built-in type
created with new, use {}.
- A member of an array or a structure is default initialized if the array or
structure is.
- To use more than one value as an intializer, initializer lists delimited by {
and } are used. In some cases, function-style argument lists can also be used.
In a declaration, an empty pair of paranthesis, (), always means function.
- When using auto, a {}-list has its type deduced to std::initializer_list<T>.
auto is a placeholder for the type of the initializer.
- Braced initialization of a variable declared with a placeholder type but
without `=` requires exactly one element inside the braces. For deduction to
‘std::initializer_list’, use copy-list-initialization (i.e. add ‘=’ before the
‘{’).
- The language provides two mechanisms for deducing a type from an expression:
      1. auto for deducing a type of an object from its initializer; the type
      can be the type of a variable, a const, or a constexpr.
      2. decltype(expr) for deducing the type of something that is not a simple
      initializer, such as the return type for a function or the type of a class
      member.
- When a decalartion of a variable has an initializer, then the auto can be used
as a placeholder for the type of the initializer. The type of a homogeneous list
of elements of type T is taken to be of type initializer_list<T>.
- When using auto, there is only one type involved, the type of the intializer,
and = can be used safely.
- Different initialization methods:
      -> default: int i;
      -> value: int i{};
      -> zero: static int i;
      -> constant: const int i = some_constexpr_function();
      -> static: zero- or constant-initialization
      -> dynamic: not static initialization
      -> unordered: dynamic initialization of class template static data members
      which are not explicitly specialized
      -> ordered: dynamic initialization of other non-local variables with
      static storage duration
      -> non-trivial: when a class or aggregate is initialized by a non-trivial
      constructor
      -> direct: int i{42}; int j(42);
      -> copy: int i = 42;
      -> copy-list: int i = {42};
      -> direct-list: int i{42};
      -> list: either copy-list or direct-list
      -> aggregate: int is[3] = {0,1,2};
      -> reference: const int& i = 42; auto&& j = 42;
      -> implicit: default or value
      -> explicit: direct, copy, or list
- Initialization Terminology:
      -> Direct Initialization: Initial value passed directly.
      -> Copy Initialization: Initialize with = .
      -> Default Initialization: Object is initialized only if corresponding
      integer constructor is defined.
      -> Zero Initialization: Object initialized by (converted) 0. Used for
      global/static/thread-local objects.
      -> Value Initialization: Object always gets a value (initialized by
      constructor or zero initializer).
      -> List Initialization: Object is initialized by braces( both direct
      list-initialized or copy list-initialized). Object always gets a value
      (initialized by constructor or zero initialized).
      -> Aggregate Initialization: Special form of list initialization if type
      is aggregate.
- Variable Lifetime: The period of time in which a variable is alive in the
memory. It becomes alive when declared and it is killed from memory at some
point.
- Storage Duration: It defines how long the variable will be alive in the
memory. These are: local(block, automatic); static; dynamic.
- Variable Scope: A region in the code where a variable name can be mentioned.
*/

#include <complex>
#include <iostream>
#include <vector>
using namespace std;

// declaration and definition; means "char ch{};" so that ch becomes '0'
char ch;

// declaration and definition; means "string s{};" so that s becomes ""
std::string s;

auto count = 10; // declaration and definition

const double pi{3.1415926}; // declaration and definition

// declaration and definition; means "double z{};" so that z becomes 0.0
double z;

extern int error_number; // declaration

const char *name = "Jack"; // declaration and definition

// season is an array of character pointers
const char *season[] = {"Spring", "Summer", "Fall",
                        "Winter"}; // declaration and definition

vector<string> people{name, "Mike", "Johnson"}; // declaration and definition

struct Date {
        int d, m, y;
}; // declaration and definition

int day(Date *p) { return p->d; } // declaration and definition

double sqrt_loc(double); // declaration

template <class T> T abs(T a) {
    return a < 0 ? -a : a;
} // declaration and definition

constexpr int fac(int n) {
    return (n < 2) ? 1 : n * fac(n - 1);
} // declaration and definition

constexpr double zz{1.56 * fac(7)}; // declaration and definition

using Complex = std::complex<double>; // declaration and definition; type alias

struct User; // declaration

enum class Beer { Carlsberg, Tuborg, Thor }; // declaration and definition

namespace NS {
int a;
} // namespace NS

int x; // global x; means "int x{};" so that x becomes 0

int *ptr = &x;

int yz = 97;

int ayz = 97;

// void f5(int x)
//{
//     int x; //error
// }

void func() {
    std::cout << " In func()\n";
    int x;           // local x hides global x
    int xyz = yz;    // Global yz
    int ayz = ::ayz; // Global ayz (initialized) will be used
    int yz = yz;     // Local yz (uninitialized) will be used
    int abc = yz;    // Local yz
    x = 1;           // assign to local x
    {
        int x;   // hides first local x
        x = 2;   // assign to second local x
        ::x = 7; // assing to global x. First local x is always hidden
        cout << "Second Local x: " << x << std::endl;
        cout << "Global x: " << ::x << std::endl;
    }
    x = 3;   // assign to first local x
    ::x = 5; // assign to global x
    cout << "First Local x: " << x << std::endl;
    cout << "Global x: " << ::x << std::endl;
    cout << "Global yz var: " << ::yz << std::endl;
    cout << "Global ayz var: " << ::ayz << std::endl;
    cout << "Local yz var: " << yz << std::endl;
    cout << "Local ayz var: " << ayz << std::endl;
    cout << "Local xyz var: " << xyz << std::endl;
    cout << "Local abc var: " << yz << std::endl;
}
void f() {
    std::cout << " In f()\n";
    int count{1}; // Local Veriable. Will hide the global variable.
    std::cout << "Local Count: " << count << std::endl;
    std::cout << "Global Count: " << ::count << std::endl;
    const char *name{"Kyle"}; // name is a variable that points to a constant
    count = 2;
    name = "Lina"; //
}
void int_init() {

    // C-like initialization
    int i1;      // undefined value
    int i2 = 42; // inits with 42

    /*
      DO NOT INITIALIZE WITH ()
    */
    int i3 = (42); // inits with 42
    int i4(42);    // inits with 42
    // int i5();   // warning: empty pararanthesis were disambiguated as a
    // function declaration

    // int i6 = ()    // error
    int i7 = int();   // inits with 0
    int i8 = int(42); // inits with 42

    int i9 = {42};     // inits with 42
    int i10{42};       // inits with 42
    int i11{};         // inits with 00
    int i12 = {};      // inits with 00
    int i13_ = int{};  // inits with 00
    int i14 = int{42}; // inits with 42

    auto i15 = 42; // inits with 42

    auto i16{42};    // c++11: std::initializer_list<int>,c++17:int
    auto i17 = {42}; // std::initializer_list<int> with 42 (should not be used)
    auto i18 = int{42}; // inits with 42
    auto i19 = int{};   // inits with 0

    auto i20(42);       // inits with 42
    auto i21 = int(42); // inits with 42
    auto i22 = int();   // inits with 0
    auto i23 = (32);    // inits with 32

    auto i24 = {
        1, 2,
        3}; // Its type is standard initializer list: std::initializer_list<int>

    int i25 = (7, 9);  // init with 9(comma operator)
    auto i26 = (7, 9); // init with 9(comma operator)

    // int i27(7, 9);          // compile-time error
    // auto i28(7, 9);         // compile-time error
    // auto i29 = int(7, 9);   // compile-time error
    // auto i30;               // compile-time error: cannot deduce 'auto' type

    // auto i31{};             // compile-tine error

    // auto i32{23, 4657, 67};  // compile-time error since c++17, was
    // std::initializer_list<int> before c++17. Braced initialization of a
    // variable declared with a placeholder type but without `=` requires
    // exactly one element inside the braces

    // auto i32 = {};          // compile-tine error: can not deduce the type
    // int i33 = {1, 2, 3};    //To many initializer value
}
void f3(double val, int val2) {

    int pcz = val; // if val == 7.345,pcz becomes 7
    char c = val2; // if val2 ==1025, c becomes 1

    // int x3{val};   // error: narrowing

    // char x4{val2};   // error: narrowing

    char c4{24}; // OK:24 can be represented exactly as a char

    // char c5{264}; // error: a=narrowing conversion of '264' from 'int' to

    // 'char' int x4 {2.0}; // error: no double to int value conversion

    vector<int> v1{99}; // v1 is a vector of 1 element with the value 99

    // v2 is a vector of 99 elements each with the default value 0
    vector<int> v2(99);

    // vec1 is a vector of 1 element with the value "Hello!"
    vector<string> vec1{"Hello!!"};

    // vector<string> vec2("Hello!!"); // error: no vector constructor takes a

    // string literal
    int x4{};                  // x4 becomes 0
    double d4{};               // d4 becomes 0.0
    char *p{};                 // p becomes nullptr
    vector<int> v4{};          // v 4 becomes the empty vector
    string s4{};               // s4 becomes ""
    int *pa{new int{10}};      // *p becomes 10
    char *q{new char[1024]{}}; // q[i] becomes 0 for all i

    // = is redundant for all the below declaration,defintion and intialization
    // using {}
    int ab[] = {1, 2}; // array initializer
    struct S {
            int x;
            string s;
    };
    S s = {1, "Hola!!"};                     // struct initializer
    complex<double> z = {0, pi};             // use constructor
    vector<double> v = {0.0, 1.1, 2.2, 3.3}; // use list constructor

    complex<double> a(0, pi * 10); // use constructor

    // use constructor: v_int gets 10 elements intialized to 3
    vector<int> v_int(10, 3);

    complex<double> fz(); // function declaration

    // function-style inititializer(initialization by constructor)
    complex<double> fz1(1, 2);

    // initialization by constructor to the default value{0,0}
    complex<double> fz_1{};

    // initialization by constructor to {1,2}
    complex<double> fz1_1{1, 2};

    // m1 is an initializer_list<int>. Copy list initialization
    auto m1 = {1, 2, 3, 4};

    // m2 is an initializer_list<double>. Copy list initialization
    auto m2 = {1.0, 2.3, 4.56};

    // auto z01{1,3,4} //This will not work. For deduction to
    // ‘std::initializer_list’, use copy-list-initialization (i.e. add ‘=’
    // before the ‘{’)

    // auto m3 = {1, 2.34}; //Error: cannot deduce the type
}
int main(int argc, char const *argv[]) {
    int x, y, z;    // int x ; int y;
    int *p, t;      // int *p ; int t;
    int m, *q;      // int m; int *q;
    int v[10], *pv; // int v[10]; int *pv;
    func();
    f();
    int x1 = 0;
    char c1 = 'z';
    int xval = int(); // initialises xval to 0
    return 0;
}
extern int error_numner; // This will work as redeclaration is of the same type.

// extern float error_numner; // This will not work as redeclaration is not of
// the same type.

int error_number = 5;

// int count = 3; // This is a redefintion of count and hence will give
// compilation error.

/*
 In func()
Second Local x: 2
Global x: 7
First Local x: 3
Global x: 5
Global yz var: 97
Global ayz var: 97
Local yz var: 32767
Local ayz var: 97
Local xyz var: 97
Local abc var: 32767
 In f()
Local Count: 1
Global Count: 10
*/
