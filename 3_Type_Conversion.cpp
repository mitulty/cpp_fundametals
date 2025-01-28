/*
  @Author: Mitul Tyagi
  @Date:   2023-10-26 23:58:05
  @Description: Type Conversion
*/
/*
- A type cast is basically a conversion from one type to another. There are two kinds of type conversion: Implicit Type Conversion and Explicit Type Conversion.
- Integral and floating-point types can be mixed freely in assignments and expressions. Whenever possible, values are converted so as not to lose information.
  Some value-destroying ("narrowing") conversions are also performed implicitly. A conversion is value-preserving if the value is converted and then convert
  the result back to it's original type and get the original value. If a conversion can not do that, it is a narrowing conversion.
- The implicit conversions that preserve values are commonly referred to as promotions. Integral promotion is used to create ints out of shorter integers types.
  Similarly, floating-point promotion is used to create doubles out of floats. These promotions will not promote to long int ( unless the operand is a char16_t,
  char32_t, wchar_t, or a plain enumeration that is already larger than an int) or long double. Promotions are used as part of the usual arithmetic conversions.
- The integral promotions are:
        -> A char, signed char, unsigned char, short int or unsigned short int is converted to an int if int can represent all the values of the soure type;
           otherwise it is converted to an unsigned int.
        -> A char16_t, chart32_t, wchar_t, or a plain enumeration type is converted to the first of the following types that can represent all the values
           of its underlying type: int, unsigned int, long, unsigned long, or unsigned long long.
        -> A bit-field is converted to an int if int can represent all the values of the the bit-field; otherwise, it is converted to unsigned int if unsigned
           int can represent all the values of the bit-field. Otherwise, no integral promotions applies to it.
        -> A bool is converted to an int; false becomes 0 and true becomes 1.
- The fundamental types can be implicitly converted into each other in a number of ways using "assignment initialization". The {}-initializer syntax prevents
  narrowing.
        -> Integral Conversions: An integer type can be converted to another integer type. A plain enumeration value can be converted to an integer type. If
                                 the destination type is unsigned, the resulting value is simply as many bits from the source as will fit in the destination
                                 (high-order bits are thrown away if necessary ). If the destination type is signed, the value is unchanged if it can be
                                 represented in the destination type; otherwise, the value is implementation-defined.
        -> Floating-Point Conversions: A floating-point value can be converted to another floating-point type. If the source value can be exactly represented
                                       in the destination type, the result is is the original numeric value. If the source value is between two adjacent values
                                       the result is one of those values. Otherwise, the behaviour is undefined.
        -> Pointer and Reference Conversions: Any pointer to an object type can be implicitly converted to a void*. A pointer (reference) to a derived class
                                              can be implicitly converted to a pointer (reference) to an accessible and unambiguous base. A pointer to
                                              function or a pointer to member cannot be implicitly conerted to a void*. A constant expression that evaluates to
                                              0 can be implicitly converted to a null pointer of any pointer type. Similarly, a constant expression that
                                              evaluates to 0 can be implicitly converted to a pointer-to-member type. A T* can be implicitly converted to
                                              a const T*. Similarly, a T& can be implicitly converted to a const T&.
        -> Boolean Conversions: Pointer, integral, and floating-point values can be implicitly converted to bool. A non-zero converts to true; a zero value
                                converts to false.
        -> Floating-Integral Conversions: When a floating value is converted to an integer value, the frational part is discarded. Conversion from a
                                          floating-point type to an integar type truncates. The behaviour is undefined if the truncated value can not be
                                          represented in the destination type. Conversions from integer to floating types are mathematically correct as the
                                          hardware allows. Loss of precision occurs if an integral value can not be represented exactly as a value of the
                                          floating type.
- To truncate in a way that is guaranteed to be portable requires the use of numeric_limits. In initializations, truncation can be avoided by using the
  {}-initializer notation.
- Usual Aritmetic Conversions: These conversions are performed on the operands of a binary operator to bring them to a common type, which is then used as the
  type of the result:
        -> If either operand is of type long double, the other is converted to long double. Otherwise, if either operand is double, the other is converted to
           double. Otherwise, if either operand is float, the other is converted to float. Otherwise integral promotions are performed on both operands.
        -> If either operand is unsigned long long, the other is converted to an unsigned long long. Otherwise, if one operand is a long long int and the
           other is an unsigned long int, then if a long long int can represent all the values of an unsigned long int, the unsigned long int is converted to
           a long long int; otherwise, both operands are converted to unsigned long long int.
        -> Otherwise, if one operand is a long int and the other is an unsigned int, then if a long int can represent all the values of an unsigned int,
           the unsigned int is converted to a long int; otherwise, both operands are converted to unsigned long int.
        -> Otherwise, if either operand is long, the other is converted to long.
        -> Otherwise, if either operand is unsigned, the other is converted to unsigned.
        -> Otherwise, both operands are int.
- Avoid mixing unsigned and signed integers. The assignment operation causes implicit conversion.
- Conversion using Cast operator: A Cast operator is an unary operator which forces one data type to be converted into another data type.
- C++ supports four types of casting:
                -> Static Cast
                -> Dynamic Cast
                -> Const Cast
                -> Reinterpret Cast
- static_cast<>() is checked by the compiler, and if the types are not compatible, compiler will throw an error.
*/
#include <iostream>
#include <climits>
#include <limits>
using namespace std;

