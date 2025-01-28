/**
 * @Author: Mitul Tyagi
 * @Date:   2024-04-21 20:42:25
 * @Description: Constructors and Initialization
 */
/*
- Default parameters can be defined for constructors also.
- Initializer list can be used to avoid unnecessary copies in case of member wise copy initialization.
- Explicit constructors do not allow implicit conversion calls.
- Constructor delegation allows one constructor to call other constructor using initializer list. During constructor delegation, any other initialization using
  intializer list will not work.
- Copy constructors are called when a copy of a class object is created from another object. It copies all the variables member-wise. Compiler generates its
  own copy constructor.
- Objects stored in arrays create copy of the objects.
- Shallow Copy: Member wise copy of member variables, even for pointers.
- Deep Copy: When pointer variables are involved, allocating a new memory and copying in data from the source pointer.
- Move constructor steals data from temporary objects.
*/
#include <iostream>
#include <string>

using namespace std;
const double PI{3.1415926535897932384626433832795};
/*--------------------------Cylinder Class---------------------------------------------*/
class Cylinder
{
public:
    // Constctors
    Cylinder() = default;
    Cylinder(double rad_param, double height_param = 5);
    // Cylinder(double rad_param =7, double height_param = 5); // This will contradict with the default constructor.
    Cylinder(double rad_param, int col);

    //  Functions (methods)
    double volume();

    // Setter and getter methods
    double get_base_radius();
    double get_height();
    void set_base_radius(double rad_param);
    void set_height(double height_param);

private:
    // Member variables
    double base_radius{1};
    double height{2};
    int color{};
};

Cylinder::Cylinder(double rad_param, double height_param)
{
    base_radius = rad_param;
    height = height_param;
    std::cout << "Two param constructor called" << std::endl;
}

// Initializer lists
Cylinder::Cylinder(double rad_param, int col)
    : base_radius(rad_param), color(col)
{
}

double Cylinder::volume()
{
    return PI * base_radius * base_radius * height;
}

// Setter and getter methods
double Cylinder::get_base_radius()
{
    return base_radius;
}
double Cylinder::get_height()
{
    return height;
}

void Cylinder::set_base_radius(double rad_param)
{
    base_radius = rad_param;
}

void Cylinder::set_height(double height_param)
{
    height = height_param;
}

/*--------------------------Square Class---------------------------------------------*/
class Square
{
public:
    explicit Square(double side_param, const std::string &color_param = "black");
    // explicit Square(double side_param);
    ~Square();
    double surface() const;

private:
    double m_side;
    std::string m_color;
};
Square::Square(double side_param, const std::string &color_param)
    : m_side{side_param}, m_color{color_param}
{
}

/*
Square::Square(double side_param)
    : m_side{side_param}
{
}
*/

double Square::surface() const
{
    return m_side * m_side;
}

Square::~Square()
{
}
// Is square1 > to square2 ? true or false
bool compare(const Square &square1, const Square &square2)
{
    return (square1.surface() > square2.surface()) ? true : false;
}
/*--------------------------Rectangle Class---------------------------------------------*/
class Rectangle
{
public:
    explicit Rectangle(double side_param);
    Rectangle(double side_param, const std::string &color_param, int shading_param);
    ~Rectangle();
    double surface() const;

private:
    double m_side;
    std::string m_color;
    int m_shading;
    double m_position;
};
Rectangle::Rectangle(double side_param)
    : Rectangle{side_param, "black", 6}
{
    m_position = 45.8;
    std::cout << "One param Rectangle constructor called" << std::endl;
}

Rectangle::Rectangle(double side_param, const std::string &color_param, int shading_param)
    : m_side{side_param}, m_color{color_param}, m_shading{shading_param}
{
    std::cout << "Three param Rectangle constructor called" << std::endl;
}

double Rectangle::surface() const
{
    return m_side * m_side;
}

Rectangle::~Rectangle()
{
    std::cout << "Rectangle object destroyed" << std::endl;
}

