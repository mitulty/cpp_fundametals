/*
  @Author: Mitul Tyagi
  @Date:   2024-01-29 22:31:56
  @Description: Getting Things Out of Functions
*/
/*
- Output parameters should be passed in such a way that they can be modified inside the function. Options are passing by reference or by pointer.
- Input parameters shouldn't be modifiable from inside a function. The function really needs to get input (read) from the arguments. The modification
  restrictions are done by using the const keyword. Options are passed by const reference, passing by pointer to const, or even passing by const pointer to
  const.
- std::optional is a type introduced in C++17 to help handle optional output from functions and some other things.
*/
#include <iostream>
#include <optional>
using namespace std;

// Input and Output Parameters
void max_str(const std::string &input1, const std::string input2, std::string &output)
{
  if (input1 > input2)
  {
    output = input1;
  }
  else
  {
    output = input2;
  }
}

void max_int(int input1, int input2, int &output)
{
  if (input1 > input2)
  {
    output = input1;
  }
  else
  {
    output = input2;
  }
}

void max_double(double input1, double input2, double *output)
{
  if (input1 > input2)
  {
    *output = input1;
  }
  else
  {
    *output = input2;
  }
}

// Return by Value
int sum(int a, int b)
{
  int result = a + b;
  std::cout << "In : &result(int) :  " << &result << std::endl;
  return result;
}

// Compiler Optimization to return by reference
std::string add_strings(std::string str1, std::string str2)
{
  std::string result = str1 + str2;
  std::cout << "In : &result(std::string) :  " << &result << std::endl;
  return result;
}

// Return by Reference
int &max_return_reference(int &a, int &b)
{
  if (a > b)
  {
    return a;
  }
  else
  {
    return b;
  }
}
/*
int &sum_ref(int &a, int &b)
{
  int result = a + b;
  return result; // Reference to local variable returned
}

int &max_input_by_value_copy(int a, int b)
{
  if (a > b)
  {
    return a; // Reference to local variable returned
  }
  else
  {
    return b; // Reference to local variable returned
  }
}
*/

// Return by Pointer
int *max_return_pointer(int *a, int *b)
{
  if (*a > *b)
  {
    return a;
  }
  else
  {
    return b;
  }
}
/*
int *max_input_by_value(int a, int b)
{
  if (a > b)
  {
    return &a; // Pointer to local variable returned
  }
  else
  {
    return &b; // Pointer to local variable returned
  }
}

int *sum_pointer(int *a, int *b)
{
  int result = *a + *b;
  return &result; // Pointer to local variable returned
}
*/

const double *find_max_address(const double scores[], size_t count);

auto process_number(int value)
{
  if (value < 10)
  {
    return 22; // returning int literal
  }
  else
  {
    return 55; // returning int literal
  }
}

auto process_number_2(int value)
{
  if (value < 10)
  {
    return static_cast<double>(22); // returning int literal
  }
  else
  {
    return 33.1; // returning double literal
  }
}
auto max_copy(int &a, int &b)
{
  if (a > b)
  {
    return a;
  }
  else
  {
    return b; // Will return a copy
  }
}
auto &max_reference(int &a, int &b)
{
  if (a > b)
  {
    return a;
  }
  else
  {
    return b; // Will return a true reference.
  }
}

// Definition to be available before the call for auto return type deduction
auto max(int &a, int &b)
{
  if (a > b)
  {
    return a;
  }
  else
  {
    return b; // Will return a copy.
  }
}

int find_character_v0(const std::string &str, char c)
{
  // If found , return the index, else return -1
  int not_found{-1};
  for (size_t i{}; i < str.size(); ++i)
  {
    if (str.c_str()[i] == c)
    {
      return i;
    }
  }
  return not_found;
}

void find_character_v1(const std::string &str, char c, bool &success)
{
  // If found set success to true, else set to false
  for (size_t i{}; i < str.size(); ++i)
  {
    if (str.c_str()[i] == c)
    {
      success = true;
      return;
    }
  }
  success = false;
}

std::optional<size_t> find_character_v2(const std::string &str, char c)
{
  // If found set the return index, else return an empty std::optional
  for (size_t i{}; i < str.size(); ++i)
  {
    if (str.c_str()[i] == c)
    {
      return i;
    }
  }
  return {}; // Or std::nullopt
}

// Specify default character to  search for

std::optional<size_t> find_character_v3(const std::string &str,
                                        std::optional<char> c = std::nullopt)
{
  // If found set return index, else return empty
  // If c is specified, find it else just find 'z'
  /*
  char char_to_find;
  if(c.has_value()){
      char_to_find = c.value();
  }else{
      char_to_find = 'z'; // Will find z by default
  }
  */
  char char_to_find = c.value_or('z');

  for (size_t i{}; i < str.size(); ++i)
  {
    // std::cout << "str[i] : " << str.at(i) << " , c : " << c << std::endl;
    if (str.c_str()[i] == char_to_find)
    {
      return i;
    }
  }
  return {}; // Or std::nullopt
}

