/*
  @Author: Mitul Tyagi
  @Date:   2023-10-24 12:00:22
  @Description: Statements and Control Flow
*/
/*
- A statement does not have a value. They are used to specify the order of execution. A declaration is a statement and an expression becomes a statement when
  a semicolon is added at the end.
- A statment is a basic unit of computation in a C++. Every C++ program is a collection of statements organized in a certain way. Statements end with a
  semicolon in C++.
- A semicolon is by itself a statement, the empty statement.
- A sequence of statements within "curly braces" is called a block or a compound statement. A name declared in a block goes out of scope at the end of its block.
- A declaration is a statement and there is no assignment statement or procedural-call statement; assignments and function calls are expression. A
  for-init-statement must be either a declaration or an expression-statement. A for-init-declaration must be the declaration of a single uninitialized variable.
- Following are the satements in C++:
                                                    declaraton
                                                    expression;
                                                    {statement-list}
                                                    try { statement-list} handler-list
                                                    case constant expression: statement
                                                    default: statement
                                                    break;
                                                    continue;
                                                    return expression;
                                                    goto identifier;
                                                    identifier: statement
                                                    selection-statement:
                                                        if ( condition ) statement
                                                        if ( condition ) statement else statement
                                                        switch ( condition ) statement
                                                    iteration-statement:
                                                        while ( condition ) statement
                                                        do statement while ( expression );
                                                        for ( for-init-statement; condition; expression ) statement
                                                        for ( for-init-declaration: expression ) statement
                                                    statement-list:
                                                        expression
                                                        type-specifier declarator = expression
                                                        type-specifier declarator { expression }
                                                    handler-list:
                                                        handler handler-list
                                                    handler:
                                                        catch ( exception-declaration ){ statement-list}
- The conditional statements (also known as decision control structures) such as if, if else, switch, etc. are used for decision-making. A value can be
  tested by either an if-statement or a switch statement. A condition is either an expression or a declaration. In an if-statement , the first (or only)
  statement is executed if the condition is true and the second statement (if it is specified) is expected otherwise. If a condition evaluates to something
  different from a Boolean, it is -if possible- implicitly converted to a bool. This implies that any arithmetic or pointer expression can be used as a
  condition. A plain enum can be implicitly converted to an integer and then to a bool, whereas enum class cannot.
- The logical operators ( && || ! ) are most commonly used in conditions. A name can only be used within the scope in which it is declared. In particular,
  it can not be used on another branch of an if-statement.
- The switch-statement selects among a set of alternatives (case-labels). The expression in the case labels must be a constant expression of integral or
  enumration type. A value may not be used more than once for case-labels in a switch-statement. It can alternatively be written as a set of if-statements.
  A case of a switch must be terminated somehow unless execution is to be carried of the next case. A break is the most common way of terminating a case,
  but a return is often useful. A default is optional and should be used to handle the most common case.
- It is possible, and common, to declare variables within the block of a switch-statement. However, it is not possible to bypass an initialization. The switch
  statment has a single scope and variables can be declared anywhere in the statment but initialization will cause compilation error(except for the lase case).
- It is a good idea to declare a variable in a condition. The scope of the declared variable extends from its point of declaration to the end of the statement
  that the condition controls. A declaration in a condition must declare and initialize a single variable or const.
- The ternary or conditional operator ( ? : ) is the shortest form of writing conditional statements. It can be used as an inline conditional statement in place
  of if-else to execute some conditional code. The type of statement_1 and statement_2 should match or should be convertible with the expression.
                                expression ? statement_1 : statement_2;
- "if constexpr" construct allows to do conditional excution at compile time rather than during run time. The condition must be a const or constexpr as it
  must be evaluated at compile time. The branch which fails will be dropped and will not be available in the binary.
- A loop can be expressed as a for-, while-, or do-statement. A for-init-statement must be either a declaration or an expression-statement. The statement of
  a for-statement (called the controlled statement or the loop body) is executed repeatedly until the condition becomes false or the program breaks out of the
  loop some other way (such as a break, a return, a thrown or a goto).
- The simplest loop is a range-for-statement; it simply gives the access to each element of a range. The scope of the variable naming the element is the
  for-statement. The expression after the colon must denote a sequence (a range); that is, it must yield a value for which v.begin() and v.end() or begin(v)
  and end(v) obtain iterators. To modify an element in a range-for loop, the element should be a reference. They are also appropriate for elements that
  might be large, so that copying them to the element value could be costly. The iterator variable has the scope of for loop.
- The more general for-statement has loop variables, the termination condition, and the expression that updates the loop variable. A variable can be declared
  in the intializer part of a for-statement. If that intitializer is a declaration. the variable (or variables) it introduced is in scope until the end of the
  for-statement. It is not always obvious what is the right type to use for a controlled variable in a for loop, so "auto" often comes in handy.
- If the final value of an index needs to be known after exit from a for-loop, the index variable must be declared outside the for-loop. If no initialization
  is needed, the initializing statement can be empty. If the exression that is supposed to increment the loop variable is omitted, it must be updated
  elsewhere. A for statement is also useful for expressing a loop without an explicit termination condition.
- A while-statement executes its controlled statement until its condition becomes fales. A for-statement is easily rewritten into an equivalent while-statement
  and vice-versa.
- A do-while statement checks the condition after the body.
- If the condition of an iteration satement is omitted, the loop will not terminate unless the user exlplicitly exits by a break,return, goto, throw or some
  less obvious ways such as call of exit().
- A "break" breaks out of the nearest (innermost) enclosing switch-statement or iteration statement. A "continue" skips the rest of the body of an
  iteration-statement. After a "continue", the increment part of the loop (if any) is executed, followed by the loop condition (if any).
- The goto statement transfers the control to the labeled statement. The scope of a label is the function it is in. Thus goto can be used to jump both
  into and out of blocks. The only restriction is that it can not jump past an intializer or into an exception handler. One of the usage is to break out
  from a nested loop or switch-statement.
                                goto identifier;
                                identifier: statement
- Multi-line style comments do not nest.
- Use std::getline(std::cin >> std::ws, str_var_name) to get string input from console.
*/
#include <iostream>
#include <iomanip>