/*--------------------------Person Class---------------------------------------------*/
class Person
{
private:
    std::string last_name{};
    std::string first_name{};
    int *age{};

public:
    // Constructors
    Person() = default;
    Person(const std::string &last_name_param, const std::string &first_name_param, int age_param);
    Person(const std::string &last_name_parm, const std::string &first_name_param);
    Person(const std::string &last_name);

    // Copy Constructor
    // Person(const Person source_p); // BAD : Potential for an endles chain of copy constructor calls

    // Memberwise copy
    // Person(const Person& source_p);

    // Don't blindly copy the pointer
    Person(const Person &source_p);
    ~Person();

    // Setters
    void set_first_name(const std::string &first_name) { this->first_name = first_name; }
    void set_last_name(const std::string &last_name) { this->last_name = last_name; }
    void set_age(int age) { *(this->age) = age; } // Remember to dereference

    // Getters
    const std::string &get_first_name() const { return first_name; }
    const std::string &get_last_name() const { return last_name; }
    int *get_age() const { return age; };

    // Utilities
    void print_info()
    {
        std::cout << "Person object at : " << this
                  << " [ Last_name : " << last_name
                  << ", First_name :  " << first_name
                  << " ,age : " << *age
                  << " , age address : " << age
                  << " ]" << std::endl;
    }
};
Person::~Person()
{
    delete age; // Make sure that you are not leaking memory
}
Person::Person(const std::string &last_name)
    : Person(last_name, "")
{
}
Person::Person(const std::string &last_name_param, const std::string &first_name_param)
    : Person(last_name_param, first_name_param, 0)
{
}
Person::Person(const std::string &last_name_param, const std::string &first_name_param, int age_param)
    : last_name(last_name_param), first_name(first_name_param), age(new int(age_param))
{
}

/*
Person::Person(const Person source_p)  // BAAAAD!
    : last_name(source_p.get_last_name()),first_name(source_p.get_last_name()),age(source_p.get_age())
{

}
*/

// Memberwise copy : BAD. This will result in the copy of pointer address rather than the data
/*
Person::Person(const Person& source_p)
    : last_name(source_p.get_last_name()),first_name(source_p.get_first_name()),age(source_p.get_age())
{
    std::cout << "Copy constructor called" << std::endl;
}
*/

// Don't blindly copy pointer member variables: Good. This will make sure that pointer points to a new location with data from prevoius object
/*
Person::Person(const Person& source_p)
    : last_name(source_p.get_last_name()),first_name(source_p.get_first_name()),age(new int(*(source_p.get_age())))
{
    std::cout << "Copy constructor called" << std::endl;
}
*/

// Delegate from the copy constructor
Person::Person(const Person &source_p)
    : Person(source_p.get_last_name(), source_p.get_first_name(), *(source_p.get_age()))
{
    std::cout << "Copy constructor called" << std::endl;
}
/*--------------------------Point Class---------------------------------------------*/
class Point
{
public:
    // methods
    Point(double x = 10.1, double y = 100.1)
        : m_x(x), m_y(y)
    {
    }

    Point(const Point &p)
        : m_x(p.x()), m_y(p.y())
    {
        std::cout << "Const copy Constructor Called..." << std::endl;
    }

    Point(Point &p)
        : m_x(p.x()), m_y(p.y())
    {
        std::cout << "Non-const copy Constructor Called..." << std::endl;
    }

    void set_x(double x)
    {
        m_x = x;
    }

    void set_y(double y)
    {
        m_y = y;
    }

    double x() const
    {
        return m_x;
    }
    double y() const
    {
        return m_y;
    }
    // member variables
private:
    double m_x{1};
    double m_y{1};
};

void print_point(Point &p)
{
    std::cout << "Point[x : " << p.x() << ", y : " << p.y() << "]\n";
}

/*--------------------------Coordinates Class---------------------------------------------*/
class Coordinates
{
private:
    double *x{};
    double *y{};

    void invalidate()
    {
        x = nullptr;
        y = nullptr;
    }

public:
    Coordinates(double x_param, double y_param);
    ~Coordinates();

