/*
  @Author: Your name
  @Date:   2024-01-28 19:07:46
  @Description: Enumm Classes
  @Last Modified time: 2024-01-28 21:43:26
*/
/*
- Implicit conversions to/from enum classes aren't allowed.
- Enum classes can't implicitly convert to/from anything, including other enum classes.
- Legacy enums implicitly transform to int, which is good for std::cout, but that introduces the problem that we can compare different enum types which is 
  very confusing.
*/
#include <iostream>
#include <string_view>
using namespace std;

// Declare an enum type
// The default type associated with enum classes with C++ is int
// unsigned char : 0 ~ 255
enum class Month : char
{
    Jan = -1,
    January = Jan,
    Feb,
    Mar,
    Apr,
    May,
    Jun,
    Jul,
    Aug,
    Sep,
    Oct = 100,
    Nov,
    Dec,
};
enum Direction : unsigned char
{
    TopLeft = 64,
    TopRight,
    Center,
    BottomLeft,
    BottomRight
};

enum Tool
{
    Pen,
    Marker,
    Eraser,
    Rectangle,
    Circle,
    PaintBucket
};
std::string_view month_to_string(Month month)
{
    switch (month)
    {
        /*
        case Month::Jan : return "January";
        case Month::Feb : return "February";
        case Month::Mar : return "March";
        case Month::Apr : return "April";
        case Month::May : return "May";
        case Month::Jun : return "June";
        case Month::Jul : return "July";
        case Month::Aug : return "August";
        case Month::Sep : return "September";
        case Month::Oct : return "October";
        case Month::Nov : return "November";
        case Month::Dec : return "December";
        default : return "None";
        */
        using enum Month;
    case Jan:
        return "January";
    case Feb:
        return "February";
    case Mar:
        return "March";
    case Apr:
        return "April";
    case May:
        return "May";
    case Jun:
        return "June";
    case Jul:
        return "July";
    case Aug:
        return "August";
    case Sep:
        return "September";
    case Oct:
        return "October";
    case Nov:
        return "November";
    case Dec:
        return "December";
    default:
        return "None";
    }
}
int main(int argc, char const *argv[])
{
    Month month{Month::Jan};
    std::cout << "month : " << static_cast<int>(month) << std::endl;
    std::cout << "sizeof(month) : " << sizeof(month) << std::endl;

    Month month_2{Month::Apr};
    std::cout << "month : " << month_to_string(month_2) << std::endl;

    Direction direction{Direction::TopLeft};
    Tool tool{Tool::Pen};

    std::cout << "direction : " << static_cast<unsigned int>(direction) << std::endl;
    std::cout << "tool : " << tool << std::endl;
    // std::cout << "(tool > direction) : " << (tool > direction) << std::endl;

    using HugeInt = unsigned long long int; // Recommended in modern C++
    // typedef unsigned long long int HugeInt; // Older C++ syntax for type aliases
    HugeInt huge_number{123378997};

    std::cout << "sizeof(unsigned long long int ) : " << sizeof(unsigned long long int) << std::endl;
    std::cout << "sizeof(HugeInt) : " << sizeof(HugeInt) << std::endl;

    std::cout << "huge_number : " << huge_number << std::endl;
    return 0;
}
