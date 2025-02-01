/*
  @Author: Mitul Tyagi
  @Date:   2024-01-29 22:33:58
  @Description: Function Call Stack and Debugging
*/
/*
- Debugging is the process of running a program through some other program to make it freeze at some point. This gives the ability to then
  execute it line by line, jumping into functions, and examining the local variables in the current stack activation record.
*/
#include <iostream>

using namespace std;

int &adjust(int &input);
int sum(int x, int y);

int main(int argc, char **argv)
{

  int a{10};
  int b{12};

  int summation = sum(a, b);
  std::cout << "sum : " << summation << std::endl;

  return 0;
}

int &adjust(int &input)
{
  int adjustment{2};
  input += adjustment;
  return input;
}

int sum(int x, int y)
{

  int result = x + y;
  int ref_result;
  ref_result = adjust(result);
  return result;
}