int main(int argc, char const *argv[])
{
   {
      // unsigned char uc0 = {1023}; // narrowing conversion
      // signed char sc0 = {1023};   // narrowing conversion
      unsigned char uc = 1023; // binary 1111111111: uc becomes binary 11111111, that is, 255
      signed char sc = 1023;   // implementation-defined: Can be 127 or -1
      std::cout << "uc: " << uc << std::endl;
      std::cout << "sc: " << sc << std::endl;
      std::cout << "uc: " << static_cast<int>(uc) << std::endl;
      std::cout << "sc: " << static_cast<int>(sc) << std::endl;

      float f = __FLT_MAX__; // largest float value
      double d = f;          // OK: d = f
      std::cout << "f: " << f << std::endl;
      std::cout << "d: " << d << std::endl;

      double d2 = __DBL_MAX__; // largest double value
      float f2 = d2;           // undefined if __FLT_MAX<__DBL_MAX
      std::cout << "f2: " << f2 << std::endl;
      std::cout << "d2: " << d2 << std::endl;

      long double ld = d2; // OK:ld = d2;
      std::cout << "ld: " << ld << std::endl;

      long double ld2 = numeric_limits<long double>::max();
      double d3 = ld2; // undefined if sizeof(long double) > sizeof(double)
      std::cout << "d3: " << d3 << std::endl;
      std::cout << "ld2: " << ld2 << std::endl;

      int i = 2.7;     // i becomes 2
      char b = 2000.7; // undefined for 8-bit chars:2000 cannot be represented as an 8-bit char
      std::cout << "i: " << i << std::endl;
      std::cout << "b: " << b << std::endl;
      std::cout << "b: " << static_cast<int>(b) << std::endl;
   }
   {
      int x = 10;   // integer x
      char y = 'a'; // character c

      // y implicitly converted to int. ASCII
      // value of 'a' is 97
      x = x + y;

      // x is implicitly converted to float
      float z = x + 1.6;

      std::cout << "x = " << x << std::endl;
      std::cout << "y = " << y << std::endl;
      std::cout << "z = " << z << std::endl;
   }
   {
      double x = 1.2;

      // Explicit conversion from double to int
      int sum = (int)x + 1;

      std::cout << "Sum = " << sum << std::endl;
   }
   {
      float f = 3.5;

      // using cast operator
      int b = static_cast<int>(f);

      std::cout << "Static Cast " << f << " to int " << b << std::endl;
   }
   {
      double x{12.5};
      double y{34.6};
      int z_implicit_1 = x + y;
      int z_implicit_2{x + y};
      int z_implicit_3 = {x + y};
      int z_implicit_4{x};
      int z_explicit_1 = static_cast<int>(x) + static_cast<int>(y);
      int z_explicit_2 = static_cast<int>(x + y);
      std::cout << "Implicit Sum is: " << z_implicit_1 << std::endl;
      std::cout << "Explicit Sum 1(casting x and y individually) is: " << z_explicit_1 << std::endl;
      std::cout << "Explicit Sum 2(sum up and then cast) is: " << z_explicit_2 << std::endl;
   }
   return 0;
}
/*
uc: �
sc: �
uc: 255
sc: -1
f: 3.40282e+38
d: 3.40282e+38
f2: inf
d2: 1.79769e+308
ld: 1.79769e+308
d3: inf
ld2: 1.18973e+4932
i: 2
b: �
b: -64
x = 107
y = a
z = 108.6
Sum = 2
Static Cast 3.5 to int 3
Implicit Sum is: 47
Explicit Sum 1(casting x and y individually) is: 46
Explicit Sum 2(sum up and then cast) is: 47
*/