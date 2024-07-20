/*
  @Author: Mitul Tyagi
  @Date:   2024-04-20 10:07:42
  @Description: Const Objects
  @Last Modified time: 2024-04-21 12:32:20
*/
/*
- const objects can not be modified and can not be read either i.e. getter methods will not work.const member functions can only be used to access it.
- For const objects only const member functions can be called.
- const objects are completely non-modifiable (immutable), the compiler won't allow calling a member function that modifies the const object in any way.
- It is not allowed to modify the object in any way inside const member functions. It is also not allowed to call a method that modifies the object indirectly
  either.
- Any attempt to modify an object's member variable (direct or indirect) from within a const member functions will result in a compiler error.
- Any non-const member functions can not be called within a const member function.
- A pointer is said to be dangling if it's pointing to or referencing invalid data.
*/
#include <iostream>
#include <iostream>
#include <string>

using namespace std;

/*---------------------------------------Dog Class-----------------------------------------------------------------*/
class Dog
{
public:
    Dog() = default;
    Dog(std::string_view name_param, std::string_view breed_param, unsigned int age_param);
    ~Dog();

    // Getters
    std::string_view get_name();
    std::string_view get_breed();
    unsigned int get_age();

    // Setters
    void set_name(std::string_view name_param);
    void set_breed(std::string_view breed_param);
    void set_age(unsigned int age);

    // Utility functions
    void print_info();

private:
    std::string_view m_name;
    std::string_view m_breed;
    unsigned int m_age;
};
Dog::~Dog()
{
    std::cout << " Destroying " << this->m_name << " object\n ";
}
Dog::Dog(std::string_view name_param, std::string_view breed_param, unsigned int age_param)
{
    m_name = name_param;
    m_breed = breed_param;
    m_age = age_param;
    std::cout << " Creating " << this->m_name << "object\n ";
}

// Getters
std::string_view Dog::get_name()
{
    // return m_name;
    return this->m_name;
}
std::string_view Dog::get_breed()
{
    return m_breed;
}
unsigned int Dog::get_age()
{
    return m_age;
}

// Setters
void Dog::set_name(std::string_view name_param)
{
    // m_name = name_param;
    this->m_name = name_param;
}
void Dog::set_breed(std::string_view breed_param)
{
    m_breed = breed_param;
}
void Dog::set_age(unsigned int age)
{
    m_age = age;
}

// Utility functions
void Dog::print_info()
{
    std::cout << "Dog (" << this << ") : [ name : " << this->m_name
              << ", breed : " << this->m_breed
              << ", age : " << this->m_age << "]" << std::endl;
}
// This causes no problem because we are working with a copy inside the function
void function_taking_dog(Dog dog)
{
    dog.set_name("Internal dog");
    dog.print_info();
}
// Parameter by non-const reference
void function_taking_dog_ref(Dog &dog_ref)
{
    // Compiler won't allow passing const object as argument
}

// Parameter by const reference
void function_taking_const_dog_ref(const Dog &const_dog_ref)
{
    // const_dog_ref.set_name("Hillo"); //Expected
    // const_dog_ref.print_info(); // Error: Not expected
}

// Pointer to non const as parameter
void function_taking_dog_p(Dog *p_dog)
{
    // Compiler won't allow passing const Dog objects as arguments
}

// Parameter passed as pointer to const
void function_taking_pointer_to_const_dog(const Dog *const_p_dog)
{
    // const_p_dog->set_name("Hillo"); // Error : Expected
    // const_p_dog->print_info();      // Error : Not expected
}
/*---------------------------------------DogConst Class-----------------------------------------------------------------*/
class DogConstClass
{
public:
    DogConstClass() = default;
    DogConstClass(std::string_view name_param, std::string_view breed_param, unsigned int age_param);
    DogConstClass(const std::string &name_param, const std::string &breed_param);
    ~DogConstClass();

    // Getters
    std::string_view getname() const;
    std::string_view getbreed() const;
    unsigned int getage() const;

