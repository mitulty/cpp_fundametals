/**
 * @Author: Mitul Tyagi
 * @Date:   2024-04-21 20:19:12
 * @Description: Friends
 */
/*
- Friend means giving access to the class member variables to external entities. External entities can be either functions or classes.
- Friend functions are external functions with access to private members of a class.
- The friend function is first declared and alive somewhere.
- The implementation can live in any translation unit.
- The declaration has to show up before the call of the function.
- The class determines who is its friend through friend declaration.
- The friend declaration can appear in public or private section of the class, either works the same.
- There can be multiple friend functions in the same class.
- Friend functions can be overloaded.
- The notation of object_name.member_var_name is used in the friend function.
- Friend functions are not member functions.
- Friend functions do not have access to the this pointer.
- Friend functions can change the data members. Use const to avoid this behaviour.
*/
#include <iostream>

using namespace std;

class Dog
{
    friend void debug_dog_info(const Dog &d);
    friend void debug_dog_info();
    friend void set_age(Dog &d, int age); // This friend function can change the member variables.
    friend class Cat;

public:
    Dog(const std::string &name, int age)
        : m_name{name}, m_age{age}
    {
    }

private:
    std::string m_name;

protected:
    int m_age;
};

void debug_dog_info(const Dog &d)
{
    std::cout << "Dog [ name : " << d.m_name << ", age : " << d.m_age << "]" << std::endl;
}

void debug_dog_info()
{
    Dog dog1("Milou", 3);
    dog1.m_name = "Toddle";
    std::cout << "Dog [ name : " << dog1.m_name << ", age : " << dog1.m_age << "]" << std::endl;
}
void set_age(Dog &d, int age)
{
    d.m_age = age;
}
class Cat
{
public:
    void print_dog_info(const Dog &d) const
    {
        std::cout << "Dog [ name : " << d.m_name << ", age : " << d.m_age << "]" << std::endl;
    }
    void set_dog_age(Dog &d, int age)
    {
        d.m_age = age;
    }
};
int main(int argc, char const *argv[])
{
    { // Friend Function
        Dog dog1("Fluffy", 4);
        debug_dog_info();
        debug_dog_info(dog1);
        set_age(dog1, 7);
        debug_dog_info(dog1);
    }
    {
        // Friend Class
        Cat cat1;

        Dog dog1("Rough", 2);

        cat1.print_dog_info(dog1);
        cat1.set_dog_age(dog1, 10);
        cat1.print_dog_info(dog1);
    }
    return 0;
}
