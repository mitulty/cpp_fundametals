/**
 * @Author: Mitul Tyagi
 * @Description: List in C++
 */
/*
- Lists are sequence containers that allow non-contiguous memory allocation. As
compared to the vector, the list has slow traversal, but once a position has
been found, insertion and deletion are quick (constant time).
- std::list is the class of the List container. It is the part of C++ Standard
Template Library (STL) and is defined inside <list> header file.
- C++ List is a STL container that stores elements randomly in unrelated
locations. To maintain sequential ordering, every list element includes two
links: one that points to the previous element and another that points to the
next element.
- In C++, the STL list implements the doubly-linked list data structure. This
allow iteration in both forward and backward direction. It provides only
sequential access. Random Access to any middle element is not possible.
- List of important member functions of vectors: advance, back, front, empty,
size, data, max_size, swap, push_back, emplace_back, pop_back, push_front,
splice, emplace_front, pop_front,insert, emplace, erase, clear, resize, begin,
end, rbegin, rend, cbegin, cend, crbegin, & crend.
- Functions like sum, sort, reverse and find can also be used using array
iterator.
*/
#include <bits/stdc++.h>
#include <iostream>
#include <list>

using namespace std;

int main(int argc, char const *argv[]) {
    // Initializing a List
    list<int> ls({
        34,
        566,
        6889,
        354,
    });
    list<int> num = {1, 2, 3};

    list<char> vowels = {'a', 'e', 'i', 'o', 'u', 123};

    list<float> real(4, 100.6);

    list<float> zeros(5);

    list<int> ones({1, 1, 1, 1, 1, 1});

    list<float> another_list(real);

    for (auto i : ls)
        cout << i << ' ';
    cout << endl;

    // Inserting at the end
    cout << "-> Inserting at the end: ";
    ls.push_back(23224);
    ls.emplace_back(534);

    for (auto i : ls)
        cout << i << ' ';
    cout << endl;

    // Inserting at the front
    cout << "-> Inserting at the front: ";
    ls.push_front(346);
    ls.emplace_front(5456);

    for (auto i : ls)
        cout << i << ' ';
    cout << endl;

    // Removing from the end
    cout << "-> Pop from the end: ";
    ls.pop_back();

    for (auto i : ls)
        cout << i << ' ';
    cout << endl;

    // Removing from the front
    cout << "-> Pop from the font: ";
    ls.pop_front();

    for (auto i : ls)
        cout << i << ' ';
    cout << endl;

    // Create a list
    list<int> numbers = {1, 2, 3, 4, 5};

    // Create an iterator to point to the first element of the list
    list<int>::iterator itr = numbers.begin();

    // Increment itr to point to the first element
    cout << "-> First Element: " << *itr << endl;

    // Increment itr to point to the 2nd element
    ++itr;

    // Display the 2nd element
    cout << "-> Second Element: " << *itr << endl;

    // Increment itr to point to the 4th element
    ++itr;
    ++itr;

    // Display the 4th element
    cout << "-> Fourth Element: " << *itr << endl;

    // Inserting elements in a list
    cout << "-> Inserting element at front: " << endl;
    numbers.insert(numbers.begin(), 10324);
    for (auto it : numbers)
        cout << it << " ";
    cout << endl;

    numbers.emplace(numbers.begin(), 46768);
    for (auto it : numbers)
        cout << it << " ";
    cout << endl;

    cout << "-> Inserting 3 elements at end, each of value 5346: ";
    numbers.insert(numbers.end(), 3, 5346);
    for (auto it : numbers)
        cout << it << " ";
    cout << endl;

    // Insert [start,end) of one list in other list
    cout << "-> Inserting elements of one list in other list: ";
    numbers.insert(numbers.begin(), ls.begin(), ls.end());
    for (auto it : numbers)
        cout << it << " ";
    cout << endl;

    // Accessing first and last element of a list
    cout << "-> Last element: " << numbers.back() << endl;
    cout << "-> First element: " << numbers.front() << endl;

    // Swapping two lists of same type
    cout << "-> Swapping two lists of same type: " << endl;

    ls.swap(numbers);
    for (auto it : numbers)
        cout << it << " ";
    cout << endl;

    for (auto it : ls)
        cout << it << " ";
    cout << endl;

    // Reverse the List
    cout << "-> Reverse the List: ";
    reverse(ls.begin(), ls.end());

    for (auto i : ls)
        cout << i << " ";
    cout << endl;

    // Sort the List in ascending order
    cout << "-> Sort in Ascending order: ";
    ls.sort();

    for (auto i : ls)
        cout << i << " ";
    cout << endl;

    // Deleting elements from a list
    cout << "-> Erasing element at front: ";
    ls.erase(ls.begin());
    for (auto it : ls)
        cout << it << " ";
    cout << endl;

    auto listitr = ls.begin();
    advance(listitr, 2);

    // Deletes elements from the range [start,end)
    cout << "-> Deleting elements from begin to 2:  ";
    ls.erase(ls.begin(), listitr);
    for (auto it : ls)
        cout << it << " ";
    cout << endl;

    // Clearing a list
    cout << "-> Clearing a list";
    ls.clear();
    cout << endl;

    // Checking if a list is empty
    cout << "-> Is Empty: " << static_cast<bool>(ls.empty()) << endl;

    list<int> l1 = {1, 2, 5};
    list<int> l2 = {4, 3};

    // Put entire list l2 at start of l1
    l1.splice(l1.begin(), l2);

    for (auto i : l1)
        cout << i << " ";
    cout << endl;
    return 0;
}