    // Setters
    void setname(std::string_view name_param);
    void setbreed(std::string_view breed_param);
    void setage(unsigned int age);

    // Getters that work as Setters
    std::string &gsname()
    {
        return name;
    }
    const std::string &gsname() const
    {
        return name;
    }

    std::string &gsbreed()
    {
        return breed;
    }
    const std::string &gsbreed() const
    {
        return breed;
    }

    // Utility functions
    void printinfo() const;
    void printinfo();
    void mutable_call() const
    {
        this->info_print_count++;
        std::cout << " Mutable Count Value: " << this->info_print_count << std::endl;
    }
    // Dangling Reference
    const std::string &compile_dog_info() const
    {
        std::string dog_info = "dog_name : " + name + " dog_breed : " + breed + " dog_age :" + std::to_string(mage);
        return dog_info;
    }
    // Dangling Pointer
    unsigned int *jumps_per_minute() const
    {
        unsigned int jumps{5};
        return &jumps;
    }

private:
    std::string_view mname;
    std::string_view mbreed;
    std::string name;
    std::string breed;
    unsigned int mage{7};
    unsigned int info_print{0};
    mutable unsigned int info_print_count{0};
};
DogConstClass::~DogConstClass()
{
    std::cout << " Destroying " << this->mname << " object\n ";
}
DogConstClass::DogConstClass(std::string_view name_param, std::string_view breed_param, unsigned int age_param)
{
    mname = name_param;
    mbreed = breed_param;
    mage = age_param;
    std::cout << " Creating " << this->mname << "object\n ";
}
DogConstClass::DogConstClass(const std::string &name_param, const std::string &breed_param)
{
    name = name_param;
    breed = breed_param;
    std::cout << " Creating " << this->mname << "object\n ";
}
// Getters
std::string_view DogConstClass::getname() const
{
    // return m_name;
    return this->mname;
}
std::string_view DogConstClass::getbreed() const
{
    return mbreed;
}
unsigned int DogConstClass::getage() const
{
    // this->mage = 6; Error
    return mage;
}

// Setters
void DogConstClass::setname(std::string_view name_param)
{
    // m_name = name_param;
    this->mname = name_param;
}
void DogConstClass::setbreed(std::string_view breed_param)
{
    mbreed = breed_param;
}
void DogConstClass::setage(unsigned int age)
{
    mage = age;
}

// Utility functions
void DogConstClass::printinfo() const
{
    std::cout << "DogConstClass (" << this << ") : [ name : " << this->mname
              << ", breed : " << this->mbreed
              << ", age : " << this->mage << "]" << std::endl;
    std::cout << "Const Object " << this << std::endl;
    // this->info_print++; Error
}
// Overloaded Function. Will be called for non-const objects
void DogConstClass::printinfo()
{
    std::cout << "DogConstClass (" << this << ") : [ name : " << this->mname
              << ", breed : " << this->mbreed
              << ", age : " << this->mage << "]" << std::endl;
    std::cout << "Non Const Object " << this << std::endl;
    this->info_print++;
}
// This causes no problem because we are working with a copy inside the function
void function_taking_dog(DogConstClass dog)
{
    dog.setname("Internal dog");
    dog.printinfo();
}
// Parameter by non-const reference
void function_taking_dog_ref(DogConstClass &dog_ref)
{
    // Compiler won't allow passing const object as argument
}

// Parameter by const reference
void function_taking_const_dog_ref(const DogConstClass &const_dog_ref)
{
    // const_dog_ref.set_name("Hillo"); //Expected
    const_dog_ref.printinfo(); // Will Work
}

// Pointer to non const as parameter
void function_taking_dog_p(DogConstClass *p_dog)
{
    // Compiler won't allow passing const Dog objects as arguments
}

// Parameter passed as pointer to const
void function_taking_pointer_to_const_dog(const DogConstClass *const_p_dog)
{
    // const_p_dog->set_name("Hillo"); // Error : Expected
    const_p_dog->printinfo(); // Will Work
}
/*---------------------------------------Point Class-----------------------------------------------------------------*/
class Point
{
public:
    double x;
    double y;
};

