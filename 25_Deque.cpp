/**
 * @Author: Mitul Tyagi
 * @Description: Dqueue in C++
 */
/*
- In C++, the STL dqueue provides the functionality of a queue data structure.
- The dqueue data structure follows the FIFO (First In First Out) principle
where elements that are added first will be removed first.
- The important methods are: front, back, push_front, pop_front, push_back,
pop_back, at, size, empty, swap, emplace_back, emplace_front, resize,
shrink_to_fit, begin, end, clear, insert, emplace, erase, cbegin, cend, rbegin,
rend, crbegin, & crend.
*/
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    // Initializing a List
    deque<int> q;
    // create a dqueue of integer data type
    deque<int> integer_queue;

    // create a dqueue of string data type
    deque<string> string_queue;
    // method 1: initializer list
    deque<int> deque1 = {1, 2, 3, 4, 5};

    // method 2: uniform initialization
    deque<int> deque2{1, 2, 3, 4, 5};

    // fill constructor
    deque<int> deque3(5, 12);

    // copy all elemnts of deque1 to deque4
    deque<int> deque4(deque1.begin(), deque1.end());

    // copy all elements from index 1 to index 2 of deque1 (end point is
    // exclusive)
    deque<int> deque5(deque1.begin() + 1, deque1.begin() + 3);

    for (int num : deque1) {
        cout << num << ", ";
    }
    cout << endl;

    deque<string> animals;

    // push elements into the dqueue
    animals.push_back("Cat");
    animals.push_front("Dog");
    animals.emplace_back("Snake");
    animals.emplace_front("Horse");

    cout << "dqueue: ";

    // print elements of dqueue
    // loop until dqueue is empty
    while (!animals.empty()) {

        // print the element
        cout << animals.front() << ", ";

        // pop element from the dqueue
        animals.pop_back();
    }

    cout << endl;

    // push element into the dqueue
    animals.push_back("Cat");
    animals.push_back("Dog");
    animals.push_back("Fox");

    // remove element from front of dqueue
    animals.pop_front();

    // create a dqueue of int
    deque<int> nums;

    // push element into the dqueue
    nums.push_front(1);
    nums.push_front(2);
    nums.push_front(3);

    // get the element at the front
    int front = nums.front();
    cout << "First element: " << front << endl;

    // get the element at the back
    int back = nums.back();
    cout << "Last element: " << back << endl;
    // create a dqueue of string
    deque<string> lang;

    // push element into the dqueue
    lang.push_back("Python");
    lang.push_front("C++");
    lang.push_back("Java");

    // get the size of the dqueue
    int size = lang.size();
    cout << "Size of the dqueue: " << size;
    cout << endl;

    // create a dqueue of string
    deque<string> languages;

    cout << "Is the dqueue empty? ";

    // check if the dqueue is empty
    if (languages.empty()) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    cout << "Pushing elements..." << endl;

    // push element into the dqueue
    languages.push_back("Python");
    languages.push_front("Ruby");

    cout << "Is the dqueue empty? ";

    // check if the dqueue is empty
    if (languages.empty()) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    cout << endl;

    languages.swap(lang);

    return 0;
}
