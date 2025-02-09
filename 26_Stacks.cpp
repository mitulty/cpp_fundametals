/**
 * @Author: Mitul Tyagi
 * @Description: Queue in C++
 */
/*
- In C++, the STL stack provides the functionality of a stack data structure.
- The stack data structure follows the LIFO (Last In First Out) principle where
elements that are added last will be removed first.
- The important methods are: top, push, pop, size, empty, swap, &
emplace.
*/
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// utility function to display stack elements
void display_stack(stack<string> st) {

    while (!st.empty()) {
        cout << st.top() << ", ";
        st.pop();
    }

    cout << endl;
}
int main(int argc, char const *argv[]) {
    // create a stack of integers
    stack<int> integer_stack;

    // create a stack of strings
    stack<string> string_stack;
    // create a stack of strings
    stack<string> languages;

    // add element to the Stack
    languages.push("C++");
    languages.push("Java");
    languages.push("Python");

    // print top element
    cout << languages.top();
    // create a stack of strings
    stack<string> colors;

    // push elements into the stack
    colors.push("Red");
    colors.push("Orange");

    cout << "Stack: ";

    // print elements of stack
    while (!colors.empty()) {
        cout << colors.top() << ", ";
        colors.pop();
    }
    cout << endl;
    // push elements into the stack
    colors.push("Red");
    colors.push("Orange");
    colors.push("Blue");

    cout << "Initial Stack: ";
    // print elements of stack
    display_stack(colors);

    // removes "Blue" as it was inserted last
    colors.pop();

    cout << "Final Stack: ";

    // print elements of stack
    display_stack(colors);
    // push element into the stack
    colors.push("Red");
    colors.push("Orange");
    colors.push("Blue");

    // get top element
    string top = colors.top();

    cout << "Top Element: " << top;
    cout << endl;
    // create a stack of int
    stack<int> prime_nums;

    // push elements into the stack
    prime_nums.push(2);
    prime_nums.push(3);
    prime_nums.push(5);

    // get the size of the stack
    int size = prime_nums.size();
    cout << "Size of the stack: " << size;
    cout << endl;
    // create a stack of double
    stack<double> nums;

    cout << "Is the stack empty? ";

    // check if the stack is empty
    if (nums.empty()) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    cout << "Pushing elements..." << endl;

    // push element into the stack
    nums.push(2.3);
    nums.push(9.7);

    cout << "Is the stack empty? ";

    // check if the stack is empty
    if (nums.empty()) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    cout << endl;

    return 0;
}
