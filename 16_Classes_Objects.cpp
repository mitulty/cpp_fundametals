/*
  @Author: Mitul Tyagi
  @Date:   2024-04-19 21:34:07
  @Description: Classes & Objects
*/
/*
- OOP stands for Object-Oriented Programming. Procedural programming is about writing procedures or functions that perform operations on the data,
  while object-oriented programming is about creating objects that contain both data and functions. Object-oriented programming has several advantages
  over procedural programming:
    -> OOP is faster and easier to execute
    -> OOP provides a clear structure for the programs
    -> OOP helps to keep the C++ code DRY "Don't Repeat Yourself", and makes the code easier to maintain, modify and debug
    -> OOP makes it possible to create full reusable applications with less code and shorter development time
- C++ is an object-oriented programming language. Everything in C++ is associated with classes and objects, along with its attributes and methods.
  For example: in real life, a car is an object. The car has attributes, such as weight and color, and methods, such as drive and brake. Attributes and methods
  are basically variables and functions that belongs to the class. These are often referred to as "class members". A class is a user-defined data type that it
  can be used in the program, and it works as an object constructor, or a "blueprint" for creating objects.
- Classes are a mechanism to build user-defined types and use them as built in types. Classes are used to represent real-world entities and are blueprints
  for them.
- When variables are declared within a class, they are called attributes.
- A simple class declaration is:
                class MyClass {       // The class
                  public:             // Access specifier
                    int myNum;        // Attribute (int variable)
                    string myString;  // Attribute (string variable)
                    void showNum()    // Method (showNum function)
                    {
                        std::cout << myNum << std::endl;
                    }
                };
    -> The class keyword is used to create a class called MyClass.
    -> The public keyword is an access specifier, which specifies that members (attributes and methods) of the class are accessible from outside the class.
    -> Inside the class, there is an integer variable myNum and a string variable myString. When variables are declared within a class, they are called
       attributes.
    -> At last, end the class definition with a semicolon ;.
- Methods are functions that belong to the class. There are two ways to define functions that belong to a class:
    -> Inside class definition
    -> Outside class definition
- Methods can be accessed just like attributes are accessed; by creating an object of the class and using the dot syntax (.).
- To define a function outside the class definition, it has to be declared inside the class and then defined outside of the class. This is done by specifiying
  the name of the class, followed the scope resolution :: operator, followed by the name of the function.
- A constructor in C++ is a special method that is automatically called when an object of a class is created. To create a constructor, use the same name as
  the class, followed by parentheses (). Constructors can also take parameters (just like regular functions), which can be useful for setting initial values
  for attributes.
- Just like functions, constructors can also be defined outside the class. First, declare the constructor inside the class, and then define it outside of the
  class by specifying the name of the class, followed by the scope resolution :: operator, followed by the name of the constructor (which is the same as the
  class):
- Access specifiers define how the members (attributes and methods) of a class can be accessed.
- In C++, there are three access specifiers:
            -> public: members are accessible from outside the class
            -> private: members cannot be accessed (or viewed) from outside the class
            -> protected: members cannot be accessed from outside the class, however, they can be accessed in inherited classes.
- Members of a class are private by default. The members can be raw stack variables, pointers or references.
- In C++, an object is created from a class.
- A class constructor is a special kind of a class method that is called when an instance of a class is created. It has no return type, same name as the class,
  can have parameters or an empty parameter list, and is usually used to initialize member variables of a class. It has to be public.
- Compiler generates an empty constructor/default constructor if there is no other constructor defintion available. A default constructor contains no parameters
  and will not be genreated if a constructor defintion is present in the code. It has to be explicityl declared for objects that need default values only.
- Setters and Getters are methods to read or modify member variables of a class which are private. These are public functions.
- Destructors are special methods that are called when an object dies. They are needed when the object needs to release some dynamic memory, or for some other
  kind of clean up. It is defined as public.
- The destructors are called in wierd places:
    -> When an object is passed by value to a function
    -> When a local object is returned from a function
    -> When a local stack object goes out of scope
    -> When a heap obect is relased with the delete
- The object that was constructed last will be destroyed first.
- The size of the object is dependent on the size of member variables only and not member functions. The members are boundary aligned.
- struct keyword can be used to create classes but members are public by default. These are generally used for classes that have public member variables only.
- Each class member function contains a hidden pointer called this. That pointer contains the address of the current object, for which the method is being
  executed. This also applies to constructors and destructors.
*/

