/**
 * @Author: Mitul Tyagi
 * @Date:   2024-04-20 22:00:06
 * @Description: Inheritance
 */
/*
- The capability of a class to derive properties and characteristics from another class is called Inheritance. Inheritance is a feature or a process in which,
  new classes are created from the existing classes. The new class created is called “derived class” or “child class” and the existing class is known as
  the “base class” or “parent class”. The derived class now is said to be inherited from the base class. the derived class inherits all the properties of
  the base class, without changing the properties of base class and may add new features to its own. These new features in the derived class will not affect
  the base class. The derived class is the specialized class for the base class.
- Sub Class: The class that inherits properties from another class is called Subclass or Derived Class.
- Super Class: The class whose properties are inherited by a subclass is called Base Class or Superclass.
- Through the base class access specifier, we can control how relaxed or constrained is the access of base class members from the derived class.
- Regardless of the access specifier, private members of the base class are never accessible from derived classes.
- Modes of Inheritance: There are 3 modes of inheritance.
    -> Public Mode: If we derive a subclass from a public base class. Then the public member of the base class will become public in the derived class and
       protected members of the base class will become protected in the derived class.
    -> Protected Mode: If we derive a subclass from a Protected base class. Then both public members and protected members of the base class will become
       protected in the derived class.
    -> Private Mode: If we derive a subclass from a Private base class. Then both public members and protected members of the base class will become Private
       in the derived class.
- A derived class doesn’t inherit access to private data members. However, it does inherit a full parent object, which contains any private members which that
  class declares.
- When a base class is privately inherited by the derived class, public members of the base class becomes the private members of the derived class and
  therefore, the public members of the base class can only be accessed by the member functions of the derived class. They are inaccessible to the objects of
  the derived class.
- On the other hand, when the base class is publicly inherited by the derived class, public members of the base class also become the public members of the
  derived class. Therefore, the public members of the base class are accessible by the objects of the derived class as well as by the member functions of the
  derived class.
- The private members in the base class cannot be directly accessed in the derived class, while protected members can be directly accessed.
- With public inheritance, derived classes can access and use public members of the base class, but the derived class can't directly access private members.
- The same also applies to friends of the derived class. They have access to private members of derived, but don't have access to the base class.
- A protected member is not available outside the class like a private member but can be inherited by the subcalsses unlike a private member.
- Using keyword can be used to resurrect the access levels for the base class members when inheriting privately.
- Default constructor for the most base class is formed first followed by the sub-classes. Base class constructors are not inherited by default. The keyowrd
  using can be used to inherit the constructor from the base class which will initialize the base member variables only and is generated by the compiler.
- Copy constructors are not inherited. Inherited constructors are base constructors. Constructors are inherited with whatever access specifier they had in
  base class.
- Destructors of the sub-classes are called first followed by the base classes.
*/
#include <iostream>
#include <string>

using namespace std;
class Person
{
    friend std::ostream &operator<<(std::ostream &out, const Person &person);

public:
    Person();
    Person(std::string &first_name_param, std::string &last_name_param);
    Person(std::string_view fullname, int age, std::string_view address);
    Person(const Person &source);
    ~Person();

    // Getters
    std::string get_first_name() const
    {
        return first_name;
    }

    std::string get_last_name() const
    {
        return last_name;
    }

    std::string get_gender_base() const
    {
        return gender;
    }

    std::string get_address() const
    {
        return m_address;
    }

    int get_age() const
    {
        return m_age;
    }

    std::string get_full_name() const
    {
        return m_full_name;
    }

    // Setters
    void set_first_name(std::string_view fn)
    {
        first_name = fn;
    }

    void set_last_name(std::string_view ln)
    {
        last_name = ln;
    }

    void set_gender_base(std::string_view gen)
    {
        gender = gen;
    }

    void set_age_base(int age)
    {
        m_age = age;
    }

    void set_address(std::string_view addr)
    {
        m_address = addr;
    }
    void set_full_name(std::string_view fn)
    {
        m_full_name = fn;
    }

    int add(int a, int b) const
    {
        return a + b;
    }

    int add(int a, int b, int c) const
    {
        return a + b + c;
    }

    void do_something() const;

public:
    std::string m_full_name{"None"};

private:
    std::string first_name{"Mysterious"};
    std::string last_name{"Person"};
    std::string m_address{"None"};

protected:
    std::string gender{"Male"};
    int m_age{0};
};

