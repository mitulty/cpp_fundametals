/*
  @Author: Mitul Tyagi
  @Date:   2023-10-16 23:33:31
  @Description: Types in C++
  @Last Modified time: 2024-02-16 11:34:43
*/
/*
- Every name (identifier) in a C++ program has a type associated with it. This type determines what operations can be applied to the name and how such
  opeartions are interpreted.
- All variables use data type during declaration to restrict the type of data to be stored. Data types are used to tell the variables the type of data they
  can store. Whenever a variable is defined in C++, the compiler allocates some memory for that variable based on the data type with which it is declared.
  Every data type requires a different amount of memory.
- These can be classified as: Primitive Data Types, User-Defined Data Types and Derived Data Types.
- Primitive Data Types: These data types are built-in or predefined data types and can be used directly by the user to declare variables. Example: int, char,
  float, double, bool, void and wchar_t.
- Derived Data Types: These are derived from the primitive or built-in datatypes are referred to as Derived Data Types.Example: Array, Pointer, Reference and
  Function.
- User-Defined Data Types: These are defined by the user itself. Example: Class, Structure, Union, Enumeration and Typedef.
- The sizeof() operator is used to find the number of bytes occupied by a variable/data type in a computer memory.
- The unsigned and signed modifiers will not change the size of the type. They change the way the type will be interpreted.
- The primitive data types in C++ are:
        -> Boolean Type: A "bool" type can have one of the two values "true" or "false". It is used to express the results of logical operations.
                         Integers can be implicitly converted to bool values. Non-zero integers convert to true and 0 converts to false.
                         Also, true has the value 1 and false has the value 0 when coverted to an integer. A non-null pointer converts to true
                         and pointer with the nullptr value points to false.
        -> Character Type: A "char" variable can hold a character of the implementation's character set. These are six distinct types: char, signed char,
                           unsigned char, wchar_t, char16_t and char32_t. A char has 8-bits so that it can hold one of the 256 different values. Each character
                           has an integer value in the character set used by the implementation. Character types are integer types so that arithmetic and
                           bitwise logical operations apply. There are many character sets and character set encodings in use. The char16_t is used to store
                           16-bit character sets like UTF-16 and the char32_t is used to store 32-bit character sets like UTF-32. The wchar_t holds a larger
                           character set like Unicode. The size of wchar_t is implementation-defined. It is also implementation-defined whether a plain char
                           is a signed or an unsigned.
        -> Integer Type: These represent integer values. These can be int, signed int and unsigned int, and each of these can be long or short. By default,
                         int is signed int. Aliases like int64_t, uint_fast16_t, int_least32_t from <cstdint> can be used.
        -> Floating-Point Type: It represents floatig-pount numbers. It is an approximation of real numbers represented in a fixed amount of memory.
                                These are: float(single-precision), double(double-precision), and long double(extended-precision).
        -> Void: There are no objects of type void. It is either used to specify that a function does not return a value or as the base type for pointers
                 to objects of unkown type.
- For most applications we can use bool for logical operations , char for characters , int for integers, and double for floating-point values. The remaining
  fundamental types are variations for optimizations, special needs, and compatibility.
- limits.h header file is defined to find the range of fundamental data-types. Unsigned modifiers have minimum value is zero. So, no macro constants
  are defined for the unsigned minimum value.
- The ranges can be obtained using min(), max() and lowest() functions for all the primitive data types.
- Literal is a data that is directly represented code without going through some other variables stored in memory. It is stored directly in the binary of the
  program/code.
- There are six major categories of literals in C++: integer, character, floating-point, string, boolean, and pointer. A user-defined literal can be
  implemented by defining an operator"" at namespace scope.
- Boolean literals are "true" and "false". Any non-zero integar is boolean "true" literal and a zero integar is a boolean "false".
- C++ introduces the "nullptr" literal to specify a zero-initialized pointer. In portable code, nullptr should be used instead of integral-type zero or
  macros such as NULL.
- A character literal is a single character enclosed in single quotes. The type of a character literal is char. A character literal can be implicitly
  converted to its integer value in the character set of the machine. It is possible to enclose more than one character in a character literal('ab').
  The type of a multicharacter literal is int.
- There are five kinds of character literals:
        -> Ordinary character literals of type char, for example 'a'
        -> UTF-8 character literals of type char (char8_t in C++20), for example u8'a'
        -> Wide-character literals of type wchar_t, for example L'a'
        -> UTF-16 character literals of type char16_t, for example u'a'
        -> UTF-32 character literals of type char32_t, for example U'a'
- A sequence of octal of hexadecimal digits is terminated by the first character that is not an octal digit or a hexadecimal digit, respectively.
- A C++ program can manipulate characters sets that are much richer than the 127-character ASCII set, such as Unicode. Literals of such larger character sets
  are presented as sequences of four or eight hexadecimal digits preceded by a "U" or a "u". These are called universal character names.
- Universal character names are formed by a prefix \U followed by an eight-digit Unicode code point, or by a prefix \u followed by a four-digit Unicode code
  point. All eight or four digits, respectively, must be present to make a well-formed universal character name.
- A string literal represents a sequence of characters that together form a null-terminated string.The characters must be enclosed between double quotation
  marks.
- String literals can have no prefix, or u8, L, u, and U prefixes to denote narrow character (single-byte or multi-byte), UTF-8, wide character (UCS-2 or
  UTF-16), UTF-16 and UTF-32 encodings, respectively. A raw string literal can have R, u8R, LR, uR, and UR prefixes for the raw version equivalents of these
  encodings. To create temporary or static std::string values, string literals or raw string literals can be used  with an s suffix.
- A UTF-8 encoded string is a u8-prefixed, double-quote delimited, null-terminated array of type const char[n], where n is the length of the encoded array
  in bytes. A u8-prefixed string literal may contain any graphic character except the double quotation mark ("), backslash (\), or newline character. A
  u8-prefixe string literal may also contain the escape sequences, and any universal character name. C++11 introduces the portable char16_t (16-bit Unicode)
  and char32_t (32-bit Unicode) character types.
- A wide string literal is a null-terminated array of constant wchar_t that is prefixed by 'L' and contains any graphic character except the double quotation
  mark ("), backslash (\), or newline character. A wide string literal may contain the escape sequences and any universal character name.
- A raw string literal is a null-terminated array—of any character type—that contains any graphic character, including the double quotation mark ("),
  backslash (\), or newline character. Raw string literals are often used in regular expressions that use character classes
- String literals are different from std::string literal which are obtained using a suffix "s".
|-----------------------|-------------------------|
|  Value	              |      Escape sequence    |
|-----------------------|-------------------------|
|  newline	            |          \n             |
|-----------------------|-------------------------|
|  backslash	          |          \\             |
|-----------------------|-------------------------|
|  horizontal tab	      |          \t             |
|-----------------------|-------------------------|
|  question mark	      |          ? or \?        |
|-----------------------|-------------------------|
|  vertical tab	        |          \v             |
|-----------------------|-------------------------|
|  single quote	        |          \'             |
|-----------------------|-------------------------|
|  backspace	          |          \b             |
|-----------------------|-------------------------|
|  double quote	        |          \"             |
|-----------------------|-------------------------|
|  carriage return	    |          \r             |
|-----------------------|-------------------------|
|  the null character	  |          \0             |
|-----------------------|-------------------------|
|  form feed	          |          \f             |
|-----------------------|-------------------------|
|  octal	              |          \ooo           |
|-----------------------|-------------------------|
|  alert (bell)	        |          \a             |
|-----------------------|-------------------------|
|  hexadecimal	        |          \xhhh          |
|-----------------------|-------------------------|
- Integer literals come in three guises: decimal, octal, and hexadecimal. A literal starting with zero followed by x or X ("0x" or "0X") is a hexadecimal
  base 16) number. A literal starting with zero but not followed by x or X is an octal (base 8) number. Octal and hexadecimal notations are most useful for
  expressing bit patterns. The suffix "U" can be explicitly used for unsigned literals, suffix "L" for long integrals and suffix "UL" for unsigned long
  integrals.
- Digit separators can be used {the single-quote character (apostrophe)} to separate place values in larger numbers to make them easier for humans to read.
  Separators have no effect on compilation.
- Floating point literals specify values that must have a frational part.  They are of type double. Suffix "f" makes it a float type and suffix "L" makes it
  a long double type.
- A binary literal can be specified by the use of the 0B or 0b prefix, followed by a sequence of 1's and 0's.
|------------------------------------------------------------------------------------------------------------------------------|
|                                        Arithmetic Literal Prefixes and Suffixes                                              |
|------------------|--------------------------------|------------------------------------------|-------------------------------|
|Notation          |          *fix                  |             Meaning                      |         Example               |
|------------------|--------------------------------|------------------------------------------|-------------------------------|
|0                 |          prefix                |              octal                       |          0776                 |
|------------------|--------------------------------|------------------------------------------|-------------------------------|
|0x/0X             |          prefix                |              hexadecimal                 |          0xff                 |
|------------------|--------------------------------|------------------------------------------|-------------------------------|
|u/U               |          suffix                |              unsigned                    |          10U/12u              |
|------------------|--------------------------------|------------------------------------------|-------------------------------|
|l/L               |          suffix                |              long                        |          125l/1244546L        |
|------------------|--------------------------------|------------------------------------------|-------------------------------|
|ll/LL             |          suffix                |              long long                   |          54657ll/343646LL     |
|------------------|--------------------------------|------------------------------------------|-------------------------------|
|f/F               |          suffix                |              float                       |          345.f/123.79f        |
|------------------|--------------------------------|------------------------------------------|-------------------------------|
|L                 |          suffix                |              long double                 |          1.25L/1244.546L      |
|------------------|--------------------------------|------------------------------------------|-------------------------------|
|e/E               |          infix                 |              floating-point              |          10e-4/ 34E-3         |
|------------------|--------------------------------|------------------------------------------|-------------------------------|
|.                 |          infix                 |              floating-point              |          4.56                 |
|------------------|--------------------------------|------------------------------------------|-------------------------------|
|lu/LU             |          suffix                |              unsigned long               |          12424LU/45668lu      |
|------------------|--------------------------------|------------------------------------------|-------------------------------|
|llu/LLU           |          suffix                |              unsigned long long          |          12424LLU/45668llu    |
|------------------|--------------------------------|------------------------------------------|-------------------------------|
|'                 |          prefix                |              char                        |          'c'                  |
|------------------|--------------------------------|------------------------------------------|-------------------------------|
|u8'               |          prefix                |              char8_t                     |          u8'c'                |
|------------------|--------------------------------|------------------------------------------|-------------------------------|
|u'                |          prefix                |              char16_t                    |          u'c'                 |
|------------------|--------------------------------|------------------------------------------|-------------------------------|
|U'                |          prefix                |              char32_t                    |          U'c'                 |
|------------------|--------------------------------|------------------------------------------|-------------------------------|
|L'                |          prefix                |              wchar_t                     |          L'c'                 |
|------------------|--------------------------------|------------------------------------------|-------------------------------|
|"                 |          prefix                |              string                      |          "mess"               |
|------------------|--------------------------------|------------------------------------------|-------------------------------|
|R"                |          prefix                |              raw string                  |          R"("\b")"            |
|------------------|--------------------------------|------------------------------------------|-------------------------------|
|u8"/u8R"          |          prefix                |              UTF-8 string                |          u8"foo"/u8R"("foo")" |
|------------------|--------------------------------|------------------------------------------|-------------------------------|
|u"/uR"            |          prefix                |              UTF-16 string               |          u"foo"/uR"("foo")"   |
|------------------|--------------------------------|------------------------------------------|-------------------------------|
|U"/UR"            |          prefix                |              UTF-32 string               |          U"foo"/UR"("foo")"   |
|------------------|--------------------------------|------------------------------------------|-------------------------------|
|L"/LR"            |          prefix                |              wchar_t string              |          L"foo"/LR"("foo")"   |
|------------------|--------------------------------|------------------------------------------|-------------------------------|
|"s                |          suffix                |              std::string                 |          "foo"s/LR"("foo")"s  |
|------------------|--------------------------------|------------------------------------------|-------------------------------|
- The standard header <cstddef> defines an alias that is very widely used in both standard-library declarations and user code: size_t, it is an implementation
  defined unsigned integer type that can hold the size in bytes of every object. Consequently, it is used where we need to hold an object size.
- Similarly, <cstddef> defines the signed integer type ptrdiff_t for holding the result of subtracting two pointers to get a number of elements.
*/
#include <iostream>
#include <climits>
#include <limits>
#include <string>
#include <cstdint>

