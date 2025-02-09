/**
 * @Author: Mitul Tyagi
 * @Description: Queue in C++
 */
/*
- In C++, the STL queue provides the functionality of a queue data structure.
- The queue data structure follows the FIFO (First In First Out) principle where
elements that are added first will be removed first.
- The important methods are: front, back, push, push_range, pop, size, empty,
swap, & emplace.
*/
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    // Initializing a List
    queue<int> q;
    // create a queue of integer data type
    queue<int> integer_queue;

    // create a queue of string data type
    queue<string> string_queue;
    queue<string> animals;

    // push elements into the queue
    animals.push("Cat");
    animals.push("Dog");
    animals.emplace("Snake");

    cout << "Queue: ";

    // print elements of queue
    // loop until queue is empty
    while (!animals.empty()) {

        // print the element
        cout << animals.front() << ", ";

        // pop element from the queue
        animals.pop();
    }

    cout << endl;

    // push element into the queue
    animals.push("Cat");
    animals.push("Dog");
    animals.push("Fox");

    // remove element from queue
    animals.pop();

    // create a queue of int
    queue<int> nums;

    // push element into the queue
    nums.push(1);
    nums.push(2);
    nums.push(3);

    // get the element at the front
    int front = nums.front();
    cout << "First element: " << front << endl;

    // get the element at the back
    int back = nums.back();
    cout << "Last element: " << back << endl;
    // create a queue of string
    queue<string> lang;

    // push element into the queue
    lang.push("Python");
    lang.push("C++");
    lang.push("Java");

    // get the size of the queue
    int size = lang.size();
    cout << "Size of the queue: " << size;
    cout << endl;
    // create a queue of string
    queue<string> languages;

    cout << "Is the queue empty? ";

    // check if the queue is empty
    if (languages.empty()) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    cout << "Pushing elements..." << endl;

    // push element into the queue
    languages.push("Python");
    languages.push("Ruby");

    cout << "Is the queue empty? ";

    // check if the queue is empty
    if (languages.empty()) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    cout << endl;

    languages.swap(lang);

    return 0;
}
