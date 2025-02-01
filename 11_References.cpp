/*
  @Author: Mitul Tyagi
  @Date:   2023-09-30 11:57:20
  @Description: References
*/
/*
- A reference is an alias for an object, is usually implemented to hold a machine address of an object, an does not impose performance overhead compared to
  pointers. A reference always refers to the object to which it was initialized. The main use of reference is for specifying arguments and return values for
  functions in general and overloaded operators. There are three kinds of references: lvalue, const and rvalue.
- The lvalue reference is used to refer the object whose value is to be changed. The notation X& means "reference to X". It is used for references to lvalues.
  It must be initialized. No operator operates on a reference. The value of a reference can not be changed after intialization; it always refers to the object
  it was initialized to denote. There can not be a pointer to a reference. Also an array of references can not be defined. A reference is not an object.
- The obvious implementation of a reference is as a (constant) pointer that is dereferenced each time used.
- The initializer for a "plain" T& must be an lvalue of type T.
- The initializer for a const T& need not be an lvalue or even of type T. In such cases, first implementation type conversion to T is applied if necessary.
  Then, the resulting value is placed in a temporary variable of type T.  Finally, this temporary variable is used as the value of the initializer. A temporary
  created to hold a reference initializer persists until the end of its reference's scope.
- A reference can be used to specify a function argument so that the function can change the value of an object passed to it. References can also be used as
  return types. This is mostly used to define functions that can be used on both the left-hand and right-hand sides of an assignment.
- An rvalue reference refers to a temporary object, which the user of the reference can (and typically) modify, assuming that the object will never be used
  again. An rvalue reference can bind to an rvalue, but not an lvalue. The && declarator operator means "rvalue reference". An object referred to by an rvalue
  reference is accessed exactly like an object referred to by an lvalue reference or an ordinary variable name.
- A reference to a reference to a type gives a reference to that type which is an lvalue reference.
- Both a const lvalue reference and an rvalue reference can bind to an rvalue.
- Pointer and references are two mechanisms for referring to an object from different places in a program without copying. To use a user-defined (overloaded)
  operator on something that refers to an object, use a reference. If there is a need to change the object, use a pointer. If name has to refer to the same
  object, use a reference. To have a collection of something that refers to an object, use pointer. If the notion of "no value" is needed, pointers offer
  nullptr. There is no equivalent "null reference".
- Reference behave like constant pointers.
- A reference to const can be bounded to a nonconst object, a literal, or a more general expression.
*/
#include <iostream>

using namespace std;
int getNumber()
{
  int x;
  cout << "Enter a number: ";
  cin >> x;
  return x;
}