    // Copy constructor
    Coordinates(const Coordinates &source_point);

    // Move constructor
    Coordinates(Coordinates &&source_point);

    // Setters
    void set_x(double x)
    {
        *(this->x) = x; // Dereference and assign
    }
    void set_y(double y)
    {
        *(this->y) = y; // Dereference and assign
    }

    // Getters
    double *get_x() const
    {
        return x;
    }

    double *get_y() const
    {
        return y;
    }

    double *steal_x()
    {
        double *new_x = x;
        x = nullptr;
        return new_x;
    }

    double *steal_y()
    {
        double *new_y = y;
        y = nullptr;
        return new_y;
    }

    // Utilities
    void print_info() const
    {
        std::cout << "Point [ x : " << (*x) << ", y: " << (*y) << "]" << std::endl;
    }
};

Coordinates::Coordinates(double x_param, double y_param)
    : x(new double(x_param)), y(new double(y_param))
{
    std::cout << "Coordinates Constructed  : " << this << std::endl;
}

// Copy constructor
Coordinates::Coordinates(const Coordinates &source_point)
    : x(new double(*(source_point.get_x()))), y(new double(*(source_point.get_y())))
{
    std::cout << "Body of Copy Constructor" << std::endl;
}

// Move constructor
Coordinates::Coordinates(Coordinates &&source_point)
    : x(source_point.steal_x()), y(source_point.steal_y())
{
    // source_point.invalidate();
    std::cout << "Body of Move Constructor" << std::endl;
}

Coordinates::~Coordinates()
{
    delete x;
    delete y;
}
int main(int argc, char const *argv[])
{
    { // Default Parameters For Constructors
        std::cout << "--------------------***************-----------------------" << std::endl;
        Cylinder c1(4);
        std::cout << "volume : " << c1.volume() << std::endl;
    }
    { // Explicit Constructors
        std::cout << "--------------------***************-----------------------" << std::endl;
        Square s1(100.0);
        Square s2(20.0);

        std::cout << std::boolalpha;
        std::cout << "s1 > s2 : " << compare(s1, s2) << std::endl; // fals  e

        // Implicit conversions
        // std::cout << "s1 > 45.9 : " << compare(s1, 45.9) << std::endl; // false
    }
    { // Constructor Delegation
        std::cout << "--------------------***************-----------------------" << std::endl;
        Rectangle s1(100.0);
    }
    { // Copy Constructors
        std::cout << "--------------------***************-----------------------" << std::endl;
        Person p1("John", "Snow", 25);
        p1.print_info();

        // Create a person copy
        Person p2(p1);
        p2.print_info();

        std::cout << "-------" << std::endl;

        p1.set_age(30);
        p1.print_info();
        p2.print_info();
    }
    {
        std::cout << "--------------------***************-----------------------" << std::endl;
        Point p1(25.1, 32.2);
        Point p2(p1);
        print_point(p2);

        const Point p3(13.5, 6.8);
        Point p4(p3);
        print_point(p4);
    }
    { // Arrays and Copies

        std::cout << "--------------------***************-----------------------" << std::endl;
        Person p1("John", "Snow", 25);
        Person p2("Sam", "Gray", 45);
        Person p3("Johny", "Drill", 5);
        p1.print_info();
        p2.print_info();
        p3.print_info();

        std::cout << "----" << std::endl;

        Person students[]{p1, p2, p3};
        for (size_t i{}; i < std::size(students); ++i)
        {
            students[i].print_info();
        }

        std::cout << "----" << std::endl;

        // This will create copies
        for (Person p : students)
        {
            p.print_info();
        }

        std::cout << "----" << std::endl;
        // Using reference will avoid copies
        for (Person &p : students)
        {
            p.print_info();
        }
    }
    {
        Coordinates p1(10.4, 15.6);
        p1.print_info();

        // Create a copy from a temporary
        Coordinates p3(std::move(Coordinates(20.5, 5.8)));
        p3.print_info();
    }

    return 0;
}
