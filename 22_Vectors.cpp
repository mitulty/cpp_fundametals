/**
 * @Author: Mitul Tyagi
 * @Description: Vectors in C++
 */
/*
- In C++, vectors are used to store elements of similar data types. However,
unlike arrays, the size of a vector can grow dynamically. They are used by
including vector header file.
- The vector resize() changes the size of the vector (i.e., number of elements)
while the vector reserve() changes the capacity (amount of memory allocated) of
the vector. Reducing the size with vector resize() does not release unused
memory. The capacity remains the same. Reserve method can not decrease the
capacity and does not change the size too.
- In C++, vector shrink_to_fit() is a built-in function used to reduce the
capacity of the vector to fit its size and destroys all elements beyond the
size.
- List of important member functions of vectors: at, back, front, empty, size,
capacity, data, max_size, swap, push_back, emplace_back, pop_back, insert,
emplace, erase, resize, reserve, shrink_to_fit, clear, begin, end, rbegin, rend,
cbegin, cend, crbegin, & crend.
- Functions like sum, sort, reverse and find can also be used using vector
iterator.
 */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    // Initializing a vector
    vector<int> v;
    vector<pair<int, int>> vec;

    // vec_five will have 5 elements each initialised to 100
    vector<int> vec_five(5, 100);

    // vec_five_zero will have 5 elements each initialised to 0
    vector<int> vec_five_zero(5);

    // initializing a vector with another vector
    vector<int> vec_another_vec(vec_five_zero);
    vector<int> vec_copy({32, 4576, 8798, 456});

    // Insert an element at the end of a vector
    v.push_back(2);
    v.emplace_back(3);

    vec.push_back({1, 2});
    vec.emplace_back(3, 4);

    // Accessing an element of a vector using index
    cout << "-> Element at index 3: " << vec_copy[3] << endl;
    cout << "-> Element at index 2: " << vec_copy.at(2) << endl;
    // The at() function is preferred zover [] because at() throws an exception
    // whenever the vector is out of bound, while [] gives a garbage value.

    // Accessing first and last element of a vector
    cout << "-> Last element: " << vec_copy.back() << endl;
    cout << "-> First element: " << vec_copy.front() << endl;

    // Size of a vector
    cout << "-> Size of the vector: " << vec_copy.size() << endl;
    cout << "-> Capacity of the vector: " << vec_copy.capacity() << endl;
    {
        vector<int> v = {1, 2, 3, 4, 5};
        cout << "-> Original Vector: ";
        for (auto i : v)
            cout << i << " ";
        cout << endl;

        cout << "-> Resizing to a lower size: ";
        // Vector resized to 3
        v.resize(3);

        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }
    {
        vector<int> v = {1, 4, 6};
        cout << "-> Original Vector: ";
        for (auto i : v)
            cout << i << " ";
        cout << endl;
        // Vector resized to 7 and added elements initialized to 9
        cout << "-> Resizing to a higher size and inserting new elements: ";
        v.resize(7, 9);

        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }
    {
        vector<int> v;
        cout << "-> Original Capacity: " << v.capacity() << endl;

        // Increase the capacity of vector
        v.reserve(9);
        cout << "-> New Capacity after reserving: " << v.capacity() << endl;
    }
    {
        vector<int> v(10);
        cout << "-> Original Capacity: " << v.capacity() << endl;
        v.resize(5);

        // Shrink capacity of vector
        v.shrink_to_fit();

        cout << "-> New Capacity: " << v.capacity() << endl;
    }
    cout << "-> Iterating over a vector of pairs: ";
    for (auto i : vec)
        cout << i.first << " " << i.second << ", ";
    cout << endl;

    for (int i = 0; i < 2; i++)
        cout << vec[i].first << " " << vec[i].second << ", ";
    cout << endl;

    for (int i = 0; i < 2; i++)
        cout << vec.at(i).first << " " << vec.at(i).second << ", ";
    cout << endl;

    // Iterating over a vector
    vector<int> vector_iter = {132,  562,  2353, 467,  5960,
                               3466, 7897, 1248, 99345};
    vector<int>::iterator iter = vector_iter.begin();

    cout << "-> First element: " << *(iter) << endl;
    iter++;
    cout << "-> Second element: " << *(iter) << endl;

    vector<int>::iterator iter_end = vector_iter.end();
    // vector<int>::iterator iter_rend = vector_iter.rend();
    // vector<int>::iterator iter_rbegin  = vector_iter.rbegin();

    cout << "-> Iterating using iterator in a loop: \n";
    for (vector<int>::iterator it = vector_iter.begin();
         it != vector_iter.end(); it++)
        cout << *(it) << " ";
    cout << endl;

    for (auto it = vector_iter.begin(); it != vector_iter.end(); it++)
        cout << *(it) << " ";
    cout << endl;

    cout << "-> Iterating using values in a loop: ";
    for (auto val : vector_iter)
        cout << val << " ";
    cout << endl;

    // Deleting elements from a vector
    cout << "-> Erasing element at position 2: ";
    vector_iter.erase(vector_iter.begin() + 2);
    for (auto it : vector_iter)
        cout << it << " ";
    cout << endl;

    // Deletes elements from the range [start,end)
    cout << "-> Deleting element from begin to end - 3:  ";
    vector_iter.erase(vector_iter.begin(), vector_iter.end() - 3);
    for (auto it : vector_iter)
        cout << it << " ";
    cout << endl;

    // Inserting elements in a vector
    cout << "-> Inserting element at front: " << endl;
    vector_iter.insert(vector_iter.begin(), 10324);
    for (auto it : vector_iter)
        cout << it << " ";
    cout << endl;

    vector_iter.emplace(vector_iter.begin(), 46768);
    for (auto it : vector_iter)
        cout << it << " ";
    cout << endl;

    cout << "-> Inserting 3 elements at end with each of the value 5346: ";
    vector_iter.insert(vector_iter.end(), 3, 5346);
    for (auto it : vector_iter)
        cout << it << " ";
    cout << endl;

    // Insert [start,end) of one vector in other vector
    cout << "-> Inserting elements of one vector in other vector: ";
    vector_iter.insert(vector_iter.begin(), vec_copy.begin(), vec_copy.end());
    for (auto it : vector_iter)
        cout << it << " ";
    cout << endl;

    // Deleting last element of a vector
    cout << "-> Removing last element: ";
    vector_iter.pop_back();
    for (auto it : vector_iter)
        cout << it << " ";
    cout << endl;

    // Swapping two vectors of same type
    cout << "-> Swapping two vectors of same type: " << endl;
    v.swap(vector_iter);
    for (auto it : vector_iter)
        cout << it << " ";
    cout << endl;

    for (auto it : v)
        cout << it << " ";
    cout << endl;

    // Reverse the vector
    cout << "-> Reverse the Vector: ";
    reverse(v.begin(), v.end());

    for (auto i : v)
        cout << i << " ";
    cout << endl;

    // Sort the vector in ascending order
    cout << "-> Sort in Ascending order: ";
    sort(v.begin(), v.end());

    for (auto i : v)
        cout << i << " ";
    cout << endl;

    // Sort the vector in descending order
    cout << "-> Sort in Descending order: ";
    sort(v.begin(), v.end(), greater<>());

    for (auto i : v)
        cout << i << " ";
    cout << endl;

    // Accessing first element of vector v's internal array
    int *ptr = v.data();
    cout << "-> Accessing using a pointer to the first element of a vector: "
         << *vector_iter.data() << endl;

    // v.push_back(32);
    // v.push_back(32);

    // remove duplicates
    // cout << "-> Remove duplicates from a vector: ";
    // unique(v.begin(), v.end());

    // for (auto i : v)
    //   cout << i << " ";
    // cout << endl;

    // Clearing a vector
    cout << "-> Clearing a vector";
    v.clear();
    cout << endl;

    // Checking if a vector is empty
    cout << "-> Is Empty: " << static_cast<bool>(v.empty()) << endl;
    return 0;
}