#include <iostream>
#include <string_view>

using namespace std;

const double PI{3.141592653589793238};

/*---------------------------------------Dog Class-----------------------------------------------------------------*/
class Dog
{
public:
    Dog() = default;
    Dog(std::string_view name_param, std::string_view breed_param, int age_param);
    ~Dog();
    void print_info()
    {
        std::cout << "Dog (" << this << ") : [ name : " << name
                  << " breed : " << breed << " age : " << *p_age << "]" << std::endl;
    }

    // Setters
    // Chained calls using pointers
    /*
    Dog* set_dog_name(std::string_view name){
        //name = name; // This does nothing
        this->name = name;
        return this;
    }
    Dog* set_dog_breed(std::string_view breed){
        this->breed = breed;
        return this;
    }

    Dog* set_dog_age(int age){
        *(this->p_age) = age;
        return this;
    }
    */

    // Chained calls using references
    Dog &set_dog_name(std::string_view name)
    {
        // name = name; // This does nothing
        this->name = name;
        return *this;
    }
    Dog &set_dog_breed(std::string_view breed)
    {
        this->breed = breed;
        return *this;
    }

    Dog &set_dog_age(int age)
    {
        *(this->p_age) = age;
        return *this;
    }

private:
    std::string name;
    std::string breed;
    int *p_age{nullptr};
};
Dog::Dog(std::string_view name_param, std::string_view breed_param, int age_param)
{
    name = name_param;
    breed = breed_param;
    p_age = new int;
    *p_age = age_param;
    std::cout << "Dog constructor called for " << name << " at " << this << std::endl;
}

Dog::~Dog()
{
    delete p_age;
    std::cout << "Dog destructor called for " << name << " at " << this << std::endl;
}

void some_func()
{
    Dog *p_dog = new Dog("Fluffy", "Shepherd", 2);

    delete p_dog; // Causes for the destructor of Dog to be called
}

/*---------------------------------------Cylinder Class-----------------------------------------------------------------*/
class Cylinder
{
public:
    // Constctors
    // Cylinder() = default; // A default constructor is generated by the compiler only when there is no other constructor defintion available.
    Cylinder()
    {
        base_radius = 2.0;
        height = 2.0;
    }

    Cylinder(double rad_param, double height_param)
    {
        base_radius = rad_param;
        height = height_param;
    }

    // Functions (methods)
    double surface_area();

    double volume()
    {
        return PI * base_radius * base_radius * height;
    }

    // Setter and getter methods
    double get_base_radius()
    {
        return base_radius;
    }
    double get_height()
    {
        return height;
    }

    void set_base_radius(double rad_param)
    {
        base_radius = rad_param;
    }

    void set_height(double height_param)
    {
        height = height_param;
    }

private:
    // Member variables
    double base_radius{1};
    double height{1};
};

double Cylinder::surface_area()
{
    return (2 * PI * base_radius * (height + base_radius));
}

/*---------------------------------------Cat Class-----------------------------------------------------------------*/
class Cat
{
public:
    Cat() = default;

private:
    size_t leg_count;
    size_t arm_count;
    int *p_age;
};

/*---------------------------------------Student Class-----------------------------------------------------------------*/
class Student
{
public:
    std::string m_name;
};

struct Person
{
public:
    std::string m_name;
};

/*---------------------------------------Point Class-----------------------------------------------------------------*/
struct Point
{
    double x;
    double y;
};