int main(int argc, char const *argv[])
{
  {
    int x = 5, y = 10;
    int &refVal = x; // Reference Variable (Another name for an object). All operations on a reference are done on the objects to which it is bound.
                     // Must always be initialized. Can not be bounded to other object. Remains bounded to the initial object.
    std::cout << "x: " << x << " y: " << y << std::endl;
    std::cout << "refval: " << refVal << std::endl;
    std::cout << " &x: " << &x << std::endl;
    std::cout << " &refval: " << &refVal << std::endl;
    refVal = 20;
    std::cout << "x: " << x << " y: " << y << std::endl;
    std::cout << "refval: " << refVal << std::endl;
    std::cout << " &x: " << &x << std::endl;
    std::cout << " &refval: " << &refVal << std::endl;
    std::cout << "=======================" << std::endl;

    float pi = 3.1412;
    // int &refPi = pi; This is illegal as reference type should be the type of the object it bound to.
    float &refPi = pi;
    std::cout << "pi: " << pi << " & "
              << " refPi: " << refPi << std::endl;
    int *p1 = nullptr, *p2 = NULL, *p3 = 0; // NULL Pointer Definitions
    std::cout << "=======================" << std::endl;

    // const int j = getNumber(); // Run Time Constant Initialisation
    // std::cout << j << " " << j + 1 << std::endl;

    const int jack = 12;
    // int &refConst = jack; // error: binding reference of type ‘int&’ to ‘const int’ discards qualifiers
    const int &refConst = jack; // Reference to a const
    std::cout << "jack: " << jack << std::endl;
    std::cout << "refConst: " << refConst << std::endl;
    std::cout << "&jack: " << &jack << std::endl;
    std::cout << "&refConst: " << &refConst << std::endl;
    std::cout << "=======================" << std::endl;

    // A reference to const can be bounded to a nonconst object, a literal, or a more general expression
    const int &k = 42;
    std::cout << "k: " << k << std::endl;
    std::cout << "=======================" << std::endl;

    double val = 23.15464;
    const double &refConval = val; // This is legal as the compiler internally handles the assignment process.
    std::cout << "Val: " << val << std::endl;
    std::cout << "refConval: " << refConval << std::endl;
    std::cout << "&Val: " << &val << std::endl;
    std::cout << "&refConval: " << &refConval << std::endl;
    val = 235.6; // This will change the val and refConval;
    // refConval = 23556.213425; // Error
    std::cout << "Val: " << val << std::endl;
    std::cout << "refConval: " << refConval << std::endl;
    std::cout << "&Val: " << &val << std::endl;
    std::cout << "&refConval: " << &refConval << std::endl;
    std::cout << "=======================" << std::endl;

    const int &refConvalintfromdouble = val; // This is legal as the compiler performs narrowing and the lvalue is a const reference.
    // Compiler creates a new temp variable and creates a reference to it.
    std::cout << "Val: " << val << std::endl;
    std::cout << "Val after narrowing: " << refConvalintfromdouble << std::endl;
    std::cout << "&Val: " << &val << std::endl;
    std::cout << "&refConvalintfromdouble: " << &refConvalintfromdouble << std::endl;
    // const int &refConvalintfromdoublenarrow{val}; // error: type 'double' cannot be narrowed to 'int' in initializer list
    // int &refintfromdouble = val; // Error: non-const lvalue reference to type 'int' cannot bind to a value of unrelated type 'double'
    std::cout << "=======================" << std::endl;

    double new_var_double{123.45};
    const int &ref_double_var_ic = new_var_double;
    // Concept of temp variable introduced by the compiler.
    std::cout << std::endl;
    std::cout << "new_var_double: " << new_var_double << std::endl;
    std::cout << "ref_double_var_ic: " << ref_double_var_ic << std::endl;
    std::cout << "&new_var_double: " << &new_var_double << std::endl;
    std::cout << "&ref_double_var_ic: " << &ref_double_var_ic << std::endl;
    new_var_double = 56.854;
    std::cout << "new_var_double: " << new_var_double << std::endl;
    std::cout << "ref_double_var_ic: " << ref_double_var_ic << std::endl;
    std::cout << "&new_var_double: " << &new_var_double << std::endl;
    std::cout << "&ref_double_var_ic: " << &ref_double_var_ic << std::endl;
    std::cout << "=======================" << std::endl;
  }
  { // References Basics
    int int_data{33};
    double double_data{55};

    int int_value{45};
    double double_value{33.65};

    int &reference_to_int_value_1{int_value};  // Assign through initialization
    int &reference_to_int_value_2 = int_value; // Assign through assignment
    double &reference_to_double_value_1{double_value};

    // References
    int &ref_int_data{int_data};
    double &ref_double_data{double_data};

    // Declaration and initialization should be in one statement.
    // int &some_reference; //Error

    // Print stuff out
    std::cout << "int_data : " << int_data << std::endl;
    std::cout << "&int_data : " << &int_data << std::endl;
    std::cout << "double_data : " << double_data << std::endl;
    std::cout << "&double_data : " << &double_data << std::endl;

    std::cout << "=======================" << std::endl;

    std::cout << "ref_int_data : " << ref_int_data << std::endl;
    std::cout << "&ref_int_data : " << &ref_int_data << std::endl;
    std::cout << "ref_double_data : " << ref_double_data << std::endl;
    std::cout << "&ref_double_data : " << &ref_double_data << std::endl;

    int_data = 111;
    double_data = 67.2;

    // Print stuff out
    std::cout << std::endl;
    std::cout << "int_data : " << int_data << std::endl;
    std::cout << "&int_data : " << &int_data << std::endl;
    std::cout << "double_data : " << double_data << std::endl;
    std::cout << "&double_data : " << &double_data << std::endl;

    std::cout << "=======================" << std::endl;

    std::cout << "ref_int_data : " << ref_int_data << std::endl;
    std::cout << "&ref_int_data : " << &ref_int_data << std::endl;
    std::cout << "ref_double_data : " << ref_double_data << std::endl;
    std::cout << "&ref_double_data : " << &ref_double_data << std::endl;

    ref_int_data = 1012;
    ref_double_data = 1000.45;

    // Print stuff out
    std::cout << std::endl;
    std::cout << "int_data : " << int_data << std::endl;
    std::cout << "&int_data : " << &int_data << std::endl;
    std::cout << "double_data : " << double_data << std::endl;
    std::cout << "&double_data : " << &double_data << std::endl;

    std::cout << "=======================" << std::endl;

    std::cout << "ref_int_data : " << ref_int_data << std::endl;
    std::cout << "&ref_int_data : " << &ref_int_data << std::endl;
    std::cout << "ref_double_data : " << ref_double_data << std::endl;
    std::cout << "&ref_double_data : " << &ref_double_data << std::endl;
  }
  { // References and Pointers

    // Declare pointer and reference
    double double_value{12.34};
    double &ref_double_value{double_value}; // Reference to double_value
    double *p_double_value{&double_value};  // Pointer to double_value

    // Reading
    std::cout << "double_value : " << double_value << std::endl;
    std::cout << "ref_double_value : " << ref_double_value << std::endl;
    std::cout << "p_double_value : " << p_double_value << std::endl;
    std::cout << "*p_double_value : " << *p_double_value << std::endl;

    // Writting through pointer
    *p_double_value = 15.44;

    std::cout << std::endl;
    std::cout << "double_value : " << double_value << std::endl;
    std::cout << "ref_double_value : " << ref_double_value << std::endl;
    std::cout << "p_double_value : " << p_double_value << std::endl;
    std::cout << "*p_double_value : " << *p_double_value << std::endl;

    // Writting through reference
    ref_double_value = 18.44;

    std::cout << std::endl;
    std::cout << "double_value : " << double_value << std::endl;
    std::cout << "ref_double_value : " << ref_double_value << std::endl;
    std::cout << "p_double_value : " << p_double_value << std::endl;
    std::cout << "*p_double_value : " << *p_double_value << std::endl;

    double some_other_double{78.45};

    // Make the reference reference something else. This works, but it doesn't make ref_double_value reference other_double_value, it merely
    // changes the value referenced by ref_double_value.
    ref_double_value = some_other_double;

    std::cout << "Making the reference reference something else..." << std::endl;
    std::cout << std::endl;
    std::cout << "double_value : " << double_value << std::endl;
    std::cout << "ref_double_value : " << ref_double_value << std::endl;
    std::cout << "p_double_value : " << p_double_value << std::endl;
    std::cout << "*p_double_value : " << *p_double_value << std::endl;

    // Make the pointer point to something else
    p_double_value = &some_other_double;
    std::cout << "Making the pointer point somewhere else..." << std::endl;
    std::cout << std::endl;
    std::cout << "double_value : " << double_value << std::endl;
    std::cout << "ref_double_value : " << ref_double_value << std::endl;
    std::cout << "&double_value : " << &double_value << std::endl;
    std::cout << "&ref_double_value : " << &ref_double_value << std::endl;
    std::cout << "p_double_value : " << p_double_value << std::endl;
    std::cout << "*p_double_value : " << *p_double_value << std::endl;

    *p_double_value = 555.5;

    std::cout << std::endl;
    std::cout << "double_value : " << double_value << std::endl;
    std::cout << "ref_double_value : " << ref_double_value << std::endl;
    std::cout << "&double_value : " << &double_value << std::endl;
    std::cout << "&ref_double_value : " << &ref_double_value << std::endl;
    std::cout << "p_double_value : " << p_double_value << std::endl;
    std::cout << "*p_double_value : " << *p_double_value << std::endl;
  }
  { // Reference and Const

    // Non const reference
    std::cout << std::endl;
    std::cout << "Non const reference : " << std::endl;
    int age{27};
    int &ref_age{age};

    std::cout << "age : " << age << std::endl;
    std::cout << "ref_age : " << ref_age << std::endl;

    // Can modify original variable through reference

    std::cout << std::endl;
    std::cout << "Modify original variable through reference : " << std::endl;

    ref_age++; // Mofify through reference

    std::cout << "age : " << age << std::endl;
    std::cout << "ref_age : " << ref_age << std::endl;

    // const reference
    std::cout << std::endl;
    std::cout << "Non const reference : " << std::endl;
    int age1{27}; // It can or can not be const
    const int &const_ref_age{age1};

    const int var{23}; // If variable is const then the reference has to be const.
    // int &ref_var{var}; // Error
    const int &ref_var{var};

    std::cout << "age : " << age << std::endl;
    std::cout << "ref_age : " << ref_age << std::endl;

    // Cannot modify original variable through reference
    // const_ref_age++; //Mofify through reference

    // Simulating const reference behavior with pointers
    const int *const p_age{&age};
    //*p_age = 45; // Error
  }
  { // References with Range based for loops
    int scores[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Printing positions
    std::cout << std::endl;

    std::cout << "Scores : ";
    for (auto score : scores)
    {
      std::cout << " " << score;
    }

    // This will not modify the original data
    for (auto score : scores)
    {
      score = score * 10;
    }

    std::cout << "Scores : ";
    for (auto score : scores)
    {
      std::cout << " " << score;
    }

    std::cout << std::endl;

    for (auto &score : scores)
    {
      score = score * 10;
    }

    std::cout << "After using References: ";
    // Printing after change
    std::cout << std::endl;
    std::cout << "Scores : ";
    for (auto score : scores)
    {
      std::cout << " " << score;
    }
    std::cout << std::endl;
  }
  return 0;
}
