/**
 * @Author: Mitul Tyagi
 * @Description: Arrays in STL
 */
/*
- The array is a collection of homogeneous objects and this array container is
defined for constant size arrays or (static size). This container wraps around
fixed-size arrays and the information of its size are not lost when declared to
a pointer. To utilize arrays, the array header is included.
- Accessing elements using [] operator doesn't check for out of bound error.
Another way to access the element of the array is to use the at() method which
checks for out of bound error.
- List of important member functions of arrays: at, back, front, empty, size,
data, fill, max_size, swap, begin, end, rbegin, rend, cbegin, cend, crbegin, &
crend.
- Functions like sum, sort, reverse and find can also be used using array
iterator.
*/
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    // Initializing an Array
    array<int, 5> ar1{3, 4, 5, 1, 2};

    array<int, 5> ar2 = {1, 2, 3, 4, 5};

    array<string, 2> ar3 = {{string("a"), "b"}};

    array<int, 3> num = {1, 2, 3};

    array<char, 6> vowels = {'a', 'e', 'i', 'o', 'u', 123};

    // uniform initialization
    array<int, 5> numbers{1, 2, 3, 4, 5};

    cout << "-> The elements are: ";

    // use a ranged for loop to print the elements
    for (const int num : numbers)
        cout << num << " ";
    cout << endl;

    // Accessing Elements
    // access first array element
    cout << "-> First element: " << numbers[0] << endl; // returns 1

    // access second array element
    cout << "-> Second element: " << numbers[1] << endl; // returns 1

    std::cout << "-> First element: " << numbers.at(0) << endl;  // returns 1
    std::cout << "-> Second element: " << numbers.at(1) << endl; // returns 2
    // std::cout << numbers.at(10); // throws std::out_of_range exception

    // Modifying the Elements
    // modify the 3rd element using []
    numbers[2] = 76;

    // modify the first element using at
    numbers.at(0) = 1;

    // Size of the array
    cout << "-> Size of the array: " << numbers.size() << endl;

    if (numbers.empty()) {
        cout << "-> The array is empty";
    } else {
        cout << "-> The array is not empty";
    }
    cout << endl;

    array<int, 5>::iterator it = numbers.begin();
    cout << "-> First Element of numbers: " << *it << endl;
    it++;
    cout << "-> Second Element of numbers: " << *it << endl;

    array<int, 5> a;

    // fill the array with zeros
    a.fill(0);

    cout << "-> The elements are: ";
    for (const int &elt : a) {
        cout << elt << " ";
    }
    cout << endl;
    array<int, 5> age = {45, 23, 66, 87, 21};

    // Reverse the array
    cout << "-> Reverse the Array: ";
    reverse(age.begin(), age.end());

    for (auto i : age)
        cout << i << " ";
    cout << endl;

    // sorting
    sort(age.begin(), age.end());

    // print the sorted array
    cout << "-> The sorted array is: ";
    for (const int elt : age) {
        cout << elt << " ";
    }
    cout << endl;

    // searching
    // checking whether the number 5  exists or not
    auto found = find(age.begin(), age.end(), 5);

    if (found != age.end())
        cout << "-> 5 was Found" << endl;
    else
        cout << "-> 5 was Not Found" << endl;

    // summing
    int sum = accumulate(age.begin(), age.end(), 0);

    cout << "-> The sum of the element of array is : " << sum << endl;

    std::array<int, 5> acopy = {1, 2, 3, 4, 5};
    // Correct: std::array supports assignment
    std::array<int, 5> b = acopy;

    // Accessing front and back elements
    array<int, 3> arr = {'G', 'f', 'G'}; // ASCII val of 'G' =71
    cout << "-> front: " << arr.front() << " & back: " << arr.back() << endl;

    // Swapping two arrays
    array<int, 3> arr0 = {'G', 'f', 'G'}; // ASCII val of 'G' =71
    array<int, 3> arr1 = {'M', 'M', 'P'}; // ASCII val of 'M' = 77 and 'P' = 80
    arr0.swap(arr1);                      // now arr = {M,M,P}
    cout << "-> front: " << arr0.front() << " & back: " << arr0.back() << endl;

    // Pointer to the first element
    const char *str = "GeeksforGeeks";
    array<char, 13> arrchar;
    memcpy(arrchar.data(), str, 13);
    cout << "-> String: " << arrchar.data() << '\n';
    return 0;
}