void print_point(const Point &point)
{
    std::cout << "Point [ x: " << point.x << ", y : " << point.y << "]" << std::endl;
}
int main(int argc, char const *argv[])
{
    Cylinder cylinder1; // Object
    std::cout << "volume cylinder1 : " << cylinder1.volume() << std::endl;
    std::cout << "surface area cylinder1 : " << cylinder1.surface_area() << std::endl;
    /*
    ----> Will work only when the data members are public and not private
   // Change the member variables
   cylinder1.base_radius = 10;
   cylinder1.height = 3;

   std::cout << "volume cylinder1 : " << cylinder1.volume() << std::endl;
   std::cout << "surface area cylinder1 : " << cylinder1.surface_area() << std::endl;
   cylinder1.height = 8;
   std::cout << "volume cylinder1 : " << cylinder1.volume() << std::endl;
   std::cout << "surface area cylinder1 : " << cylinder1.surface_area() << std::endl;
    */

    Cylinder cylinder2(10, 4); // Object
    std::cout << "volume cylinder2: " << cylinder2.volume() << std::endl;

    Cylinder cylinder3; // Object
    std::cout << "volume cylinder3: " << cylinder3.volume() << std::endl;

    Cylinder cylinder4(10, 10);
    std::cout << "base radius cylinder4: " << cylinder4.get_base_radius() << std::endl;
    std::cout << "height cylinder4: " << cylinder4.get_height() << std::endl;
    std::cout << "volume cylinder4: " << cylinder4.volume() << std::endl;

    // Modify our object
    cylinder4.set_base_radius(100);
    cylinder4.set_height(10);

    std::cout << "base radius cylinder4: " << cylinder4.get_base_radius() << std::endl;
    std::cout << "height cylinder4: " << cylinder4.get_height() << std::endl;
    std::cout << "volume cylinder4: " << cylinder4.volume() << std::endl;

    // Managing a stack object through pointers
    Cylinder *p_cylinder1 = &cylinder1;

    // std::cout << "volume : " << (*p_cylinder1).volume() << std::endl;
    std::cout << "volume : " << p_cylinder1->volume() << std::endl;

    // Create a cylinder heap object through the new operator
    Cylinder *p_cylinder2 = new Cylinder(100, 2); // Heap

    std::cout << "volume(cylinder2) : " << p_cylinder2->volume() << std::endl;
    std::cout << "base_rad(cylinder2) : " << p_cylinder2->get_base_radius() << std::endl;
    std::cout << "height(cylinder2) : " << p_cylinder2->get_height() << std::endl;

    delete p_cylinder2;
    some_func();
    std::cout << "Done!" << std::endl;
    Dog dog_new("Non-Fluffy", "Poodle", 2);

    Dog dog1("Dogyy1", "Shepherd", 2);
    Dog dog2("Dogyy2", "Shepherd", 3);
    Dog dog3("Dogyy3", "Shepherd", 5);
    Dog dog4("Dogyy4", "Shepherd", 1);

    Cat cat;
    std::cout << "sizeof(size_t) : " << sizeof(size_t) << std::endl;
    std::cout << "sizeof(int*) : " << sizeof(int *) << std::endl;
    std::cout << "sizeof(Cat) : " << sizeof(cat) << std::endl;

    std::string name{"I am the king of the universe!"};

    std::cout << "sizeof(name) : " << sizeof(name) << std::endl;

    Person jack;
    Student kim;

    jack.m_name = "Fluffy";
    kim.m_name = "Juny";
    std::cout << jack.m_name << std::endl;
    std::cout << kim.m_name << std::endl;

    Point point1;
    point1.x = 10;
    point1.y = 55.5;

    print_point(point1);

    point1.x = 40.4;
    point1.y = 2.7;
    print_point(point1);

    Dog dog10("Cute", "Shepherd", 2); // Constructor
    dog10.print_info();
    Dog *p_dog10{&dog10};
    Dog *p_dog11 = new Dog("Fluffy", "Shepherd", 2);

    dog10.set_dog_name("Pumba");
    dog10.set_dog_breed("Wire Fox Terrier");
    dog10.set_dog_age(4);

    // Chained calls using pointers
    // p_dog10->set_dog_name("Pumba")->set_dog_breed("Wire Fox Terrier")->set_dog_age(4);
    // p_dog11->set_dog_name("Pumba")->set_dog_breed("Wire Fox Terrier")->set_dog_age(4);

    // Chained calls using references
    dog10.set_dog_name("Pumba").set_dog_breed("Wire Fox Terrier").set_dog_age(4);

    dog10.print_info();

    return 0;
}
