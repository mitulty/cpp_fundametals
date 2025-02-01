/*
  @Author: Mitul Tyagi
  @Date:   2023-11-04 14:49:35
  @Description: Structure, Unions and Enumerations
*/
/*
- A structure is a sequence/aggregate of elements(called members) of arbitrary types. A structure creates a data type that can be used to group items of
  possibly different types into a single type.
- The ‘struct’ keyword is used to create a structure. The general syntax to create a structure is:
                                            struct structureName{
                                                member1;
                                                member2;
                                                member3;
                                                .
                                                .
                                                .
                                                memberN;
                                            };
  The name of the structure is structureName. The members are member1, member2, member3, …, memberN. The members can be of any data type. The name is optional.
- Structures in C++ can contain two types of members:
            -> Data Member: These members are normal C++ variables.
            -> Member Functions: These members are normal C++ functions. Along with variables, functions acn be included inside a structure declaration.
- Structure members can be initialized with declaration in C++. Structure members can also be initialized using curly braces ‘{}’.
- Structure members are accessed using dot (.) operator.
- Structure padding is the addition of some empty bytes of memory in the structure to naturally align the data members in the memory. It is done to minimize
  the CPU read cycles to retrieve different data members in the structure. Every member of the structure should be naturally aligned. The members of the
  structure are allocated sequentially in increasing order.
- The structure padding is unavoidable. There is a way to minimize padding. The programmer should declare the structure members in their increasing/decreasing
  order of size.
- Most of the compilers provide nonstandard extensions to switch off the default padding like pragmas or command line switches. In GCC, the following code can
  be used for structure packing:
                                    #pragma pack(1)
                                            or

                                    struct name {
                                        ...
                                    }__attribute__((packed));
- A structure can be passed by reference and accessed using the . (struct member access) operator. Objects of structure type can be assigned, passed as
  function arguments, and returned as the result from a function.
- An object of a struct holds its members in the order they are declared. Members are allocated in memory in declaration order. However, the size of an object
  of a struct is not necessarily the sum of the sizes of its members. This is because many machines require objects of certain types to be allocated on
  architecture-dependent boundaries or handle such objects much more efficiently if they are. On such machines, objects are said to have to be properly aligned.
  This leads to "holes" in the structures. Ordering members by size can minimize the wastage.
- The name of a type becomes available for use immediately after it has been encountered and not just after the complete declaration has been seen. However, it
  is not possible to declare new objects of a struct until its complete declarataion has been seen. The name of a struct can be used before the type is defined
  as long as that use does not require the name of a member or the size of the structure to be known. However, until the completion of the declaration of a
  struct, that struct is an incomplete type.
- It is possible to declare a struct and a non-struct with the same name in the same scope. In such cases, the plane name is the name of non-stuct and the
  struct must be referred to with the prefix struct. Similarly, the keywords class, union, and enum can be used as prefixes for disambiguation.
- A structure can have an array as an element and there can be an array of structures. Placing a built-in array in a struct allows to treat that array as an
  object: The struct can be copied in initialization (including argument passing and function return) and assignment.
- Two structs are different types even when they have the same members. Every struct must have a unique defintion in a program.
- It is possible to bundle several tiny variables together as fields in a struct. A field is often called a bit-field. A member is defined to be a field by
  specifying the number of bits it is to occupy. Unnamed fields are allowd. They do not affect the meaning of the named fields, but they can be used to make
  the layout better in some machine-dependent way.
- A union is a struct in which all the members are allocated at the same address so that the union occupies only as much space as its largest member. Naturally,
  a union can hold a value for only one member at a time. The language does not keep track of which kind of value is held by a union, so the programmer must do
  that.
- Enumeration (Enumerated type) is a user-defined data type that can be assigned some limited values. These values are defined by the programmer at the time of
  declaring the enumerated type. Enumerator types of values are also known as enumerators. It is also assigned by zero the same as the array. It can also be
  used with switch statements.
                        enum enumerated-type-name
                        {
                            value1, value2, value3…..valueN
                        };
- An enumeration is a type that can hold a set of integers values specified by the user. Some of an enumeration's possible values are named and called
  enumerators. The enumerator names are in the same scope as the enum and their values implicitly convert to integers. A plain enum can be unnamed. It is used
  when a set of integer constants is needed, rather than a type to used for variables.
*/

#include <iostream>
using namespace std;

struct Point
{
  int x = 0; // It is Considered as Default Arguments and no Error is Raised
  int y = 1;
};

struct PPN
{
  unsigned int PFN : 22; // Page Frame Number
  int : 3;               // Unused
  unsigned int CCA : 3;  // Cache Coherency Algorithm
  bool nonreachable : 1;
  bool dirty : 1;
  bool valid : 1;
  bool global : 1;
};

struct Address
{
  const char *name;
  int number;
  const char *street;
  const char *town;
  char state[2];
  const char *zip;
};

Point move(Point p, int x, int y)
{
  Point p_new = {p.x + x, p.y + y};
  return p_new;
}
union Value
{
  char *s;
  int i;
};

int main(int argc, char const *argv[])
{
  struct Point p1, p2 = {0, 1};

  // Accessing members of point p1
  // No value is Initialized then the default value is considered. ie x=0 and y=1;
  std::cout << "x = " << p1.x << ", y = " << p1.y << std::endl;

  // Initializing the value of y = 20;
  p1.y = 20;
  std::cout << "x = " << p1.x << ", y = " << p1.y << std::endl;
  // Accessing members of point p1
  p1.x = 20;
  std::cout << "x = " << p1.x << ", y = " << p1.y << std::endl;
  struct Point arr[10];

  // Access array members
  arr[0].x = 10;
  arr[0].y = 20;

  std::cout << arr[0].x << " " << arr[0].y << std::endl;
  p1 = move(p1, 2, 3);
  std::cout << "x = " << p1.x << ", y = " << p1.y << std::endl;

  // Defining enum Gender
  enum Gender
  {
    Male,
    Female
  };

  // Creating Gender type variable
  Gender gender = Male;

  switch (gender)
  {
  case Male:
    std::cout << "Gender is Male" << std::endl;
    break;
  case Female:
    std::cout << "Gender is Female" << std::endl;
    break;
  default:
    std::cout << "Value can be Male or Female" << std::endl;
  }
  return 0;
}
/*
x = 0, y = 1
x = 0, y = 20
x = 20, y = 20
10 20
x = 22, y = 23
Gender is Male
*/