using namespace std;

void digits()
{
  std::cout << "Character Arithmetic" << std::endl;
  for (int i = 0; i < 10; i++)
  {
    std::cout << static_cast<char>('0' + i) << " ";
  }
  std::cout << std::endl;
}
int main(int argc, char const *argv[])
{
  /* code */
  std::cout << "Size of the data types (in bytes): " << std::endl;
  std::cout << "bool : " << sizeof(bool) << std::endl;
  std::cout << "signed char : " << sizeof(signed char) << std::endl;
  std::cout << "unsigned char : " << sizeof(unsigned char) << std::endl;
  std::cout << "char : " << sizeof(char) << std::endl;
  std::cout << "char8_t(in C++20 and above) : " << sizeof(char8_t) << std::endl;
  std::cout << "char16_t : " << sizeof(char16_t) << std::endl;
  std::cout << "char32_t : " << sizeof(char32_t) << std::endl;
  std::cout << "wchar_t : " << sizeof(wchar_t) << std::endl;
  std::cout << "int : " << sizeof(int) << std::endl;
  std::cout << "unsigned int : " << sizeof(unsigned int) << std::endl;
  std::cout << "short int : " << sizeof(short int) << std::endl;
  std::cout << "long int : " << sizeof(long int) << std::endl;
  std::cout << "unsigned short int : " << sizeof(unsigned short int) << std::endl;
  std::cout << "unsigned long int : " << sizeof(unsigned long int) << std::endl;
  std::cout << "long long int : " << sizeof(long long int) << std::endl;
  std::cout << "unsigned long long int : " << sizeof(unsigned long long int) << std::endl;
  std::cout << "float : " << sizeof(float) << std::endl;
  std::cout << "double : " << sizeof(double) << std::endl;
  std::cout << "long double : " << sizeof(long double) << std::endl;
  std::cout << "-------------------------------------------------------\n";
  std::cout << "Bool Lowest " << std::numeric_limits<bool>::lowest() << std::endl;
  std::cout << "Bool Min " << std::numeric_limits<bool>::min() << std::endl;
  std::cout << "Bool Max " << std::numeric_limits<bool>::max() << std::endl;
  std::cout << "Char Lowest " << static_cast<int>(std::numeric_limits<char>::lowest()) << std::endl;
  std::cout << "Char Min " << static_cast<int>(std::numeric_limits<char>::min()) << std::endl;
  std::cout << "Char Max " << static_cast<int>(std::numeric_limits<char>::max()) << std::endl;
  std::cout << "Unsigned Char Lowest " << static_cast<int>(std::numeric_limits<unsigned char>::lowest()) << std::endl;
  std::cout << "Unsigned Char Min " << static_cast<int>(std::numeric_limits<unsigned char>::min()) << std::endl;
  std::cout << "Unsigned Char Max " << static_cast<int>(std::numeric_limits<unsigned char>::max()) << std::endl;
  std::cout << "Signed Char Lowest " << static_cast<int>(std::numeric_limits<signed char>::lowest()) << std::endl;
  std::cout << "Signed Char Min " << static_cast<int>(std::numeric_limits<signed char>::min()) << std::endl;
  std::cout << "Signed Char Max " << static_cast<int>(std::numeric_limits<signed char>::max()) << std::endl;
  std::cout << "Int Lowest " << std::numeric_limits<int>::lowest() << std::endl;
  std::cout << "Int Min " << std::numeric_limits<int>::min() << std::endl;
  std::cout << "Int Max " << std::numeric_limits<int>::max() << std::endl;
  std::cout << "Unsigned Int Lowest " << std::numeric_limits<unsigned int>::lowest() << std::endl;
  std::cout << "Unsigned Int  Min " << std::numeric_limits<unsigned int>::min() << std::endl;
  std::cout << "Unsigned Int Max " << std::numeric_limits<unsigned int>::max() << std::endl;
  std::cout << "Long Int Lowest " << std::numeric_limits<long int>::lowest() << std::endl;
  std::cout << "Long Int Min " << std::numeric_limits<long int>::min() << std::endl;
  std::cout << "Long Int Max " << std::numeric_limits<long int>::max() << std::endl;
  std::cout << "Long Long Int Lowest " << std::numeric_limits<long long int>::lowest() << std::endl;
  std::cout << "Long Long Int Min " << std::numeric_limits<long long int>::min() << std::endl;
  std::cout << "Long Long Int Max " << std::numeric_limits<long long int>::max() << std::endl;
  std::cout << "Unsigned Long Int Lowest " << std::numeric_limits<unsigned long int>::lowest() << std::endl;
  std::cout << "Unsigned Long Int Min " << std::numeric_limits<unsigned long int>::min() << std::endl;
  std::cout << "Unsigned Long Int Max " << std::numeric_limits<unsigned long int>::max() << std::endl;
  std::cout << "Float Lowest " << std::numeric_limits<float>::lowest() << std::endl;
  std::cout << "Float Min " << std::numeric_limits<float>::min() << std::endl;
  std::cout << "Float Max " << std::numeric_limits<float>::max() << std::endl;
  std::cout << "Double Lowest " << std::numeric_limits<double>::lowest() << std::endl;
  std::cout << "Double Min " << std::numeric_limits<double>::min() << std::endl;
  std::cout << "Double Max " << std::numeric_limits<double>::max() << std::endl;
  std::cout << "Long Double Lowest " << std::numeric_limits<long double>::lowest() << std::endl;
  std::cout << "Long Double Min " << std::numeric_limits<long double>::min() << std::endl;
  std::cout << "Long Double Max " << std::numeric_limits<long double>::max() << std::endl;
  std::cout << "-------------------------------------------------------\n";

  std::cout << "char minimum value: " << CHAR_MIN << std::endl;
  std::cout << "char maximum value: " << CHAR_MAX << std::endl;
  std::cout << "signed char minimum value: " << SCHAR_MIN << std::endl;
  std::cout << "signed char maximum value: " << SCHAR_MAX << std::endl;
  std::cout << "unsigned char maximum value: " << UCHAR_MAX << std::endl;
  std::cout << "short int minimum value: " << SHRT_MIN << std::endl;
  std::cout << "short int maximum value: " << SHRT_MAX << std::endl;
  std::cout << "unsigned short int maximum value: " << USHRT_MAX << std::endl;
  std::cout << "int minimum value: " << INT_MIN << std::endl;
  std::cout << "int maximum value: " << INT_MAX << std::endl;
  std::cout << "unsigned int maximum value: " << UINT_MAX << std::endl;
  std::cout << "long int minimum value: " << LONG_MIN << std::endl;
  std::cout << "long int maximum value: " << LONG_MAX << std::endl;
  std::cout << "unsigned long int maximum value: " << ULONG_MAX << std::endl;
  std::cout << "long long int minimum value: " << LLONG_MIN << std::endl;
  std::cout << "long long int maximum value: " << LLONG_MAX << std::endl;
  std::cout << "unsigned long long int maximum value: " << ULLONG_MAX << std::endl;
  std::cout << "-------------------------------------------------------\n";

  { // Boolean data type

    bool l = true;
    bool m = false;
    // bool ibool {10};// This will not work due to narrowing
    bool ibool = 10;
    bool mbool{10 != 0}; // Explicit Conversion
    std::cout << "Boolean data type: " << std::endl;
    std::cout << "true: " << l << std::endl;
    std::cout << "false: " << m << std::endl;
    std::cout << "ibool: " << ibool << std::endl;
    std::cout << "mbool: " << mbool << std::endl;
    std::cout << std::boolalpha << std::endl;
    std::cout << "mbool: " << mbool << std::endl;
  }
  { // Integer data types

    int a = 10; // signed by default
    short b = 20;
    long c = 30;
    long long d = 40;
    unsigned long e = -23;

    std::cout << "Integer data types: " << std::endl;
    std::cout << "int: " << a << std::endl;
    std::cout << "short: " << b << std::endl;
    std::cout << "long: " << c << std::endl;
    std::cout << "long long: " << d << std::endl;
    std::cout << "unsigned long: " << e << std::endl;
  }
  { // Floating-point data types

    float e = 3.14f;
    double f = 3.141592;
    long double g = 3.14159265358979L;
    std::cout << "Floating-point data types: " << std::endl;
    std::cout << "float: " << e << std::endl;
    std::cout << "double: " << f << std::endl;
    std::cout << "long double: " << g << std::endl;
  }
  { // Character data types

    char h = 'a';
    wchar_t i = L'b';
    char8_t l = u8'c'; // C++20 Standard
    char16_t j = u'c';
    char32_t k = U'd';
    std::cout << "Character data types: " << std::endl;
    std::cout << "char: " << h << std::endl;
    // MTstd::cout << "wchar_t: " << i <<std::endl;
    // MTstd::cout << "char8_t: " << l <<std::endl;
    // MTstd::cout << "char16_t: " << j <<std::endl;
    // MTstd::cout << "char32_t: " << k <<std::endl;
    digits();
  }

  { // String data type

    std::string n = "Hello, world!";
    std::cout << "String data type: ";
    std::cout << n << std::endl;
    const char *s = "This is C++ Code\n";
    std::cout << s;
  }
  { // Character literals

    auto c0 = 'A';   // char
    auto c1 = u8'A'; // char, but char8_t in C++20 and after
    auto c2 = L'A';  // wchar_t
    auto c3 = u'A';  // char16_t
    auto c4 = U'A';  // char32_t
    // Multicharacter literals
    auto m0 = 'abcd'; // int, value 0x61626364
  }

  {
    // String literals
    auto s0 = "hello";   // const char*
    auto s1 = u8"hello"; // const char* before C++20, encoded as UTF-8,
                         // const char8_t* in C++20
    auto s2 = L"hello";  // const wchar_t*
    auto s3 = u"hello";  // const char16_t*, encoded as UTF-16
    auto s4 = U"hello";  // const char32_t*, encoded as UTF-32

    // Raw string literals containing unescaped \ and "
    auto R0 = R"("Hello \ world")";   // const char*
    auto R1 = u8R"("Hello \ world")"; // const char* before C++20, encoded as UTF-8,
                                      // const char8_t* in C++20
    auto R2 = LR"("Hello \ world")";  // const wchar_t*
    auto R3 = uR"("Hello \ world")";  // const char16_t*, encoded as UTF-16
    auto R4 = UR"("Hello \ world")";  // const char32_t*, encoded as UTF-32

    // Combining string literals with standard s-suffix
    auto S0 = "hello"s;   // std::string
    auto S1 = u8"hello"s; // std::string before C++20, std::u8string in C++20
    auto S2 = L"hello"s;  // std::wstring
    auto S3 = u"hello"s;  // std::u16string
    auto S4 = U"hello"s;  // std::u32string
  }
  {
    // represents the string: An unescaped \ character
    const char *raw_narrow = R"(An unescaped \  character)";
    const wchar_t *raw_wide = LR"(An unescaped \ character)";
    // const char *raw_utf8a = u8R"(An unescaped \ character)"; // Before C++20
    const char8_t *raw_utf8b = u8R"(An unescaped \ character)"; // C++20
    const char16_t *raw_utf16 = uR"(An unescaped \ character)";
    const char32_t *raw_utf32 = UR"(An unescaped \ character)";

    // Combining raw string literals with standard s-suffix
    auto S5 = R"("Hello \ world")"s;   // std::string from a raw const char*
    auto S6 = u8R"("Hello \ world")"s; // std::string from a raw const char* before C++20, encoded as UTF-8,
                                       // std::u8string in C++20
    auto S7 = LR"("Hello \ world")"s;  // std::wstring from a raw const wchar_t*
    auto S8 = uR"("Hello \ world")"s;  // std::u16string from a raw const char16_t*, encoded as UTF-16
    auto S9 = UR"("Hello \ world")"s;  // std::u32string from a raw const char32_t*, encoded as UTF-32

    auto s = R"("Hello " \ World \n ")"s;
    std::cout << s << std::endl;
  }

  { // Escape Sequences
    char newline = '\n';
    char tab = '\t';
    char backspace = '\b';
    char backslash = '\\';
    char nullChar = '\0';

    std::cout << "Newline character: " << newline << "ending" << std::endl;
    std::cout << "Tab character: " << tab << "ending" << std::endl;
    std::cout << "Backspace character: " << backspace << "ending" << std::endl;
    std::cout << "Backslash character: " << backslash << "ending" << std::endl;
    std::cout << "Null character: " << nullChar << "ending" << std::endl;
  }
  {

    char u1 = 'A';              // 'A'
    char u2 = '\101';           // octal, 'A'
    char u3 = '\x41';           // hexadecimal, 'A'
    char16_t u4{u'\u0041'};     // \u UCN 'A'
    char32_t u5{U'\U00000041'}; // \U UCN 'A'
    char u6{U'\U00000041'};     // \U UCN 'A'
    auto u7 = u'A';             // 'A'
    auto u8 = u'\101';          // octal, 'A'
    auto u9 = u'\x41';          // hexadecimal, 'A'
    auto u10{U'\U00000041'};    // \U UCN 'A'
    // char u11{U'\U0000FF41'};     // Narrowing Conversion
    char u12 = U'\U0000FF41'; // char 'A'
    char v1[] = "a\xah\129";
    char v2[] = "a\xah\127";
    char v3[] = "a\xad\127";
    char v4[] = "a\xad\0127";
    char arr[] = "a\x4e\x44\101"; // aNDA
    std::cout << "String representation using integral values" << arr << std::endl;

    std::cout << "String v1 of length: " << sizeof(v1) / sizeof(char) << std::endl;
    std::cout << "String v2 of length: " << sizeof(v2) / sizeof(char) << std::endl;
    std::cout << "String v3 of length: " << sizeof(v3) / sizeof(char) << std::endl;
    std::cout << "String v4 of length: " << sizeof(v4) / sizeof(char) << std::endl;

    int id = 157; // Decimal literal
    // int j = 0198;      // Not a decimal number; erroneous octal literal
    int kd = 0365;                              // Leading zero specifies octal literal, not decimal
    int md = 36'000'000;                        // digit separators make large values more readable
    int idd = 0377;                             // Octal literal
    int iddd = 0x3fff;                          // Hexadecimal literal
    int jd = 0X3FFF;                            // Equal to iddd
    unsigned val_1d = 328u;                     // Unsigned value
    long val_2d = 0x7FFFFFL;                    // Long value specified as hex literal
    unsigned long val_3d = 0776745ul;           // Unsigned long value
    auto val_4d = 108LL;                        // signed long long
    auto val_4dd = 0x8000000000000000ULL << 16; // unsigned long long
    long long idddd = 24'847'458'121;

    auto x = 0B001101; // binary int
    auto y = 0b000001; // binary int
  }
  {
    // Literal types : u and l combinations for unsigned and long.
    unsigned char unsigned_char{53u}; // 555U would fail because of narrowing

    // 2 Bytes
    short short_var{-32768};          //  No special literal type for short
    short int short_int{455};         //  No special literal type for short
    signed short signed_short{122ul}; // No special literal type for short
    // signed short signed_short{12345452ul};          // Narrowing Conversion
    signed short int signed_short_int{-456}; // No special literal type for short
    unsigned short int unsigned_short_int{5678U};
    unsigned short int unsigned_short_int_2 = 567678U;
    // unsigned short int unsigned_short_int_3 = {567678U}; // Narrowing Conversion
    // unsigned short int unsigned_short_int_4{567678U};    // Narrowing Conversion

    // 4 Bytes
    const int int_var{55};
    signed signed_var{66};
    signed int signed_int{77};
    unsigned int unsigned_int{555U};

    // 4 or 8 Bytes
    long long_var{88L}; // 4 OR 8 Bytes
    long int long_int{33L};
    signed long signed_long{44l};
    signed long int signed_long_int{44l};
    long long int unsigned_long_int{18446744ull};
    // long long int unsigned_long_int{18446744073709551615ull}; // Narrowing Conversion

    long long long_long{888ll}; // 8 Bytes
    long long int long_long_int{999ll};
    signed long long signed_long_long{444ll};
    signed long long int signed_long_long_int{1234ll};

    // Grouping Numbers : C++14 and onwards
    unsigned int prize{1'500'00'0u};
    std::cout << "The prize is : " << prize << std::endl;

    std::cout << " signed_long_long_int : " << signed_long_long_int << std::endl;

    // Narrowing errors
    // Possible narrowing errors are cought by the braced initializer method.
    // Assignment and functional don't catch that.
    // unsigned char distance {555u}; //Error [0~255]
    // unsigned int game_score {-20}; //Error

    // std::cout << "game_score : " << game_score << std::endl;

    // With number systems - Hex : prefix with 0x
    unsigned int hex_number{0x22BU}; // Dec 555
    int hex_number2{0x400};          // Dec 1024
    std::cout << std::hex << "The hex number is : " << hex_number << std::endl;
    std::cout << std::dec << "The hex number2 is : " << hex_number2 << std::endl;

    // Representing colors with hex
    int black_color{0xffffff};
    std::cout << "Black color is : " << std::dec << black_color << std::endl;

    // Octal literals : prefix with 0
    int octal_number{0777u}; // 511 Dec
    std::cout << "The octal number is : " << octal_number << std::endl;
    //!!BE CAREFUL NOT TO PREFIX YOUR INTEGERS WITH 0 IF YOU MEAN DEC
    int error_octal{055}; // This is not 55 in memory , it is 45 dec
    std::cout << "The erronous octal number is : " << error_octal << std::endl;

    // Binary literals
    unsigned int binary_literal{0b11111111u}; // 255 dec
    std::cout << "The binary literal is : " << binary_literal << std::endl;

    // Other literals.
    char char_literal{'c'};
    int number_literal{15};
    float fractional_literal{1.5f};
    std::string string_literal{"Hit the road"};

    std::cout << "The char literal is : " << char_literal << std::endl;
    std::cout << "The number literal is : " << number_literal << std::endl;
    std::cout << "The fractional literal is : " << fractional_literal << std::endl;
    std::cout << "The string literal is : " << string_literal << std::endl;
  }
  return 0;
}
/*
Size of following Datatypes in bytes:
 -signed char : 1
 -unsigned char : 1
 -char : 1
 -wchar_t : 4
 -int : 4
 -unsigned int : 4
 -short int : 2
 -long int : 8
 -unsigned short int : 2
 -unsigned long int : 8
 -long long int : 8
 -unsigned long long int : 8
 -float : 4
 -double : 8
 -long double : 16
Int Min -2147483648
Int Max 2147483647
Unsigned Int  Min 0
Unsigned Int Max 4294967295
Long Int Min -9223372036854775808
Long Int Max 9223372036854775807
Unsigned Long Int Min 0
Unsigned Long Int Max 18446744073709551615
char minimum value: -128
char maximum value: 127
signed char minimum value: -128
signed char maximum value: 127
unsigned char maximum value: 255
short int minimum value: -32768
short int maximum value: 32767
unsigned short int maximum value: 65535
int minimum value: -2147483648
int maximum value: 2147483647
unsigned int maximum value: 4294967295
long int minimum value: -9223372036854775808
long int maximum value: 9223372036854775807
unsigned long int maximum value: 18446744073709551615
long long int minimum value: -9223372036854775808
long long int maximum value: 9223372036854775807
unsigned long long int maximum value: 18446744073709551615
Boolean data type:
true: 1
false: 0
ibool: 1
mbool: 1
Integer data types:
int: 10
short: 20
long: 30
long long: 40
unsigned long: 18446744073709551593
Floating-point data types:
float: 3.14
double: 3.14159
long double: 3.14159
Character data types:
char: a
wchar_t: 98
char8_t: 99
char16_t: 99
char32_t: 100
Character Arithmetic
0 1 2 3 4 5 6 7 8 9
String data type: Hello, world!
This is C++ Code
"Hello " \ World \n
Newline character:
ending
Tab character: 	ending
Backspace character:  ending
Backslash character: \ending
Null character:  ending
String v1 of length: 6
String v2 of length: 5
String v3 of length: 4
String v4 of length: 5
*/
