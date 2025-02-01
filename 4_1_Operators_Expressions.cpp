/*
  @Author: Mitul Tyagi
  @Date:   2023-10-25 22:54:52
  @Description: Opeartors and Expressions
*/
/*
- In C++, an assignment is an expression, a function call is an expression, the construction of an object is an expression. It is an order collection of
  operators and operands which specifies a computation. An expression can contain zero or more operators and one or more operands, operands can be constants
  or variables. In addition, an expression can contain function calls as well which return constant values.
- An expression is a combination of operators, constants and variables. An expression may consist of one or more operands, and zero or more operators to
  produce a value.
- The basic units of an expression are numbers, names, and the opeartors *,/,+,- (both unary and binary), and = (assignement).
- An operator is a symbol that operates on a value to perform specific mathematical or logical computations. They form the foundation of any programming
  language. In C++, there built-in operators to provide the required functionality. These can be classified into following types:
        -> Arithmetic Operators: These operators are used to perform arithmetic or mathematical operations on the operands. These can be unary or binary.
        -> Relational Operators: These operators are used for the comparison of the values of two operands. The result returns a Boolean value, i.e., true or
                                 false.
        -> Logical Operators: These operators are used to combine two or more conditions or constraints or to complement the evaluation of the original
                              condition in consideration. The result returns a Boolean value, i.e., true or false.
        -> Bitwise Operators: These operators are used to perform bit-level operations on the operands. The operators are first converted to bit-level and
                              then the calculation is performed on the operands.
        -> Assignment Operators: These operators are used to assign value to a variable.
        -> Ternary or Conditional Opeartors: The ternary operator ? determines the answer on the basis of the evaluation of Expression1. If it is true,
                                             then Expression2 gets evaluated and is used as the answer for the expression. If Expression1 is false, then
                                             Expression3 gets evaluated and is used as the answer for the expression.
        -> sizeof Operator: This unary operator is used to compute the size of its operand or variable.
        -> Comma Operator(,): This binary operator (represented by the token) is used to evaluate its first operand and discards the result, it then evaluates
                              the second operand and returns this value (and type). It is used to combine various expressions together.
        -> (->) Operator: This operator is used to access the variables of classes or structures.
        -> Cast Operator: This unary operator is used to convert one data type into another.
        -> Dot Operator(.): This operator is used to access members of structure variables or class objects in C++.
        -> & Operator: This is a pointer operator and is used to represent the memory address of an operand.
        -> * Operator: This  is an Indirection Operator
        -> << Operator: It is called the insertion operator. It is used with std::cout to print the output.
        -> >> Operator: It is called the extraction operator. It is used with cin to get the input.
- C++ provides assignment opeartors for the binary opeartors +, -, *, /, %, &, |, ^, << and >> so that the following assignment operatorts are possible:
  =, +=, -=, /=, *=, %=, |=, &=, ^=, <<= and >>=.
- Precedence is the priority for grouping different types of operators with their operands. Associativity is the left-to-right or right-to-left order for
  grouping operands to operators that have the same precedence. Operator precedence describes how operations are performed in an arithmetic expression. It
  determines how terms are grouped in an expression and how the expression is evaluated.
- Unary operators and assignment operators are right-associative; all others are left-associative.
|------------|--------------------------------------|-------------------------------------------------------------|
|Precedence  |    Operator                          |             Description                                     |
|------------|--------------------------------------|-------------------------------------------------------------|
| 1(L->R)    |     ()                               |     Parenthesized Expression                                |
|            |     [capture-list]lambda-declarator  |     Lambda                                                  |
|------------|--------------------------------------|-------------------------------------------------------------|
| 2(L->R)    |     class-name :: member             |     Scope Resolution                                        |
|            |     namesapce-name :: member         |     Scope Resolution                                        |
|            |     :: name                          |     Global                                                  |
|------------|--------------------------------------|-------------------------------------------------------------|
| 3(L->R)    |    .                                 |     Member selection via object name                        |
|            |    ->                                |     Member selection via a pointer                          |
|------------|--------------------------------------|-------------------------------------------------------------|
| 4(L->R)    |    []                                |     Brackets (array subscript)                              |
|            |    ()                                |     Function Call                                           |
|            |    type {expr-list}                  |     Value Construction                                      |
|            |    type (expr-list)                  |     Function-Style Type Construction                        |
|            |    a++/a--                           |     Postfix increment/decrement (a is a variable)           |
|            |    typeid(type)                      |     Type Identification                                     |
|            |    typeid(expr)                      |     Run-Time Type Identification                            |
|            |    dynamic_cast<type>(expr)          |     Run-Time Checked Conversion                             |
|            |    static_cast<type>(expr)           |     Compile-Time Checked Conversion                         |
|            |    reinterpret_cast<type>(expr)      |     Unchecked Conversion                                    |
|            |    const_cast<type>(expr)            |     Const Conversion                                        |
|------------|--------------------------------------|-------------------------------------------------------------|
|            |    sizeof                            |     Determine size in bytes on this implementation          |
|            |    alignof(type)                     |     Alignment of Type                                       |
| 5(R->L)    |    ++a/--a                           |     Prefix increment/decrement (a is a variable)            |
|            |    !/~                               |     Logical negation/bitwise complement                     |
|            |    +/-                               |     Unary plus/minus                                        |
|            |    &                                 |     Address (of operand)                                    |
|            |    *                                 |     Dereference                                             |
|            |    new type                          |     Create ( allocate )                                     |
|            |    new type (expr-list)              |     Create ( allocate and initialize )                      |
|            |    new type {expr-list}              |     Create ( allocate and initialize )                      |
|            |    new (expr-list ) type             |     Create ( palce )                                        |
|            |    new (expr-list ) type (expr-list) |     Create ( palce and initialize )                         |
|            |    new (expr-list ) type {expr-list} |     Create ( palce and initialize )                         |
|            |    delete pointer                    |     Destroy ( Deallocate)                                   |
|            |    delete [] pointer                 |     Destroy Array                                           |
|            |    noexcept ( expr )                 |     Can expression throw?                                   |
|            |    ( type ) expr                     |     Cast ( type conversion )                                |
|------------|--------------------------------------|-------------------------------------------------------------|
| 6(L->R)    |    .*                                |     Member selection                                        |
|            |    ->*                               |     Member selection                                        |
|------------|--------------------------------------|-------------------------------------------------------------|
| 7(L->R)    |    *,/,%                             |     Multiplication/division/modulus                         |
|------------|--------------------------------------|-------------------------------------------------------------|
| 8(L->R)    |    +/-                               |     Addition/subtraction                                    |
|------------|--------------------------------------|-------------------------------------------------------------|
| 9(L->R)    |    << , >>                           |     Bitwise shift left, Bitwise shift right                 |
|------------|--------------------------------------|-------------------------------------------------------------|
| 10(L->R)   |    < , <=                            |     Relational (less than)/(less than or equal to)          |
|            |    > , >=                            |     Relational (greater than)/(greater than or equal to)    |
|------------|--------------------------------------|-------------------------------------------------------------|
| 11(L->R)   |    == , !=                           |     Relational (is equal to)/(is not equal to)              |
|------------|--------------------------------------|-------------------------------------------------------------|
| 12(L->R)   |    &                                 |     Bitwise AND                                             |
|------------|--------------------------------------|-------------------------------------------------------------|
| 13(L->R)   |    ^                                 |     Bitwise exclusive OR                                    |
|------------|--------------------------------------|-------------------------------------------------------------|
| 14(L->R)   |    |                                 |     Bitwise OR                                              |
|------------|--------------------------------------|-------------------------------------------------------------|
| 15(L->R)   |    &&                                |     Logical AND                                             |
|------------|--------------------------------------|-------------------------------------------------------------|
| 16(L->R)   |    ||                                |     Logical OR                                              |
|------------|--------------------------------------|-------------------------------------------------------------|
| 17(R->L)   |    ?:                                |     Ternary conditional                                     |
|------------|--------------------------------------|-------------------------------------------------------------|
|            |    {expr-list}                       |     List                                                    |
|            |    throw expr                        |     Throw Exception                                         |
| 18(R->L)   |    =                                 |     Assignment                                              |
|            |    += , -=                           |     Addition/subtraction assignment                         |
|            |    *= , /=                           |     Multiplication/division assignment                      |
|            |    %= , &=                           |     Modulus/bitwise AND assignment                          |
|            |    ^= , |=                           |     Bitwise exclusive/inclusive OR assignment               |
|            |    <<=, >>=                          |     Bitwise shift left/right assignment                     |
|------------|--------------------------------------|-------------------------------------------------------------|
| 19(L->R)   |    ,                                 |     expression separator/comma operator                     |
|------------|--------------------------------------|-------------------------------------------------------------|
- Lexical tokens are composed from characters. The longest possible sequence of characters is chosen to make a token. Whitespace characters can be token
  separators but are otherwise ignored. These are space, tab, and newline.
- The result of types of arithmetic operators are determined by a set of rules known as "the usual arithmetic conversions". The overall aim is to produce a
  result of the "largest" operand type. Operands that are smaller than an int (such as bool and char) are coverted to int before the opeartor is applied. The
  relational operators produce boolean results. If both the second and third operands of ?: are lvalues and have the same type, the result is of that type and
  is an lvalue. The result of "sizeof" is of an unsigned integral type called size_t defined in <cstddef>. The result of pointer subtraction is of a signed
  integral type called ptrdiff_t defined in <cstddef>.
- The order of evaluation of subexpressions with an expression is undefined. The operators ,(comma), &&(logical and), and ||(logical or) guarantee that their
  left-hand operand is evaluated before their right-hand operand.
- Parantheses can be used to force grouping.
- The compiler introduces an object to hold an intermediate result of an expression. Unless bound to a reference or used to initialize a named object, a
  temporary object is destroyed at the end of the full expression in which it was created. A full expression is an expression that is not a subexpression of
  some other expression.
- Integer division does not produce fractional parts. Modulus operator is performed on only integer values.
- Arithmetic operations can not be performed on integral values stored in less than 4 bytes due to processor implementation. The compiler performs promotions to
  convert the values to the int type.
- Use bitset library for binary representation of integral numbers.
- Bitwise operators are supported for integral types only. These are also not supported for integral types shorter than integers in the length. The compiler
  performs promotions to convert the values to the int type.
- Shifting right divides by 2^n and shifting left multiplies by 2^n where n is the number of digits. This rule breaks if the 1's are thrown either to the
  left or the right.
- Compound assignment work on binary operators only.
- A bitset is an array of bools but each boolean value is not stored in a separate byte instead, bitset optimizes the space such that each boolean value
  takes 1-bit space only, so space taken by bitset is less than that of an array of bool or vector of bool.
- A limitation of the bitset is that size must be known at compile time i.e. size of the bitset is fixed.
- std::bitset is the class template for bitset that is defined inside <bitset> header file. std::bitset class contains some useful member functions to work on
  the bitset objects. These are: set(), reset(), test(), flip(), count(), any(), none(), all(), size(), to_string(), to_ulong(), to _ullong(). Some of the
  basic operators are overloaded to work with bitset objects. These are: [], &, |, !, >>=, <<=, &=, |=, ^=, ~.

*/

