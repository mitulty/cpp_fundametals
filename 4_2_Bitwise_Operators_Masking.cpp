/*
  @Author: Mitul Tyagi
  @Date:   2023-12-25 21:03:51
  @Description: Bitwise Operator and Masking
  @Last Modified time: 2024-01-30 22:35:53
*/
/*
- A bit is the smallest unit of data. A computer system only understands binary language which consists of 0s and 1s. These 0s and 1s single-handedly are known
  as – ‘BIT’.
- Bitmasking is a technique used in programming to perform operations more efficiently on binary data. Bitmasking is a frequently employed technique in
  algorithms to enhance performance in terms of time complexity, utilizing bitwise operators for efficient operations at the bit level.
- Bitmasking in C++ involves manipulating individual bits of a number to achieve the desired output. It is achieved by generating a bit mask.
- Bit Toggle: If a bit is set to 0, it can be toggled to 1 and vice-versa.
- Bit Setting: If a bit is set to 0 then it’s called ‘bit is NOT set’. It can be set by performing a toggle operation and change it to 1. This is known as bit
  setting.
- Bit Clearing: If a bit is set to 1 then it’s called a ‘SET-BIT’. It can be set to 0 by performing a toggle operation. This is called a – ‘Bit-clearing’
  operation.
- Checking specific bit is on or off: A bit is said to be on if it’s 1 and off if it’s 0. For example, an integer can contain multiple bits and it can be
  checked for a specific bit to be set or not by utilizing bitwise operators.
- A bit mask is the fundamental technique to achieve bit masking. It is basically a binary pattern used to perform various bit-level operations like set,
  clear, toggle or checking if a bit is set or not. Bitmasking is done by putting a mask (hiding some unnecessary bits based on some criteria) and setting or
  clearing the remaining bits.
- To generate a mask put the bit values as 1 for the required bits and rest as 0.
            mask = ((1 << bit_pos_1) | (1 << bit_pos_2) | (1 << bit_pos_3) | ..............| (1 << bit_pos_n))
- Bitwise AND (&) – return true only if both the bits are set
- Bitwise OR (|) – returns true if either of the bits is set.
- Bitwise XOR (^) – returns true if two bits are different.
- Bitwise NOT (~) – negates the bit.
- Bitwise Left Shift (<<) – Shifts all the bits to the left by 1 place.
- Bitwise Right Shift (>>) – Shifts all the bits to the right by 1 place.
- Setting a specific bit basically means changing it from 0 to 1. It can be done by utilizing the Bitwise OR because of its property to give 1 if either of the
  bits is set to 1 and the bitwise left shift operator.
                                                            integer |= mask
- Clearing a bit means set it to 0 if it is 1 without touching or affecting any other bits. This is done by using Bitwise AND and the negation operator
  (Bitwise NOT). The Bitwise NOT flips all the bits that are 1 to 0 and 0 to 1.
                                                            integer &= ~(mask)
- In this operation, fliping of a bit is done also called togglomg the bit. If it’s set to 1 toggle it to 0 and if it’s set to 0 then toggle it to 1. This is
  easily achievable by the Bitwise XOR operator (^) and the left shift (<<). The property of the XOR operator to flip the bits if the bits of 2 different
  numbers are not the same is utilised in this operation.
                                                            integer ^= (mask)
- To check if a specific bit is set or not the bitwise AND (&) and the Left shift operators are used. If the bit is set then the answer will be 2^(bit_position)
  else 0.
                                                            integer &= (1 << bit_position_to_check)
- Bit masking have following applications :
            --> Compression: Bit masking is highly useful in case of compression that allows reducing the size of data. Ex : JPEG image stores the compression
                             parameters as bit mask.
            --> Filters on Images: Filters can be applied to the images being uploaded, what’s happening under the hood is pixels of our original image are
                                   merging with some special bits. This procedure is a mix of bit masking and bit merging.
            --> Cryptograph: It is used in cryptography to add/remove redundant bits and encrypt and decrypt the data.
            --> Optimization: It is used to optimize the algorithm making them more time and space efficient.
*/
#include <iostream>
#include "cmath"
#include <bitset>
#include <iomanip>

using namespace std;
// Highlight position for bit of interest with a 1
// Mask other positions with 0

const unsigned char mask_bit_0{0b00000001}; // Bit0
const unsigned char mask_bit_1{0b00000010}; // Bit1
const unsigned char mask_bit_2{0b00000100}; // Bit2
const unsigned char mask_bit_3{0b00001000}; // Bit3
const unsigned char mask_bit_4{0b00010000}; // Bit4
const unsigned char mask_bit_5{0b00100000}; // Bit5
const unsigned char mask_bit_6{0b01000000}; // Bit6
const unsigned char mask_bit_7{0b10000000}; // Bit7