Person::Person()
{
    std::cout << "Default constructor for Person called..." << std::endl;
}

Person::Person(std::string &first_name_param, std::string &last_name_param)
    : first_name(first_name_param), last_name(last_name_param)
{
}

Person::Person(std::string_view fullname, int age, std::string_view address)
    : m_full_name{fullname}, m_age{age}, m_address{address}
{
    std::cout << "Custom constructor for Person called..." << std::endl;
}

Person::Person(const Person &source)
    : m_full_name(source.m_full_name), m_age(source.m_age), m_address(source.m_address)
{
    std::cout << "Custom copy constructor for Person called..." << std::endl;
}
std::ostream &operator<<(std::ostream &out, const Person &person)
{
    out << "Person [Full name :" << person.get_full_name() << ", Age:" << person.get_age() << ", Address:" << person.get_address() << "]";
    return out;
}

Person::~Person()
{
    std::cout << "Destructor for Person called .." << std::endl;
}

void Person::do_something() const
{
    std::cout << "Hello" << std::endl;
}

/*---------------------------------------Player Class-----------------------------------------------------------------*/
class Player : public Person
{
    friend std::ostream &operator<<(std::ostream &out, const Player &player);

public:
    // Player() = default;
    Player();
    Player(std::string_view game_param);
    void set_gender(std::string_view sgen)
    {
        gender = sgen;
    }
    std::string_view get_gender() const
    {
        return gender;
    }
    // See the access we have to inherited members from Person
    void play()
    {

        m_full_name = "John Snow"; // OK
        m_age = 55;                // OK
        // m_address = "DSAKFD;ASKFJ;DKAS"; Compiler error
    }

private:
    int m_career_start_year{0};
    double m_salary{0.0};
    int health_factor{0}; // Let's say that it's 0~10
    std::string m_game{"None"};
};
Player::Player()
{
    std::cout << "Default constructor for Player called..." << std::endl;
}

Player::Player(std::string_view game_param)
    : m_game(game_param)
{
    // first_name = "John"; Compiler errors
    // last_name = "Snow";
    gender = "Male";
}

std::ostream &operator<<(std::ostream &out, const Player &player)
{

    out << "Player : [ game : " << player.m_game
        << " names : " << player.get_first_name()
        << " " << player.get_last_name()
        << " gender : " << player.get_gender() << "]";
    return out;
}

/*---------------------------------------Nurse Class-----------------------------------------------------------------*/
// Nurse will do protected inheritance
class Nurse : protected Person
{
    friend std::ostream &operator<<(std::ostream &, const Nurse &operand);
    using Person::Person; // Inheriting the constructor

public:
    Nurse();
    Nurse(std::string_view fullname, int age, std::string_view address, int id);
    ~Nurse();

    void treat_unwell_person()
    {
        m_full_name = "John Snow"; // OK
        m_age = 23;                // OK
        // m_address = "897-78-723"; Compiler error
    }

private:
    int practice_certificate_id{0};
};
Nurse::Nurse()
{
}
Nurse::Nurse(std::string_view fullname, int age, std::string_view address, int id)
    : Person(fullname, age, address), practice_certificate_id(id)
{
    std::cout << "Custom constructor for Nurse called..." << std::endl;
}
std::ostream &operator<<(std::ostream &out, const Nurse &operand)
{
    out << "Nurse [Full name : " << operand.get_full_name() << ", age : " << operand.get_age() << ", address : " << operand.get_address()
        << ", practice certificate id : " << operand.practice_certificate_id << "]";
    return out;
}

Nurse::~Nurse()
{
}

/*---------------------------------------Engineer Class-----------------------------------------------------------------*/
// Engineer is doing private inheritance
class Engineer : private Person
{
    friend std::ostream &operator<<(std::ostream &out, const Engineer &operand);

public:
    Engineer();
    Engineer(std::string_view fullname, int age, std::string_view address, int contract_count);
    Engineer(const Engineer &source);
    ~Engineer();

    void build_something()
    {
        m_full_name = "John Snow"; // OK
        m_age = 23;                // OK
        // m_address = "897-78-723"; Compiler error
    }

public:
    using Person::add; // Resurrect to public access

protected:
    using Person::get_address;
    using Person::get_age;
    using Person::get_full_name;
    // using Person::m_address; // Compiler error

    int get_contract_count() const
    {
        return contract_count;
    }

private:
    int contract_count{0};
};
Engineer::Engineer()
{
    std::cout << "Default constructor for Engineer called..." << std::endl;
}