using namespace std;
void findElement(int arr[], int size, int key)
{
    // loop to traverse array and search for key
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            std::cout << "Element found at position: " << (i + 1) << std::endl;
            break;
        }
    }
}

void printNumbers()
{
    int n = 1;
label:
    std::cout << n << " ";
    n++;
    if (n <= 10)
        goto label;
    std::cout << std::endl;
}

int SUM(int a, int b)
{
    int s1 = a + b;
    return s1;
}

// returns void
// function to print
void Print(int s2)
{
    std::cout << "The sum is " << s2 << std::endl;
    return;
}

int main(int argc, char const *argv[])
{
    {
        int i = 10;
        int var = 2;
        int flag = 0;

        if (i > 15)
        {
            std::cout << "10 is greater than 15" << std::endl;
        }

        std::cout << "I am Not in if" << std::endl;

        if (i < 15)
        {

            std::cout << "i is smaller than 15" << std::endl;
        }
        else
        {

            std::cout << "i is greater than 15" << std::endl;
        }
        if (i == 10)
        {
            // First if statement
            if (i < 15)
                std::cout << "i is smaller than 15" << std::endl;

            // Nested - if statement
            // Will only be executed if statement above
            // is true
            if (i < 12)
                std::cout << "i is smaller than 12 too " << std::endl;
            else
                std::cout << "i is greater than 15" << std::endl;
        }
        if (i == 10)
            std::cout << "i is 10" << std::endl;
        else if (i == 15)
            std::cout << "i is 15" << std::endl;
        else if (i == 20)
            std::cout << "i is 20" << std::endl;
        else
            std::cout << "i is absent" << std::endl;

        // declaring switch cases
        switch (var)
        {
        case 1:
            std::cout << "Case 1 is executed" << std::endl;
            break;
        case 2:
            std::cout << "Case 2 is executed" << std::endl;
            break;
        default:
            std::cout << "Default Case is executed" << std::endl;
            break;
        }

        // using conditional operator to assign the value to var
        // according to the value of flag
        var = flag == 0 ? 25 : -25;
        std::cout << "Value of var when flag is 0 " << var << std::endl;

        // changing the value of flag
        flag = 1;
        // again assigning the value to var using same statement
        var = flag == 0 ? 25 : -25;
        std::cout << "Value of var when flag is NOT 0 " << var << std::endl;

        int arr[] = {1, 2, 3, 4, 5, 6};

        // no of elements
        int n = 6;

        // key to be searched
        int key = 3;

        // Calling function to find the key
        findElement(arr, n, key);

        // loop from 1 to 10
        for (int i = 1; i <= 10; i++)
        {

            // If i is equals to 6,
            // continue to next iteration
            // without printing
            if (i == 6)
                continue;

            else
                // otherwise print the value of i
                std::cout << i << " ";
        }
        std::cout << std::endl;
        printNumbers();

        int num1 = 10;
        int num2 = 10;
        int sum_of = SUM(num1, num2);
        Print(sum_of);
    }
    {
        int condition{3}; // With condition {1} it will run only the case 1 statements.

        int my_var{4};

        switch (int data{7}; condition)
        {
            // int x1{9}; // This will not work:  error: jump to case label |  crosses initialization of ‘int x1’ . Never going to run
            int x;
        case 0:
            // int y1 {5}; // This will not work:  error: jump to case label |  crosses initialization of ‘int y1’ .  Never going to run
            int y;
            x = 6;
            x++;
            y = 10;
            // z =6;  // z was not declared in this scope
            std::cout << "x : " << x << std::endl;
            std::cout << "y : " << y << std::endl;
            std::cout << "Statement1" << std::endl;
            std::cout << "Statement2" << std::endl;
            std::cout << "data" << data << std::endl;
            break;
        default:
            // int u{56}; // This will not work:  error: jump to case label |  crosses initialization of ‘int u’
            std::cout << "Statement5" << std::endl;
            std::cout << "Statement6" << std::endl;
            std::cout << "data" << data << std::endl;
            // break; // This will cause case 1 staments to run after the default statments
        case 1:
            int z;
            my_var++;
            y = 5;
            int vt{56}; // This will work
            std::cout << "y : " << y << std::endl;
            std::cout << "Statement3" << std::endl;
            std::cout << "Statement4" << std::endl;
            std::cout << "data" << data << std::endl;
            break;
        }
        std::cout << "Moving on..." << std::endl;
    }
    {
        int x{10};
        std::cout << std::endl;

        std::string message;
        message = (x % 2 == 0) ? " is Even" : " is Odd";
        std::cout << x << message << std::endl;
    }
    { // if constexpr
        constexpr bool condition{false};
        if constexpr (condition)
            std::cout << "Condition is true" << std::endl;
        else
            std::cout << "Condition is false" << std::endl;
    }
    { // with if initializer
        bool go{true};

        if (int speed{10}; go)
        {
            std::cout << "speed : " << speed << std::endl;

            if (speed > 5)
            {
                std::cout << "Slow down!" << std::endl;
            }
            else
            {
                std::cout << "All good!" << std::endl;
            }
        }
        else
        {
            std::cout << "speed : " << speed << std::endl;
            std::cout << "Stop" << std::endl;
        }

        // std::cout << "Out of the if block , speed : " << speed << std::endl;
    }
    { // with switch initializer
        const int Pen{10};
        const int Marker{20};
        const int Eraser{30};
        const int Rectangle{40};
        const int Circle{50};
        const int Ellipse{60};
        int tool{Eraser};

        switch (double strength{3.56}; tool)
        {
        case Pen:
        {
            std::cout << "Active tool is Pen. strength : " << strength << std::endl;
        }
        break;

        case Marker:
        {
            std::cout << "Active tool is Marker. strength : " << strength << std::endl;
        }
        break;

        case Eraser:
        {
            std::cout << "Active tool is Eraser. strength : " << strength << std::endl;
        }
        break;
        case Rectangle:
        case Circle:
        case Ellipse:
        {
            std::cout << "Drawing Shapes. strength : " << strength << std::endl;
        }
        break;
        default:
        {
            std::cout << "No match found. strength : " << strength << std::endl;
        }
        break;
        }

        std::cout << "Moving on" << std::endl;
        // strength++;
    }
    { // scope in a switch statment
        int condition{0};

        int my_var{4};

        switch (int data{7}; condition)
        {
            // int x{9}; // Never going to run and thus a compile run.
            int x;
        case 0:

            // int y {5}; // Compile error
            int y;
            x = 6;
            x++;
            y = 14;
            // z =6; // must be declared first
            std::cout << "x : " << x << std::endl;
            std::cout << "Statement1" << std::endl;
            std::cout << "Statement2" << std::endl;
            break;

        case 1:
            int z;
            my_var++;
            y = 5;
            std::cout << "y : " << y << std::endl;
            std::cout << "Statement3" << std::endl;
            std::cout << "Statement4" << std::endl;
            break;

        default:
            int u;
            int xt{8}; // OK
            z = 10;
            std::cout << "Statement5" << std::endl;
            std::cout << "Statement6" << std::endl;
            break;
        }
        std::cout << "Moving on..." << std::endl;
    }
    {
        // for (unsigned int i{};i<5;++i) // iterator;test;update{body}
        for (size_t i{}; i < 5; ++i) // iterator;test;updation{body}
            std::cout << " Simple Loop in C++ when i: " << i << std::endl;
        // Only a single test statement. Also, the iterator variables have to be of the same type in the declarator part
        for (int i = 0, j = 10, k = 20; (i < 10, j < 23); j++, k--, i += k)
        {
            std::cout << i << " " << j << " " << k << std::endl;
        }
    }
    {
        int bag_of_values[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // This is a collection of integers
                                                            // The variable value will be assigned a value from the values array on each iteration
        for (int i = 1; i <= 5; i++)
        {
            std::cout << "Hello World" << std::endl;
        }

        for (int i = 0, j = 10, k = 20; (i + j + k) < 100; j++, k--, i += k)
        {
            std::cout << i << " " << j << " " << k << std::endl;
        }

        int arr[]{40, 50, 60, 70, 80, 90, 100};
        for (auto element : arr)
        {
            std::cout << element << " ";
        }
        for (auto &element : arr)
        {
            element += 2354;
        }
        std::cout << std::endl;

        for (size_t i{0}; i < 10; ++i)
        {
            std::cout << "value : " << bag_of_values[i] << std::endl;
        }

        for (int value : bag_of_values)
        {
            // value holds a copy of the current iteration in the whole bag
            std::cout << " value : " << value << std::endl;
        }

        // Specify the collection in place

        for (int value : {1, 2, 3, 4, 5, 6, 7, 8, 9, 10})
        {
            // value holds a copy of the current iteration in the whole bag
            std::cout << " value : " << value << std::endl;
        }

        // Auto type deduction
        for (auto value : {1, 2, 3, 4, 5, 6, 7, 8, 9, 10})
        {
            // value holds a copy of the current iteration in the whole bag
            std::cout << " value : " << value << std::endl;
        }

        int i = 1;

        // test expression
        while (i < 6)
        {
            std::cout << "Hello World" << std::endl;

            // update expression
            i++;
        }
        i++;
        do
        {
            // loop body
            std::cout << "Hello World" << std::endl;

            // update expression
            i++;

        } while (i < 1); // test expression
    }

    { // Nested Loops
        // Setw on numbers before you print them
        const size_t ROWS{12};
        const size_t COLS{3};

        std::cout << "Tabular data visualization with nested for loops : " << std::endl;

        for (size_t row{0}; row < ROWS; ++row)
        {

            for (size_t col{0}; col < COLS; ++col)
            {

                std::cout << "( row " << std::setw(2) << row << ",col " << std::setw(2) << col << ")  ";
            }
            std::cout << std::endl;
        }

        // While loop

        std::cout << std::endl;
        std::cout << "Tabular data visualization with nested while loops : " << std::endl;

        // Remember to reset col to 0 after the inner loop is done for the next row
        //  to use the right columns.
        size_t row{0};
        size_t col{0};

        while (row < ROWS)
        {

            while (col < COLS)
            {
                std::cout << "( row " << std::setw(2) << row << ",col " << std::setw(2) << col << ") ";
                ++col;
            }
            std::cout << std::endl;
            col = 0; // Reset col to 0 to allow printing from col 0 . col is in main
                     // function local scope now.
            ++row;
        }

        std::cout << std::endl;
        std::cout << "Tabular data visualization with nested do while loops : " << std::endl;

        row = 0;
        col = 0;

        do
        { // row

            do
            {
                std::cout << "( row " << std::setw(2) << row << ",col " << std::setw(2) << col << ")   ";
                ++col;
            } while (col < COLS);

            std::cout << std::endl;
            col = 0; // Reset col to 0 to allow printing from col 0 . col is in main
                     // function local scope now.
            ++row;
        } while (row < ROWS);
    }
    { // break and continue

        // break and continue : for loops
        const size_t COUNT{20};

        for (size_t i{0}; i < COUNT; ++i)
        {

            if (i == 5)
                continue;

            if (i == 11)
                break; // Breaks out of the loop
            std::cout << "i : " << i << std::endl;
        }
        std::cout << "For Loop done!" << std::endl;

        // break and continue : while loop
        size_t i{0};

        while (i < 20)
        {

            if (i == 5)
            {
                ++i;
                continue;
            }

            if (i == 11)
                break;

            std::cout << "i : " << i << std::endl;
            ++i;
        }
        std::cout << "While Loop done!" << std::endl;

        // break and continue : do while loop
        i = 0;

        do
        {
            if (i == 5)
            {
                ++i;
                continue;
            }

            if (i == 11)
                break;

            std::cout << "i : " << i << std::endl;
            ++i;

        } while (i < 20);
        std::cout << "Do While Loop done!" << std::endl;
    }
    {
        // Range based for loop with initializer
        for (double multiplier{4}; auto i : {1, 2, 3, 4, 5, 6, 7, 8, 9, 10})
        {
            std::cout << "result : " << (i * multiplier) << std::endl;
        }
    }
    return 0;
}
/*
I am Not in if
i is smaller than 15
i is smaller than 15
i is smaller than 12 too
i is 10
Case 2 is executed
Value of var when flag is 0 25
Value of var when flag is NOT 0 -25
Element found at position: 3
1 2 3 4 5 7 8 9 10
1 2 3 4 5 6 7 8 9 10
The sum is 20
Statement5
Statement6
data7
y : 5
Statement3
Statement4
data7
Moving on...

10 is Even
Condition is false
speed : 10
Slow down!
Active tool is Eraser. strength : 3.56
Moving on
x : 7
Statement1
Statement2
Moving on...
 Simple Loop in C++ when i: 0
 Simple Loop in C++ when i: 1
 Simple Loop in C++ when i: 2
 Simple Loop in C++ when i: 3
 Simple Loop in C++ when i: 4
0 10 20
19 11 19
37 12 18
54 13 17
70 14 16
85 15 15
99 16 14
112 17 13
124 18 12
135 19 11
145 20 10
154 21 9
162 22 8
Hello World
Hello World
Hello World
Hello World
Hello World
0 10 20
19 11 19
37 12 18
54 13 17
40 50 60 70 80 90 100
value : 1
value : 2
value : 3
value : 4
value : 5
value : 6
value : 7
value : 8
value : 9
value : 10
 value : 1
 value : 2
 value : 3
 value : 4
 value : 5
 value : 6
 value : 7
 value : 8
 value : 9
 value : 10
 value : 1
 value : 2
 value : 3
 value : 4
 value : 5
 value : 6
 value : 7
 value : 8
 value : 9
 value : 10
 value : 1
 value : 2
 value : 3
 value : 4
 value : 5
 value : 6
 value : 7
 value : 8
 value : 9
 value : 10
Hello World
Hello World
Hello World
Hello World
Hello World
Hello World
Tabular data visualization with nested for loops :
( row  0,col  0)  ( row  0,col  1)  ( row  0,col  2)
( row  1,col  0)  ( row  1,col  1)  ( row  1,col  2)
( row  2,col  0)  ( row  2,col  1)  ( row  2,col  2)
( row  3,col  0)  ( row  3,col  1)  ( row  3,col  2)
( row  4,col  0)  ( row  4,col  1)  ( row  4,col  2)
( row  5,col  0)  ( row  5,col  1)  ( row  5,col  2)
( row  6,col  0)  ( row  6,col  1)  ( row  6,col  2)
( row  7,col  0)  ( row  7,col  1)  ( row  7,col  2)
( row  8,col  0)  ( row  8,col  1)  ( row  8,col  2)
( row  9,col  0)  ( row  9,col  1)  ( row  9,col  2)
( row 10,col  0)  ( row 10,col  1)  ( row 10,col  2)
( row 11,col  0)  ( row 11,col  1)  ( row 11,col  2)

Tabular data visualization with nested while loops :
( row  0,col  0) ( row  0,col  1) ( row  0,col  2)
( row  1,col  0) ( row  1,col  1) ( row  1,col  2)
( row  2,col  0) ( row  2,col  1) ( row  2,col  2)
( row  3,col  0) ( row  3,col  1) ( row  3,col  2)
( row  4,col  0) ( row  4,col  1) ( row  4,col  2)
( row  5,col  0) ( row  5,col  1) ( row  5,col  2)
( row  6,col  0) ( row  6,col  1) ( row  6,col  2)
( row  7,col  0) ( row  7,col  1) ( row  7,col  2)
( row  8,col  0) ( row  8,col  1) ( row  8,col  2)
( row  9,col  0) ( row  9,col  1) ( row  9,col  2)
( row 10,col  0) ( row 10,col  1) ( row 10,col  2)
( row 11,col  0) ( row 11,col  1) ( row 11,col  2)

Tabular data visualization with nested do while loops :
( row  0,col  0)   ( row  0,col  1)   ( row  0,col  2)
( row  1,col  0)   ( row  1,col  1)   ( row  1,col  2)
( row  2,col  0)   ( row  2,col  1)   ( row  2,col  2)
( row  3,col  0)   ( row  3,col  1)   ( row  3,col  2)
( row  4,col  0)   ( row  4,col  1)   ( row  4,col  2)
( row  5,col  0)   ( row  5,col  1)   ( row  5,col  2)
( row  6,col  0)   ( row  6,col  1)   ( row  6,col  2)
( row  7,col  0)   ( row  7,col  1)   ( row  7,col  2)
( row  8,col  0)   ( row  8,col  1)   ( row  8,col  2)
( row  9,col  0)   ( row  9,col  1)   ( row  9,col  2)
( row 10,col  0)   ( row 10,col  1)   ( row 10,col  2)
( row 11,col  0)   ( row 11,col  1)   ( row 11,col  2)
i : 0
i : 1
i : 2
i : 3
i : 4
i : 6
i : 7
i : 8
i : 9
i : 10
For Loop done!
i : 0
i : 1
i : 2
i : 3
i : 4
i : 6
i : 7
i : 8
i : 9
i : 10
While Loop done!
i : 0
i : 1
i : 2
i : 3
i : 4
i : 6
i : 7
i : 8
i : 9
i : 10
Do While Loop done!
result : 4
result : 8
result : 12
result : 16
result : 20
result : 24
result : 28
result : 32
result : 36
result : 40
*/