void use_options_v0(bool flag0, bool flag1, bool flag2, bool flag3,
                    bool flag4, bool flag5, bool flag6, bool flag7)
{

  std::cout << "Flag0 is : " << flag0 << ", do something with it." << std::endl;
  std::cout << "Flag1 is : " << flag1 << ", do something with it." << std::endl;
  std::cout << "Flag2 is : " << flag2 << ", do something with it." << std::endl;
  std::cout << "Flag3 is : " << flag3 << ", do something with it." << std::endl;
  std::cout << "Flag4 is : " << flag4 << ", do something with it." << std::endl;
  std::cout << "Flag5 is : " << flag5 << ", do something with it." << std::endl;
  std::cout << "Flag6 is : " << flag6 << ", do something with it." << std::endl;
  std::cout << "Flag7 is : " << flag7 << ", do something with it." << std::endl;
}

void use_options_v1(unsigned char flags)
{

  std::cout << "bit0 is " << static_cast<bool>((flags & mask_bit_0) >> 0) << ", do something with it!" << std::endl;
  std::cout << "bit1 is " << static_cast<bool>((flags & mask_bit_1) >> 1) << ", do something with it!" << std::endl;
  std::cout << "bit2 is " << static_cast<bool>((flags & mask_bit_2) >> 2) << ", do something with it!" << std::endl;
  std::cout << "bit3 is " << static_cast<bool>((flags & mask_bit_3) >> 3) << ", do something with it!" << std::endl;
  std::cout << "bit4 is " << static_cast<bool>((flags & mask_bit_4) >> 4) << ", do something with it!" << std::endl;
  std::cout << "bit5 is " << static_cast<bool>((flags & mask_bit_5) >> 5) << ", do something with it!" << std::endl;
  std::cout << "bit6 is " << static_cast<bool>((flags & mask_bit_6) >> 6) << ", do something with it!" << std::endl;
  std::cout << "bit7 is " << static_cast<bool>((flags & mask_bit_7) >> 7) << ", do something with it!" << std::endl;
}
int main(int argc, char const *argv[])
{

  const int COLUMN_WIDTH{20};

  // Sandbox variable
  unsigned char var{0b00000000}; // Starts off all bits off

  std::cout << std::setw(COLUMN_WIDTH) << "var : "
            << std::setw(COLUMN_WIDTH) << std::bitset<8>(var) << std::endl;

  // Set a few bits : make them 1's regardless of what's in there

  // SETTING BITS
  // Setting : |= with mask of the bit

  // Set bit 1
  std::cout << "Setting bit in position 1" << std::endl;
  var |= mask_bit_1;
  std::cout << std::setw(COLUMN_WIDTH) << "var : "
            << std::setw(COLUMN_WIDTH) << std::bitset<8>(var) << std::endl;

  // Set bit 5
  std::cout << "Setting bit in position 5" << std::endl;
  var |= mask_bit_5;
  std::cout << std::setw(COLUMN_WIDTH) << "var : "
            << std::setw(COLUMN_WIDTH) << std::bitset<8>(var) << std::endl;

  // RESETTING BITS : set to 0
  // Resetting : &= (~mask)

  // Reset bit 1
  std::cout << "Resetting bit in position 1" << std::endl;
  var &= (~mask_bit_1);
  std::cout << std::setw(COLUMN_WIDTH) << "var : "
            << std::setw(COLUMN_WIDTH) << std::bitset<8>(var) << std::endl;

  // Reset bit 5
  std::cout << "Resetting bit in position 1" << std::endl;
  var &= (~mask_bit_5);
  std::cout << std::setw(COLUMN_WIDTH) << "var : "
            << std::setw(COLUMN_WIDTH) << std::bitset<8>(var) << std::endl;

  // Set all bits
  std::cout << "Setting all bits" << std::endl;
  var |= (mask_bit_0 | mask_bit_1 | mask_bit_2 | mask_bit_3 |
          mask_bit_4 | mask_bit_5 | mask_bit_6 | mask_bit_7);
  std::cout << std::setw(COLUMN_WIDTH) << "var : "
            << std::setw(COLUMN_WIDTH) << std::bitset<8>(var) << std::endl;

  // Reset bits at pos 0,2,4,6
  std::cout << "Reset bits at pos 0,2,4,6" << std::endl;
  var &= ~(mask_bit_0 | mask_bit_2 | mask_bit_4 | mask_bit_6);
  std::cout << std::setw(COLUMN_WIDTH) << "var : "
            << std::setw(COLUMN_WIDTH) << std::bitset<8>(var) << std::endl;

  // Check state of a bit
  std::cout << std::endl;
  std::cout << "Checking the state of each bit position (on/off)" << std::endl;
  std::cout << "bit0 is " << ((var & mask_bit_0) >> 0) << std::endl;
  std::cout << "bit1 is " << ((var & mask_bit_1) >> 1) << std::endl;
  std::cout << "bit2 is " << ((var & mask_bit_2) >> 2) << std::endl;
  std::cout << "bit3 is " << ((var & mask_bit_3) >> 3) << std::endl;
  std::cout << "bit4 is " << ((var & mask_bit_4) >> 4) << std::endl;
  std::cout << "bit5 is " << ((var & mask_bit_5) >> 5) << std::endl;
  std::cout << std::boolalpha;
  std::cout << "bit6 is " << ((var & mask_bit_6) >> 6) << std::endl;
  std::cout << "bit6 is " << static_cast<bool>(var & mask_bit_6) << std::endl;

  std::cout << "bit7 is " << ((var & mask_bit_7) >> 7) << std::endl;
  std::cout << "bit7 is " << static_cast<bool>(var & mask_bit_7) << std::endl;

  // Toggle bits
  // Toggle : var ^ mask

  // Toggle bit 0
  std::cout << std::endl;
  std::cout << "Toggle bit 0" << std::endl;
  var ^= mask_bit_0;
  std::cout << std::setw(COLUMN_WIDTH) << "var : "
            << std::setw(COLUMN_WIDTH) << std::bitset<8>(var) << std::endl;

  // Toggle bit7
  std::cout << "Toggle bit 7" << std::endl;
  var ^= mask_bit_7;
  std::cout << std::setw(COLUMN_WIDTH) << "var : "
            << std::setw(COLUMN_WIDTH) << std::bitset<8>(var) << std::endl;

  // Toggle multiple bits in one go : the 4 higher bits
  std::cout << "Toggle multiple bits in one go : the 4 higher bits" << std::endl;
  var ^= (mask_bit_7 | mask_bit_6 | mask_bit_5 | mask_bit_4);
  std::cout << std::setw(COLUMN_WIDTH) << "var : "
            << std::setw(COLUMN_WIDTH) << std::bitset<8>(var) << std::endl;

  {
    use_options_v0(0, 0, 1, 1, 1, 0, 1, 0);
    std::cout << "----------------------" << std::endl;
    use_options_v1(mask_bit_2 | mask_bit_3 | mask_bit_4 | mask_bit_6);
  }
  {
    const unsigned int red_mask{0xFF000000};
    const unsigned int green_mask{0x00FF0000};
    const unsigned int blue_mask{0x0000FF00};
    const unsigned int alpha_mask{0x000000FF}; // Transparency information

    unsigned int my_color{0xAABCDE00};

    // We shift to make sure the color byte of interest is in the
    //  lower index byte position so that we can interpret that as an integer,
    //  which will be between 0 and 255.

    // Set some format options
    std::cout << std::dec << std::showbase << std::endl;

    std::cout << "Red is : " << ((my_color & red_mask) >> 24) << std::endl;
    std::cout << "Green is : " << ((my_color & green_mask) >> 16) << std::endl;
    std::cout << "Blue is : " << ((my_color & blue_mask) >> 8) << std::endl;
    std::cout << "Alpha is : " << ((my_color & alpha_mask) >> 0) << std::endl;
  }
  return 0;
}
/*
              var :             00000000
Setting bit in position 1
              var :             00000010
Setting bit in position 5
              var :             00100010
Resetting bit in position 1
              var :             00100000
Resetting bit in position 1
              var :             00000000
Setting all bits
              var :             11111111
Reset bits at pos 0,2,4,6
              var :             10101010

Checking the state of each bit position (on/off)
bit0 is 0
bit1 is 1
bit2 is 0
bit3 is 1
bit4 is 0
bit5 is 1
bit6 is 0
bit6 is false
bit7 is 1
bit7 is true

Toggle bit 0
              var :             10101011
Toggle bit 7
              var :             00101011
Toggle multiple bits in one go : the 4 higher bits
              var :             11011011
Flag0 is : false, do something with it.
Flag1 is : false, do something with it.
Flag2 is : true, do something with it.
Flag3 is : true, do something with it.
Flag4 is : true, do something with it.
Flag5 is : false, do something with it.
Flag6 is : true, do something with it.
Flag7 is : false, do something with it.
---------------------------------------------------------------
bit0 is 0, do something with it!
bit1 is 0, do something with it!
bit2 is 1, do something with it!
bit3 is 1, do something with it!
bit4 is 1, do something with it!
bit5 is 0, do something with it!
bit6 is 1, do something with it!
bit7 is 0, do something with it!

Red is : 170
Green is : 188
Blue is : 222
Alpha is : 0
*/