Engineer::Engineer(const Engineer &source)
    : Person(source), contract_count(source.contract_count)
{
    std::cout << "Custom copy constructor for Engineer called..." << std::endl;
}
Engineer::Engineer(std::string_view fullname, int age, std::string_view address, int contract_count_param)
    : Person(fullname, age, address), contract_count(contract_count_param)
{
    std::cout << "Custom constructor for Engineer called..." << std::endl;
}
std::ostream &operator<<(std::ostream &out, const Engineer &operand)
{
    out << "Engineer [Full name : " << operand.get_full_name() << ",age : " << operand.get_age() << ",address : "
        << operand.get_address() << ",contract_count : " << operand.contract_count << "]";
    return out;
}

Engineer::~Engineer()
{
    std::cout << "Destructor for Engineer called ..." << std::endl;
}
/*---------------------------------------Civil Engineer Class-----------------------------------------------------------------*/
class CivilEngineer : public Engineer
{
    friend std::ostream &operator<<(std::ostream &, const CivilEngineer &operand);

public:
    CivilEngineer();
    CivilEngineer(std::string_view fullname, int age, std::string_view address, int contract_count, std::string_view speciality);
    CivilEngineer(const CivilEngineer &source);
    ~CivilEngineer();

    void build_road()
    {
        // get_full_name(); // Compiler error
        /// m_full_name = "Daniel Gray"; //Compiler error
        // m_age = 45; // Compiler error

        add(10, 2);
        add(10, 2, 4);
    }

private:
    std::string m_speciality{"None"};
};
CivilEngineer::CivilEngineer()
{
    std::cout << "Default constructor for CivilEngineer called..." << std::endl;
}
CivilEngineer::CivilEngineer(const CivilEngineer &source)
    : Engineer(source), m_speciality(source.m_speciality)
{
    std::cout << "Custom copy constructor called for CivilEngineer ... " << std::endl;
}
CivilEngineer::CivilEngineer(std::string_view fullname, int age, std::string_view address, int contract_count, std::string_view speciality)
    : Engineer(fullname, age, address, contract_count), m_speciality(speciality)
{
    std::cout << "Custom constructor called for CivilEnginner ... " << std::endl;
}
/*
//BAD : Compiler error - m_address is private to person
CivilEngineer::CivilEngineer(std::string_view fullname,int age,
    std::string_view address,int contract_count, std::string_view speciality)
{
    m_full_name = fullname;
    m_age = age;
    //m_address = address;
    m_speciality = speciality;
    std::cout << "Custom constructor called for CivilEnginner ... " << std::endl;
}
*/

/*
CivilEngineer::CivilEngineer(std::string_view fullname,int age,
    std::string_view address,int contract_count, std::string_view speciality)
    :m_full_name(fullname),m_age(age),m_address(address),m_speciality(speciality)
{

    std::cout << "Custom constructor called for CivilEnginner ... " << std::endl;
}
*/
std::ostream &operator<<(std::ostream &out, const CivilEngineer &operand)
{

    /*
     out << "CivilEngineer [Full name : " << operand.get_full_name() <<
                    ",age : " << operand.get_age() <<
                    //",address : " << operand.get_address() <<
                    ",contract_count : " << operand.contract_count <<
                    ",speciality : " << operand.m_speciality << "]";
                    */

    return out;
}

CivilEngineer::~CivilEngineer()
{
    std::cout << "Destructor called for CivilEngineer ..." << std::endl;
}

/*---------------------------------------Parent Class-----------------------------------------------------------------*/
class Parent
{
public:
    Parent() = default;
    Parent(int member_var) : m_member_var(member_var)
    {
    }
    ~Parent() = default;

    void print_var() const
    {
        std::cout << "The value in parent is : " << m_member_var << std::endl;
    }

protected:
    int m_member_var{100};
};

/*---------------------------------------Child Class-----------------------------------------------------------------*/
class Child : public Parent
{
public:
    Child();
    Child(int member_var) : m_member_var(member_var)
    {
    }
    ~Child() = default;

    void print_var() const
    {
        std::cout << "The value in child is : " << m_member_var << std::endl;
    }