#include <iostream>
#include "cmath"
#include <bitset>
#include <iomanip>

double hexagon_area(int a)
{

  // MTstd::cout << "Received Side Lenght: " << a << std::endl;
  double hex_area = (3 * (std::sqrt(3)) / 2) * (a * a);

  return hex_area;
}
using namespace std;

int main(int argc, char const *argv[])
{
  {
    int a = 8, b = 3;
    int sum_1{a + b};
    int sum_2(a + b);
    int sum_3 = a + b;
    std::cout << "Sum of a : " << a << " and b using direct initialisation {a+b}: " << sum_1 << std::endl;
    std::cout << "Sum of a : " << a << " and b using direct initialisation (a+b): " << sum_2 << std::endl;
    std::cout << "Sum of a : " << a << " and b using copy initialisation = a+b: " << sum_3 << std::endl;

    std::cout << "a : " << a << " and b: " << b << std::endl;
    // Addition operator
    std::cout << "a + b = " << (a + b) << std::endl;

    // Subtraction operator
    std::cout << "a - b = " << (a - b) << std::endl;

    // Multiplication operator
    std::cout << "a * b = " << (a * b) << std::endl;

    // Division operator
    std::cout << "a / b = " << (a / b) << std::endl;

    // Modulo operator
    std::cout << "a % b = " << (a % b) << std::endl;

    float div_1 = 56 / 20;          // Will generate int value
    float div_2 = 56.0 / 20;        // Will generate fractional value
    float div_3 = float(56 / 20);   // Will generate int value which will be type-casted to float
    float div_4 = (float(56) / 20); // Will generate fractional value as 56 will be type-casted to float and then division is performed

    std::cout << "3.4/2.8--> " << 3.4 / 2.8 << std::endl;
    std::cout << "(float(56/2))--> " << float(56 / 2) << std::endl;
    std::cout << "float div_1 = 56/20--> " << div_1 << std::endl;
    std::cout << "float div_2 =  56.0/20--> " << div_2 << std::endl;
    std::cout << "float div_3  = float(56/20)-->" << div_3 << std::endl;
    std::cout << "float div_4  = (float(56)/20)--> " << div_4 << std::endl;
  }
  {
    int a = 6, b = 4;
    std::cout << "a : " << a << " and b: " << b << std::endl;

    // Equal to operator
    std::cout << "a == b is " << (a == b) << std::endl;

    // Greater than operator
    std::cout << "a > b is " << (a > b) << std::endl;

    // Greater than or Equal to operator
    std::cout << "a >= b is " << (a >= b) << std::endl;

    //  Lesser than operator
    std::cout << "a < b is " << (a < b) << std::endl;

    // Lesser than or Equal to operator
    std::cout << "a <= b is " << (a <= b) << std::endl;

    // true
    std::cout << "a != b is " << (a != b) << std::endl;
  }
  {
    int a = 6, b = 4;
    std::cout << "a : " << a << " and b: " << b << std::endl;

    // Logical AND operator
    std::cout << "a && b is " << (a && b) << std::endl;

    // Logical OR operator
    std::cout << "a ! b is " << (a > b) << std::endl;

    // Logical NOT operator
    std::cout << "!b is " << (!b) << std::endl;
  }
  {
    int a = 6, b = 4;
    std::cout << "a : " << a << " and b: " << b << std::endl;

    // Binary AND operator
    std::cout << "a & b is " << (a & b) << std::endl;

    // Binary OR operator
    std::cout << "a | b is " << (a | b) << std::endl;

    // Binary XOR operator
    std::cout << "a ^ b is " << (a ^ b) << std::endl;

    // Left Shift operator
    std::cout << "a<<1 is " << (a << 1) << std::endl;

    // Right Shift operator
    std::cout << "a>>1 is " << (a >> 1) << std::endl;

    // One’s Complement operator
    std::cout << "~(a) is " << ~(a) << std::endl;
  }
  {
    int a = 6, b = 4;
    std::cout << "a : " << a << " and b: " << b << std::endl;

    // Assignment Operator
    std::cout << "a = " << a << std::endl;

    //  Add and Assignment Operator
    std::cout << "a += b is " << (a += b) << std::endl;

    // Subtract and Assignment Operator
    std::cout << "a -= b is " << (a -= b) << std::endl;

    //  Multiply and Assignment Operator
    std::cout << "a *= b is " << (a *= b) << std::endl;

    //  Divide and Assignment Operator
    std::cout << "a /= b is " << (a /= b) << std::endl;
  }
  {
    int a = 3, b = 4;
    std::cout << "a : " << a << " and b: " << b << std::endl;

    // Conditional Operator
    int result = (a < b) ? b : a;
    std::cout << "The greatest number is " << result << std::endl;
  }
  {
    int a = 6;
    int *b;
    int c;
    //  & Operator
    b = &a;

    // * Operator
    c = *b;
    std::cout << " a = " << a << std::endl;
    std::cout << " b = " << b << std::endl;
    std::cout << " c = " << c << std::endl;
  }
  {
    short int var1{10}; // 2 bytes
    short int var2{20};

    char var3{40}; // 1 bytes
    char var4{50};

    std::cout << "size of var1 : " << sizeof(var1) << " bytes" << std::endl;
    std::cout << "size of var2 : " << sizeof(var2) << " bytes" << std::endl;
    std::cout << "size of var3 : " << sizeof(var3) << " bytes" << std::endl;
    std::cout << "size of var4 : " << sizeof(var4) << " bytes" << std::endl;

    auto result1 = var1 + var2; // Type of result1 should be short int and should occupy 2 bytes but it is 4 bytes
    auto result2 = var3 + var4; // Type of result1 should be short int and should occupy 2 bytes but it is 4 bytes

    std::cout << "size of result1 : " << sizeof(result1) << " bytes" << std::endl; // 4 bytes
    std::cout << "size of result2 : " << sizeof(result2) << " bytes" << std::endl; // 4 bytes
  }

  {
    unsigned short int data{15};
    unsigned short int data_binary{0b10010001};

    std::cout << "data (dec) : " << std::showbase << std::dec << data << std::endl;
    std::cout << "data (oct) : " << std::showbase << std::oct << data << std::endl;
    std::cout << "data (hex) : " << std::showbase << std::hex << data << std::endl;
    std::cout << "data (bin) : " << std::bitset<16>(data) << std::endl;

    std::cout << "data (dec) : " << std::showbase << std::dec << data_binary << std::endl;
    std::cout << "data (oct) : " << std::showbase << std::oct << data_binary << std::endl;
    std::cout << "data (hex) : " << std::showbase << std::hex << data_binary << std::endl;
    std::cout << "data (bin) : " << std::bitset<16>(data_binary) << std::endl;
  }
  {
    // declaring an uninitialized bitset object
    bitset<8> uninitializedBitset;

    // initialization with decimal number
    bitset<8> decimalBitset(15);

    // initialization with binary string
    bitset<8> stringBitset(string("1111"));

    cout << "Uninitialized bitset: " << uninitializedBitset
         << endl;
    cout << "Initialized with decimal: " << decimalBitset
         << endl;
    cout << "Initialized with string: " << stringBitset
         << endl;
  }
  {
    int index = 0;
    // declaring few bitset objects
    bitset<4> allSet("1111"), allUnset;

    cout << "any() value: " << boolalpha << allSet.any()
         << endl;

    cout << "all() value: " << allSet.all() << endl;

    cout << "none() value: " << allSet.none() << endl;

    cout << "test() at index 0: " << noboolalpha
         << allSet.test(index) << endl;

    cout << "size() value: " << allSet.size() << endl;

    cout << "Value of allUnset on before using set(): "
         << allUnset << endl;
    allUnset.set(index);
    cout << "Value of allUnset on after using set(): "
         << allUnset << endl;

    cout << "Value of allSet on before using reset(): "
         << allSet << endl;
    allSet.reset(index);
    cout << "Value of allSet on after using reset(): "
         << allSet << endl;

    // declaring an empty string
    string bitString;
    // using to_string() method to assign value to empty
    // string
    bitString = allSet.to_string();
    cout << "bitString: " << bitString << endl;

    cout << "Unsigned Long value: " << allSet.to_ulong();
  }
  {

    bitset<4> bitset1("1001"), bitset2("1010");
    bitset<4> result;

    cout << "Bitset1: " << bitset1
         << "\nBitset2: " << bitset2 << endl;

    cout << "Accessing bit value at index 1 of bitset1: "
         << bitset1[1] << endl;

    // bitwise AND
    cout << "Bitwise AND using &: "
         << (result = bitset1 & bitset2) << endl;
    cout << "Bitwise AND using &=: " << (bitset1 &= bitset2)
         << endl;

    // bitwise OR
    bitset1 = 9; // 9 = 1001
    cout << "Bitwise OR using |: "
         << (result = bitset1 | bitset2) << endl;
    cout << "Bitwise OR using |=: " << (bitset1 |= bitset2)
         << endl;

    // bitwise NOT
    cout << "Bitwise NOT: " << (result = ~bitset1) << endl;

    // bitwise XOR
    bitset1 = 9;
    cout << "Bitwise XOR: " << (bitset1 ^= bitset2) << endl;

    bitset1 = 9;
    cout << "Binary leftshift on bitwise1: "
         << (bitset1 <<= 1) << endl;
    bitset1 = 9;
    cout << "Binary rightshift on bitwise1: "
         << (bitset1 >>= 1) << endl;
  }
  {
    std::cout << "Bit Shifting Example: " << std::endl;
    unsigned short int value{0xff0u};

    std::cout << "Size of short int " << sizeof(short int) << std::endl; //  16 bits

    std::cout << "value : " << std::bitset<16>(value)
              << ", dec : " << std::dec << value << std::endl;

    // Shift left by one bit
    value = static_cast<unsigned short int>(value << 1);
    std::cout << "value : " << std::bitset<16>(value)
              << ", dec : " << value << std::endl;

    // Shift left by one bit
    value = static_cast<unsigned short int>(value << 1);
    std::cout << "value : " << std::bitset<16>(value)
              << ", dec : " << value << std::endl;

    // Shift left by one bit
    value = static_cast<unsigned short int>(value << 1);
    std::cout << "value : " << std::bitset<16>(value)
              << ", dec : " << value << std::endl;

    // Shift left by one bit
    value = static_cast<unsigned short int>(value << 1);
    std::cout << "value : " << std::bitset<16>(value)
              << ", dec : " << value << std::endl;

    // Shift left by one bit
    value = static_cast<unsigned short int>(value << 1);
    std::cout << "value : " << std::bitset<16>(value)
              << ", dec : " << value << std::endl;

    // Shift right by one bit
    value = static_cast<unsigned short int>(value >> 1);
    std::cout << "value : " << std::bitset<16>(value)
              << ", dec : " << value << std::endl;

    // Shift by multiple bits in one go
    // Shift right by four bits
    value = static_cast<unsigned short int>(value >> 4);
    std::cout << "value : " << std::bitset<16>(value)
              << ", dec : " << value << std::endl;

    // Use paranthesis
    std::cout << "value : " << (value >> 1) << std::endl;
  }
  {
    int COLUMN_WIDTH{20};
    unsigned char value1{0x3}; // 0000 0011
    unsigned char value2{0x5}; // 0000 0101

    std::cout << std::setw(COLUMN_WIDTH) << "value1 : "
              << std::setw(COLUMN_WIDTH) << std::bitset<8>(value1) << std::endl;

    std::cout << std::setw(COLUMN_WIDTH) << "value2 : "
              << std::setw(COLUMN_WIDTH) << std::bitset<8>(value2) << std::endl;

    // AND
    std::cout << std::endl;
    std::cout << "Bitwise AND :  " << std::endl;
    std::cout << std::setw(COLUMN_WIDTH) << "value1 & value2 : "
              << std::setw(COLUMN_WIDTH) << std::bitset<8>(value1 & value2) << std::endl;
    std::cout << std::endl;

    // OR
    std::cout << std::endl;
    std::cout << "Bitwise OR :  " << std::endl;
    std::cout << std::setw(COLUMN_WIDTH) << "value1 | value2 : "
              << std::setw(COLUMN_WIDTH) << std::bitset<8>(value1 | value2) << std::endl;
    std::cout << std::endl;

    // NOT
    std::cout << std::endl;
    std::cout << "Bitwise NOT " << std::endl;

    std::cout << std::setw(COLUMN_WIDTH) << "~value1 : "
              << std::setw(COLUMN_WIDTH) << std::bitset<8>(~value1) << std::endl;

    std::cout << std::setw(COLUMN_WIDTH) << "~value2 : "
              << std::setw(COLUMN_WIDTH) << std::bitset<8>(~value2) << std::endl;

    std::cout << std::setw(COLUMN_WIDTH) << "~01011001 : "
              << std::setw(COLUMN_WIDTH) << std::bitset<8>(~0b01011001) << std::endl; // Using bin literal

    std::cout << std::setw(COLUMN_WIDTH) << "~01011001 : "
              << std::setw(COLUMN_WIDTH) << std::bitset<8>(~0x59) << std::endl; // Using hex literal
    std::cout << std::endl;

    // XOR
    std::cout << std::endl;
    std::cout << "Bitwise XOR :  " << std::endl;
    std::cout << std::setw(COLUMN_WIDTH) << "value1 ^ value2 : "
              << std::setw(COLUMN_WIDTH) << std::bitset<8>(value1 ^ value2) << std::endl;
    std::cout << std::endl;
  }
  {
    const int COLUMN_WIDTH{20};

    std::cout << std::endl;
    std::cout << "Compound bitwise assignment operators" << std::endl;

    unsigned char sandbox_var{0b00110100}; // 8 bits : positive numbers only

    // Print out initial value
    std::cout << std::endl;
    std::cout << "Initial value :  " << std::endl;
    std::cout << std::setw(COLUMN_WIDTH) << "sandbox_var : "
              << std::setw(COLUMN_WIDTH) << std::bitset<8>(sandbox_var) << std::endl;
    std::cout << std::endl;

    // Compound left shift
    std::cout << std::endl;
    std::cout << "Shift left 2 bit positions in place :  " << std::endl;
    sandbox_var <<= 2;
    std::cout << std::setw(COLUMN_WIDTH) << "sandbox_var : "
              << std::setw(COLUMN_WIDTH) << std::bitset<8>(sandbox_var) << std::endl;
    std::cout << std::endl;

    // Compound right shift
    std::cout << std::endl;
    std::cout << "Shift right 4 bit positions in place :  " << std::endl;
    sandbox_var >>= 4;
    std::cout << std::setw(COLUMN_WIDTH) << "sandbox_var : "
              << std::setw(COLUMN_WIDTH) << std::bitset<8>(sandbox_var) << std::endl;
    std::cout << std::endl;

    // Compound OR with 0000 1111 to have all lower 4 bits turned on
    std::cout << std::endl;
    std::cout << "Compound OR with 0000 1111 :  " << std::endl;
    sandbox_var |= 0b00001111;
    std::cout << std::setw(COLUMN_WIDTH) << "sandbox_var : "
              << std::setw(COLUMN_WIDTH) << std::bitset<8>(sandbox_var) << std::endl;
    std::cout << std::endl;

    // Compound AND with 0000 1100 to turn off the 2 lowest bits
    std::cout << std::endl;
    std::cout << "Compound AND with 0000 1100 :  " << std::endl;
    sandbox_var &= 0b000001100;
    std::cout << std::setw(COLUMN_WIDTH) << "sandbox_var : "
              << std::setw(COLUMN_WIDTH) << std::bitset<8>(sandbox_var) << std::endl;
    std::cout << std::endl;

    // XOR with 00000011 to invert the lower two bits
    std::cout << std::endl;
    std::cout << "Compound XOR with 0000 0011 :  " << std::endl;
    sandbox_var ^= 0b00000011;
    std::cout << std::setw(COLUMN_WIDTH) << "sandbox_var : "
              << std::setw(COLUMN_WIDTH) << std::bitset<8>(sandbox_var) << std::endl;
    std::cout << std::endl;
  }
  {
    // The comma operator combines
    // two or more  expressions into a single expression,
    //  where the value of the operation is the value of its right operand

    int increment{5};
    int number1{10};
    int number2{20};
    int number3{25};
    int result = (number1 *= ++increment, number2 - (++increment), number3 += ++increment);
    std::cout << "number1 : " << number1 << std::endl; // 60
    std::cout << "number2 : " << number2 << std::endl; // 20
    std::cout << "number3 : " << number3 << std::endl; // 33
    std::cout << "result : " << result << std::endl;   // 33
  }

  std::cout << "Area of Hexagon with side length of 6.7 is: " << hexagon_area(6.7) << std::endl;

  return 0;
}
/*
a : 8 and b: 3
a + b = 11
a - b = 5
a * b = 24
a / b = 2
a % b = 2
a : 6 and b: 4
a == b is 0
a > b is 1
a >= b is 1
a < b is 0
a <= b is 0
a != b is 1
a : 6 and b: 4
a && b is 1
a ! b is 1
!b is 0
a : 6 and b: 4
a & b is 4
a | b is 6
a ^ b is 2
a<<1 is 12
a>>1 is 3
~(a) is -7
a : 6 and b: 4
a = 6
a += b is 10
a -= b is 6
a *= b is 24
a /= b is 6
a : 3 and b: 4
The greatest number is 4
 a = 6
 b = 0x7ffe2c358f94
 c = 6
*/