void print_point(const Point p)
{
    std::cout << "Point [ x : " << p.x << ", y : " << p.y << "]" << std::endl;
}
int main(int argc, char const *argv[])
{
    {
        const Dog dog1("Fluffy", "Shepherd", 2);

        // Direct access
        /*
        dog1.print_info(); // Compiler error

        dog1.set_name("Milou"); // Compiler error

        dog1.print_info(); // Compile Error
        */

        // Pointer to non const
        // Dog * dog_ptr = &dog1; // Error: Invalid conversion from const Dog* to Dog*

        // Non const reference
        // Dog& dog_ref = dog1; // Error: Can't convert from const Dog& to Dog&

        // Pointer to const
        const Dog *const_dog_ptr = &dog1;
        // const_dog_ptr->set_name("Milou"); // Error
        // const_dog_ptr->get_name(); // Error

        // Const reference
        const Dog &const_dog_ref = dog1;
        // const_dog_ref.set_name("Milou"); // Error
        // const_dog_ref.get_name(); // Error
        // const_dog_ref.print_info(); // Error
    }
    { // Const Objects as Function Arguments
        const Dog dog1("Cute", "Poodle", 3);
        std::cout << "address of object : " << &dog1 << std::endl;

        // Function taking parameter by value : WORKS
        function_taking_dog(dog1);

        // function_taking_dog_ref(dog1); // Compiler error

        // function_taking_const_dog_ref(dog1); // Compiler Error

        // function_taking_dog_p(&dog1); // Compilier Error

        // function_taking_pointer_to_const_dog(&dog1); //Compile Error
    }
    { // const member functions

        const DogConstClass dog1("Danger", "Poodle", 3);
        DogConstClass dog2("Fast", "Poodle", 5);
        dog1.printinfo();
        function_taking_dog(dog1);
        // function_taking_dog_ref(dog1); // Compiler error
        function_taking_const_dog_ref(dog1);
        // function_taking_dog_p(&dog1);
        function_taking_pointer_to_const_dog(&dog1);
        dog2.printinfo();
    }
    { // Getters that double as setters

        DogConstClass dog1("Sleepy", "Stray");
        dog1.printinfo();
        std::cout << "dog name : " << dog1.gsname() << std::endl; // Getter

        // Modify the object
        dog1.gsname() = "Milou"; // Setter
        dog1.printinfo();

        const DogConstClass dog2("Tom", "Poodle");
        dog2.printinfo();
        std::cout << "dog name : " << dog2.gsname() << std::endl; // Getter

        // Modify the object
        //  dog2.gsname() = "Mike"; // Setter Error
        dog2.printinfo();
    }
    { // Dangling Pointer
        DogConstClass dog1("Fluffy", "Shepherd");

        /* Segmentation Fault
        const std::string& str_ref = dog1.compile_dog_info();
        std::cout << " info : " << str_ref << std::endl;
        */

        /* Segmentation Fault
        unsigned int* int_ptr = dog1.jumps_per_minute();
        std::cout << "jumps_per_minute : " << *int_ptr << std::endl;
        */

        std::cout << "Done!" << std::endl;
    }
    { // Mutable Member Variables
        const DogConstClass dog1("Fluffy", "Shepherd");
        for (size_t i{0}; i < 10; i++)
            dog1.mutable_call();
    }
    { // Structured Bindings
        Point point1;

        point1.x = 5;
        point1.y = 6;

        print_point(point1);

        auto [a, b] = point1; // Structured Binding

        std::cout << "a : " << a << std::endl;
        std::cout << "b : " << b << std::endl;

        point1.x = 44.1;
        point1.y = 55.2;

        print_point(point1);

        std::cout << "a : " << a << std::endl;
        std::cout << "b : " << b << std::endl;

        auto func = [=]()
        {
            std::cout << "a (captured) : " << a << std::endl;
            std::cout << "b (captured) : " << b << std::endl;
        };
        func();
    }
    return 0;
}