    void show_values() const
    {
        std::cout << "The value in child is :" << m_member_var << std::endl;
        std::cout << "The value in parent is : " << Parent::m_member_var << std::endl;
        // The value in parent must be in accessible scope from the derived class.
    }

private:
    int m_member_var{1000};
};
int main(int argc, char const *argv[])
{
    {
        std::cout << "---------****------------" << std::endl;
        Player p1("Basketball");
        std::cout << "player : " << p1 << std::endl;
        p1.set_first_name("John");
        p1.set_last_name("Snow");
        std::cout << "player : " << p1 << std::endl;
    }
    { // Protected Member
        std::cout << "----------****-----------" << std::endl;
        Player p2("Football");
        std::cout << "player: " << p2 << std::endl;
        p2.set_first_name("Rose");
        p2.set_last_name("Lake");
        p2.set_gender("Female"); // Gender is a protected member and is accessible to the methods in the derived class
        std::cout << "player: " << p2 << std::endl;
    }
    { // Demo
        std::cout << "----------****-----------" << std::endl;
        Person person1("Daniel Gray", 27, "Blue Sky St 233 #56");
        std::cout << "person1 : " << person1 << std::endl;

        std::cout << "---------------" << std::endl;

        Player player;
        player.m_full_name = "Samuel Jackson";
        // player.m_age = 55; Compier error
        // player.m_address = "2i892317322"; Compiler

        std::cout << "------------------" << std::endl;

        Nurse nurse1;
        // nurse1.m_full_name = "Davy Johnes";Compiler error
        // nurse1.m_age = 51; // Compiler error

        std::cout << "---------------" << std::endl;
        Engineer engineer1;
        // engineer1.m_full_name = "Olivier Godson";// Compiler error
        // engineer1.m_age = 55; // Compiler error
        // engineer1.m_address = "dsakfd;aslfjd;laskf";// Compiler error
    }
    { // Private Inheritance
        std::cout << "----------****-----------" << std::endl;
        Engineer eng1;

        CivilEngineer ce1;

        std::cout << "Done" << std::endl;
    }
    { // Default Constructor
        std::cout << "----------****-----------" << std::endl;
        std::cout << "Order of Default Constructor" << std::endl;
        CivilEngineer ce1;
    }
    { // Custom Constructor
        std::cout << "----------****-----------" << std::endl;
        std::cout << "Order of Custom Constructor" << std::endl;
        Person person1("John Snow", 27, "Winterfell Cold 33St#75");
        std::cout << "person1 : " << person1 << std::endl;

        std::cout << "---------------------" << std::endl;
        Engineer eng1("Daniel Gray", 41, "Green Sky Oh Blue 33St#75", 12);
        std::cout << "eng1 : " << eng1 << std::endl;

        std::cout << "---------------------" << std::endl;
        CivilEngineer civil_eng1("John Travolta", 51, "Tiny Dog 42St#89", 31, "Road Strength");
        std::cout << "civil_eng1 : " << civil_eng1 << std::endl;
        CivilEngineer ce1;
    }
    { // Copy Constructors
        std::cout << "----------****-----------" << std::endl;

        Engineer eng1("Daniel Gray", 41, "Green Sky Oh Blue 33St#75", 12);

        std::cout << "----------" << std::endl;

        Engineer eng2(eng1);
        std::cout << "eng2 : " << eng2 << std::endl;

        CivilEngineer eng3("Daniel Gray", 41, "Green Sky Oh Blue 33St#75", 12, "Road Strength");

        std::cout << "----------" << std::endl;

        CivilEngineer eng4(eng3);
        std::cout << "eng4 : " << eng4 << std::endl;
    }
    { // Inheriting Base Constructors
        std::cout << "----------****-----------" << std::endl;
        Nurse nur1("Daniel Gray", 23, "asdl;fkjdas;fkdas;fk", 4);
        std::cout << "nur1 : " << nur1 << std::endl;
        Nurse nur2("Li Quang", 55, "6th Cross Road, James Park"); // This calls the inherited constructors
        std::cout << "nur2 : " << nur2 << std::endl;
    }
    { // Inheritance and Destructors
        std::cout << "----------****-----------" << std::endl;
        std::cout << "Order of Destructors" << std::endl;
        CivilEngineer ce1;
    }
    { // Resued Symbold in Inheritance
        std::cout << "----------****-----------" << std::endl;
        Child child(33);
        child.print_var();         // Calls the method in Child
        child.Parent::print_var(); // Calls the method in Parent,
                                   // value in parent just contains junk or whatever
                                   // in class initialization we did.

        std::cout << "--------" << std::endl;
        child.show_values();
    }
    return 0;
}