int main(int argc, char const *argv[])
{
  { // Input and Output Parameters

    std::string out_str;
    std::string string1("Cassablanca");
    std::string string2("Bellevue");

    max_str(string1, string2, out_str);
    std::cout << "max_str : " << out_str << std::endl;
    int out_int;
    int in1{45};
    int in2{723};
    max_int(in1, in2, out_int);
    std::cout << "max_int : " << out_int << std::endl;

    double out_double;
    double in_double1{45.8};
    double in_double2{76.9};
    max_double(in_double1, in_double2, &out_double);
    std::cout << "max_double : " << out_double << std::endl;
    std::cout << "----------Done!------------------" << std::endl;
  }
  { // Returning From Functions By Value
    int x{15};
    int y{9};
    int result = sum(x, y);
    std::cout << "Out : &result(int) :  " << &result << std::endl;
    std::cout << "result : " << result << std::endl;

    std::string in_str1{"Hello"};
    std::string in_str2{" World!"};
    std::string result_str = add_strings(in_str1, in_str2);
    std::cout << "Out : &result_str(std::string) :  " << &result_str << std::endl;
    std::cout << "result_str : " << result_str << std::endl;
    std::cout << "----------Done!------------------" << std::endl;
  }
  { // Returning From Functions By Reference
    int x{14};
    int y{9};
    int &ref_max = max_return_reference(x, y); // Reference
    int val = max_return_reference(x, y);      // Copy

    std::cout << "ref_max : " << ref_max << std::endl;
    std::cout << "val : " << val << std::endl;
    std::cout << "x : " << x << std::endl;
    std::cout << "y : " << y << std::endl;

    ref_max++;

    std::cout << "----- " << std::endl;
    std::cout << "ref_max : " << ref_max << std::endl; // 15
    std::cout << "val : " << val << std::endl;         // 14
    std::cout << "x : " << x << std::endl;             // 15
    std::cout << "y : " << y << std::endl;             // 9

    // Results in Segmentaion Fault as references to local copy are used
    /*
    int x1{14};
    int y1{9};
    int &result1 = sum_ref(x1, y1); // Reference
    std::cout << "result : " << result1 << std::endl;

    int x2{14};
    int y2{9};
    int &result2 = max_input_by_value_copy(x2, y2); // Reference
    std::cout << "result : " << result2 << std::endl;
    */
    std::cout << "----------Done!------------------" << std::endl;
  }
  { // Returning From Functions By Pointer
    int x{56};
    int y{45};
    int *p_max = max_return_pointer(&x, &y);

    std::cout << "x : " << x << std::endl;
    std::cout << "y : " << y << std::endl;
    std::cout << "*p_max : " << *p_max << std::endl;

    ++(*p_max);

    std::cout << "-----" << std::endl;
    std::cout << "x : " << x << std::endl;
    std::cout << "y : " << y << std::endl;
    std::cout << "*p_max : " << *p_max << std::endl;

    // Results in Segmentaion Fault as pointers to local copy are used
    /*
    int x1{56};
    int y1{45};
    int *p_sum1 = sum_pointer(&x1, &y1);
    std::cout << *p_sum1 << std::endl;

    int x2{56};
    int y2{45};
    int *p_sum2 = max_input_by_value(x2, y2);
    std::cout << *p_sum2 << std::endl;
    */
    std::cout << "----------Done!------------------" << std::endl;
  }
  { // Returning Array Element Index by Pointer
    double array[]{1.0, 2.0, 3.0, 45.0, 5.0, 6.0, 7.0, 8.0, 79.0, 10.0};
    const double *p_max = find_max_address(array, std::size(array));
    std::cout << "max : " << *p_max << std::endl;
    std::cout << "----------Done!------------------" << std::endl;
  }
  { // Bare Auto Type Deduction
    // Type deduction with auto : Just a copy
    double some_variable{55.5};

    auto x = some_variable;

    std::cout << "sizeof(some_var) : " << sizeof(some_variable) << std::endl;
    std::cout << "sizeof(x) : " << sizeof(x) << std::endl;
    std::cout << "&some_var : " << &some_variable << std::endl;
    std::cout << "&x : " << &x << std::endl;
    std::cout << "some_var : " << some_variable << std::endl;
    std::cout << "x : " << x << std::endl;

    double some_var = 55.5; // double

    double &some_var_ref{some_var};

    auto y = some_var_ref; // y is not deduced as a reference to double
                           // it's just a double that contains the value
                           // in some_var_ref. constness does not matter.
    ++y;

    std::cout << "sizeof(some_var) : " << sizeof(some_var) << std::endl;         // 8
    std::cout << "sizeof(some_var_ref) : " << sizeof(some_var_ref) << std::endl; // 8
    std::cout << "sizeof(y) : " << sizeof(y) << std::endl;                       // 8
    std::cout << "&some_var : " << &some_var << std::endl;                       // 0xabc123
    std::cout << "&some_var_ref : " << &some_var_ref << std::endl;               // 0xabc123
    std::cout << "&y : " << &y << std::endl;                                     // 0xaab543
    std::cout << "some_var : " << some_var << std::endl;                         // 55.5
    std::cout << "some_var_ref : " << some_var_ref << std::endl;                 // 55.5
    std::cout << "y : " << y << std::endl;                                       // 56.5

    // True reference deduction
    double some_var1 = 55.5; // double
    double &some_var_ref1{some_var1};

    auto &z = some_var_ref1; // z is deduced as a double reference
    ++z;

    std::cout << "sizeof(some_var) : " << sizeof(some_var1) << std::endl;         // 8
    std::cout << "sizeof(some_var_ref) : " << sizeof(some_var_ref1) << std::endl; // 8
    std::cout << "sizeof(z) : " << sizeof(z) << std::endl;                        // 8
    std::cout << "&some_var : " << &some_var1 << std::endl;                       // 0xabc123
    std::cout << "&some_var_ref : " << &some_var_ref1 << std::endl;               // 0xabc123
    std::cout << "&z : " << &z << std::endl;                                      // 0xabc123
    std::cout << "some_var : " << some_var1 << std::endl;                         // 56.5
    std::cout << "some_var_ref : " << some_var_ref1 << std::endl;                 // 56.5
    std::cout << "z : " << z << std::endl;                                        // 56.5

    // Constness is preserved with properly deduced references.
    const double some_other_var{44.3};

    const double &const_ref{some_other_var};

    auto &p = const_ref;

    std::cout << "some_other_var : " << some_other_var << std::endl;
    std::cout << "const_ref : " << const_ref << std::endl;
    std::cout << "p : " << p << std::endl;

    //++p; // Compiler error
    // std::cout << "some_other_var : " << some_other_var << std::endl;
    // std::cout << "const_ref : " << const_ref << std::endl;
    // std::cout << "p : " << p << std::endl;

    // Constness doesn't matter with non reference deduction
    const double i_am_const{71.2};
    const double &my_ref{i_am_const};

    auto q = my_ref; // q is a separate variable, initialized with the
                     // value in i_am_const.
    ++q;             // Can modify q without a problem. It's a copy.
    std::cout << "----------Done!------------------" << std::endl;
  }
  { // Function Return Type Deduction
    auto result = process_number(17);
    std::cout << "result : " << result << std::endl;
    std::cout << "sizeof(result)  : " << sizeof(result) << std::endl;
    std::cout << "sizeof(int) : " << sizeof(int) << std::endl;
    std::cout << "sizeof(double) : " << sizeof(double) << std::endl;

    auto results = process_number_2(7);
    std::cout << "results : " << results << std::endl;
    std::cout << "sizeof(results)  : " << sizeof(results) << std::endl;
    std::cout << "sizeof(int) : " << sizeof(int) << std::endl;
    std::cout << "sizeof(double) : " << sizeof(double) << std::endl;
    std::cout << "----------Done!------------------" << std::endl;
  }
  { // Return Type Deduction with References
    int x{10};
    int y{45};

    // Can not treat return value as a reference. It's jut a bare separate variable with a value inside.
    // int &result = max_copy(x, y); // error: cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’

    int result = max_copy(x, y); // A copy of the max is returned

    ++result;
    std::cout << "x :" << x << std::endl;            // 10
    std::cout << "y :" << y << std::endl;            // 46
    std::cout << "result : " << result << std::endl; // 46

    int &result_ref = max_reference(x, y); // A reference to the max is returned

    ++result_ref;
    std::cout << "x :" << x << std::endl;                    // 10
    std::cout << "y :" << y << std::endl;                    // 46
    std::cout << "result_ref : " << result_ref << std::endl; // 46

    int result_ref_2 = max_reference(x, y); // A copy to the max is returned
    ++result_ref_2;
    std::cout << "x :" << x << std::endl;                        // 10
    std::cout << "y :" << y << std::endl;                        // 46
    std::cout << "result_ref_2 : " << result_ref_2 << std::endl; // 46
    std::cout << "----------Done!------------------" << std::endl;
  }

  { // Function Defintions with Return Type Deduction
    int x{5};
    int y{9};
    int int_val = max(x, y);
    std::cout << "int_val :" << int_val << std::endl;
    std::cout << "----------Done!------------------" << std::endl;
  }
  { // Optional Output from Functions
    std::string str1{"Hello World in C++20!"};
    char c{'r'};

    int index = find_character_v0(str1, c);

    if ((find_character_v0(str1, c)) != -1)
    {
      std::cout << "Found character " << c << " at index : " << index << std::endl;
    }
    else
    {
      std::cout << "Didn't find our character" << std::endl;
    }

    bool success{false};

    find_character_v1(str1, c, success);

    if (success)
    {
      std::cout << "Found character " << c << " in our string " << std::endl;
    }
    else
    {
      std::cout << "Didn't find our character" << std::endl;
    }
    std::cout << "----------Done!------------------" << std::endl;
  }
  { // std::optional
    std::optional<int> items{3};
    std::optional<std::string> name{"Daniel Gakwaya"};
    std::optional<double> weight{77.2};
    std::optional<char> character{'s'};

    // Declare and empty initialize
    std::optional<std::string> dog_name{};     // Initializes to std::nullopt
    std::optional<int> age{std::nullopt};      // std::nullopt is the null or zero equivalent for std::optional
    std::optional<char> letter = std::nullopt; // Triggers unused warning
    std::optional<double> height = {};         // Initializes to std::nullopt
                                               //  Triggers unused warning.

    // Read from an std::optional variable
    std::cout << "items : " << items.value() << std::endl;
    std::cout << "items : " << *items << std::endl; // Personaly find this confusing as it is not a pointer
                                                    // std::cout << "items : " << items << std::endl;

    std::cout << "name : " << name.value() << std::endl;
    std::cout << "weight : " << weight.value() << std::endl;
    std::cout << "character : " << character.value() << std::endl;

    // Write stuff
    dog_name = "Fluffy";
    age = 26;

    std::cout << std::endl;
    std::cout << "Writting data in ..." << std::endl;
    std::cout << "dog_name : " << dog_name.value() << std::endl;
    std::cout << "age : " << age.value() << std::endl;

    // Reading bad data
    // std::cout << letter.value() << std::endl; // Throws exception and crashes program
    // std::cout << height.value() << std::endl; // Trhows exception and crashes program

    // has_value()
    std::cout << std::boolalpha;
    std::cout << "letter.has_value() : " << letter.has_value() << std::endl;
    std::cout << "height.has_value() : " << height.has_value() << std::endl;
    std::cout << "dog_name.has_value() : " << dog_name.has_value() << std::endl;

    // Do your checks before you read data

    std::cout << std::endl;
    std::cout << "Conditional reading" << std::endl;
    if (letter.has_value())
    {
      std::cout << "letter contains a useful value" << std::endl;
    }
    else
    {
      std::cout << "letter contains std::nullopt" << std::endl;
    }

    // Checking against std::nullopt
    if (letter != std::nullopt)
    {
      std::cout << "letter contains a useful value" << std::endl;
    }
    else
    {
      std::cout << "letter contains std::nullopt" << std::endl;
    }

    // Checking against std::nullopt
    if (dog_name != std::nullopt)
    {
      std::cout << "dog_name contains a useful value : " << dog_name.value() << std::endl;
    }
    else
    {
      std::cout << "dog_name contains std::nullopt" << std::endl;
    }
    std::cout << "----------Done!------------------" << std::endl;
  }
  { // Optional Output with std::optional
    std::string str1{"Hello World in C++20!"};
    char c{'C'};

    std::optional<size_t> result = find_character_v2(str1, c);

    if (result.has_value())
    {
      std::cout << "Found our character at index : " << result.value() << std::endl;
    }
    else
    {
      std::cout << "Didn't find our character" << std::endl;
    }

    str1 = "Hello Worldz in C++20!";

    auto result1 = find_character_v3(str1, 'o'); // Will search for 'z' if you don't specify
                                                 //  the character so search for
    if (result1.has_value())
    {
      std::cout << "Found character 'o' at index " << result1.value() << std::endl;
    }
    else
    {
      std::cout << "Could not find character 'o' in the string : " << str1 << std::endl;
    }
    std::cout << "----------Done!------------------" << std::endl;
  }
  return 0;
}

// double *find_max_address(const double scores[], size_t count) : Error
const double *find_max_address(const double scores[], size_t count)
{

  size_t max_index{};
  double max{};

  for (size_t i{0}; i < count; ++i)
  {
    if (scores[i] > max)
    {
      max = scores[i];
      max_index = i;
    }
  }
  return &scores[max_index];
}
