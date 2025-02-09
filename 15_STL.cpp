/*
  @Author: Mitul Tyagi
  @Description: Standard Template Library
*/
/*
- The Standard Template Library (STL) is a set of C++ template classes to provide common programming data structures and functions such as lists, stacks, arrays, etc. It is a
  library of container classes, algorithms, and iterators. It is a generalized library and so, its components are parameterized.
- In C++, the Standard Template Library (STL) provides a set of programming tools to implement algorithms and data structures like vectors, lists, queues, etc. The STL is a
  collection of generic classes and functions which enables the programmer to implement data structures like linked lists, queues, stacks, etc. and algorithms like sorting,
  searching, etc. in a highly reusable and efficient way.
- STL provides a way to write generic, reusable code that can be applied to different data types.
- STL has the following important components:
    a) Algorithms: The STL provides a range of algorithms, such as sort, find, and binary_search, which can be used to manipulate data stored in containers.
    b) Containers: The STL provides a range of containers, such as vector, list, map, set, and stack, which can be used to store and manipulate data.
    c) Iterators:  These are objects that provide a way to traverse the elements of a container.
    d) Functors: Function objects, also known as functors, are objects that can be used as function arguments to algorithms. They provide a way to pass a function to an algorithm,
                 allowing to customize its behavior.
    e) Adapters: Adapters are components that modify the behavior of other components in the STL. For example, the reverse_iterator adapter can be used to reverse the order of
                 elements in a container.
- The header algorithm defines a collection of functions specially designed to be used on a range of elements. They act on containers and provide means for various operations for
  the contents of the containers.
- STL containers store data and organize them in a specific manner as required. They are implemented as class templates, which allows a great flexibility in the types used as
  elements in the container. STL containers are implemented as generic classes, which means that a single class can be used for different types of data. They are classified into
  three categories: Sequence Containers, Associative Containers, and Unordered Associative Containers.
- The Sequence Containers in STL are vector, list, stack, deque, queue, arrays, and forward_list. These containers implement data structures that can be accessed in a sequential manner.
- The Associative Containers in STL are set, multiset, map, and multimap. These containers implement sorted data structures that can be quickly searched. These are implemented using
  binary search trees.
- The Unordered Associative Containers in STL are unordered_set, unordered_multiset, unordered_map, and unordered_multimap. These containers implement unordered data structures that
  can be quickly searched. These are implemented using hash tables.
- Iterators are objects that are used to access elements of a container. Iterators are used to point at the memory addresses of STL containers. They are primarily used in sequence
  of numbers, characters etc. and used to point at the memory addresses of STL containers.
- STL algorithms are a collection of functions especially designed to be used on ranges of elements. These functions act on containers and provide means for various operations for
  the contents of the containers. Some of the commonly used algorithms are sort(), binary_search(), reverse(), count(), find(), etc. These algorithms are used to perform operations
  on the elements of the containers.
*/
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
  /* code */
  cout << "---------------------------------------" << endl;
  cout << "Pairs in C++" << endl;
  pair<int, int> p = {1.3, 3};
  cout << "Pair values are: " << p.first << " and " << p.second << endl;

  pair<int, pair<int, float>> double_pair = {1, {1, 3.3}};
  cout << "Pair values are: " << double_pair.first << ", " << double_pair.second.first << " and " << double_pair.second.second << endl;

  pair<int, int> arr[] = {{1, 2}, {3, 4}, {5, 6}};
  for (auto i : arr)
  {
    cout << i.first << "," << i.second << " ";
  }
  cout << endl;
  return 0;
}
