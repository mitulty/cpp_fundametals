/**
 * @Author: Mitul Tyagi
 * @Description: Maps, Multimap, Unordered_map & Unordered_multimap in C++
 */
/*
- In C++, maps are associated containers that hold pairs of data.
- These pairs, known as key-value pairs, have a unique key, while the associated
values don't have to be unique.
- The elements in a map are internally sorted by their keys.
- The map structure is implemented using the BST.
- The important methods are: at, clear, count, emplace, emplace_hint, empty,
equal_range, erase, extract, find, insert, key_comp, lower_bound, max_size,
size, swap, upper_bound, value_comp, try_emplace, merge, begin, end, cbegin,
cend, rbegin, rend, crbegin, & crend.
- The emplace_hint methods inserts a new element into the container as close as
possible to the position just before hint.
- The try_emplace method will not construct the object associated with the key,
if the key already exists.
- The std::map::count() in C++ is a built-in function that is used to count the
occurrence of the given key in the map container. It is the member function of
the std::map container. It returns 1 if the key is present else 0.
- The std::map::value_comp() is a function in C++ STL. It returns a function
object that compares objects of type std::map::value.
- The std::map::lower_bound() is a built-in method used to find the first
element in the map whose key is either equal to or greater than the given key.
- The std::map::upper_bound() is a built-in function in C++ STL which returns an
iterator pointing to the immediate next element just greater than k. If the key
passed in the parameter exceeds the maximum key in the container, then the
iterator returned points to the number of elements in the map container as key
and element=0.

- In C++, the STL unordered_map is an unordered associative container that
provides the functionality of an unordered map or dictionary data structure.
- In contrast to a regular map, the order of keys in an unordered map is
undefined.
- Also, the unordered map is implemented as a hash table data structure whereas
the regular map is a binary search tree data structure.
- Along with map methods, unordered_map has methods for hashing and bucket list
which are important for hash table implementation. These are: bucket,
bucket_count, bucket_size, hash_function, keq_eq, load_factor, max_bucket_count,
max_load_factor, max_size, rehash, & reserve.
- Unordered_map is an associated container that stores elements formed by the
combination of key-value and a mapped value. The key value is used to uniquely
identify the element and the mapped value is the content associated with the
key. Both key and value can be of any type predefined or user-defined.
- Bucket: Internally, unordered_map is implemented using a hash table so, a
bucket is a slot in the internal hash Table to which elements are assigned based
on the hash value of their key. Buckets are numbered from 0 to (bucket_count-1).
- The bucket() function is part of the C++ unordered_map container. It returns
the bucket number (zero-indexed) where a specified element is located within the
unordered map.
- std::bucket_count: This function is used to count the total no. of buckets in
the unordered_map. No parameter is required to pass into this function.
- std::bucket_size: This function count the number of elements present in each
bucket of the unordered_map.
- load_factor: Returns the current load factor in the unordered_map container.
The load factor is the ratio between the number of elements in the container
(its size) and the number of buckets (bucket_count):
load_factor = size / bucket_count
- The load factor influences the probability of collision in the hash table
(i.e., the probability of two elements being located in the same bucket). The
container automatically increases the number of buckets to keep the load factor
below a specific threshold (its max_load_factor), causing a rehash each time an
expansion is needed.
- To retrieve or change this threshold, the member function max_load_factor is
used.
- unordered_set::max_load_factor() is a function in C++ STL which returns(Or
sets) the current maximum load factor of the unordered set container. The load
factor is the ratio between number of elements in the container and number of
buckets(bucket_count). By default the maximum load factor of an unordered set
container is set to 1.0.
- The std::unordered_map::rehash() is a built in function C++ STL which sets the
number of buckets in container to n or more.
- The keq_eq method returns the key comparison object with which the
unordered_map was constructed.
- The hash_function method will return the hash functor object with which the
Unordered_map was constructed.
- The C++ function std::unordered_map::reserve() sets the number of buckets in
the container (bucket_count) to the most appropriate to contain at least n
elements.0

- The multimap and unordered_multimap variants store multiple duplicate keys.
They have the similar methods and functions to corresponding map and
unordered_map.

- Structure bindings, introduced in C++17, provide a way to unpack the elements
of a std::pair (which is what a std::map stores) directly into named variables
within a range-based for loop.
*/
#include <bits/stdc++.h>
#include <functional>
#include <iostream>
#include <string>
#include <utility>

using namespace std;

// function prototype for display_unordered_map()
void display_unordered_map(const unordered_map<int, string> &);

// function prototype for display_multimap()
void display_multimap(const multimap<int, string> &);

int main(int argc, char const *argv[]) {

    //----------------------------------------Map-----------------------------------
    // create a map with integer keys and string values
    cout << "---------------------std::map----------------------\n";
    cout << "-> Initializing using opeartor=\n";
    std::map<int, string> student = {
        {1, "Jacqueline"}, {2, "Blake"}, {3, "Chang"}};

    for (auto i : student)
        cout << " " << i.first << " : " << i.second << endl;

    std::map<int, string, greater<int>> people{
        {1, "Jacqueline"}, {2, "Blake"}, {3, "Denise"}};

    for (auto i : people)
        cout << " " << i.first << " : " << i.second << endl;

    // create a map with integer keys and string values
    std::map<int, string> stud;

    // add element with key 1 and value "Jacqueline"
    stud[1] = "Jacqueline";

    // add element with key 2 and value "Blake"
    stud[2] = "Blake";

    student.insert(std::make_pair(4, "Denise"));
    student.insert(std::pair<int, std::string>(7, "Sen"));
    student.emplace(5, "John");

    // add elements with duplicate keys
    student[6] = "Timothy";
    student.insert_or_assign(1, "Hans");
    student[6] = "Aaron";

    // Accessing using [] and at
    cout << "-> Accessing using [] and at()\n";
    for (int i = 1; i <= student.size(); ++i) {
        cout << " Student[" << i << "]: " << student[i] << endl;
    }

    cout << " " << student[1] << endl;
    cout << " " << student.at(4) << endl;
    const auto [key, value] = std::make_pair(5, "hello");
    cout << " " << key << ": " << value << endl;
    // Initializing a container
    map<string, string> m;

    // Inserting elements in random order
    m.try_emplace("a", "123");
    m.try_emplace("b", "456");
    m.try_emplace("a", "Won't be inserted");
    m.try_emplace("c", "789");
    m.try_emplace("c", "Won't be inserted");

    // Print the elements
    cout << "-> Accessing using loops\n";
    cout << " The map is : \n";
    cout << " KEY\tELEMENT\n";

    // Accessing element
    for (auto p : m) {
        cout << " " << p.first << "\t" << p.second << endl;
    }

    // initialize container
    map<int, int> mp;

    // insert elements in random order
    mp.emplace_hint(mp.begin(), 2, 30); // faster
    mp.emplace_hint(mp.begin(), 1, 40); // faster
    mp.emplace_hint(mp.begin(), 3, 60); // slower

    cout << "-> Accessing using iterators\n";
    // prints the elements
    cout << " The map is : \n";
    cout << " KEY\tELEMENT\n";
    for (auto itr = mp.begin(); itr != mp.end(); itr++)
        cout << " " << itr->first << "\t" << itr->second << endl;

    // declare map iterator
    map<int, string>::iterator iter;

    // use iterator to display map elements
    for (iter = student.begin(); iter != student.end(); ++iter) {
        cout << " " << iter->first << " - " << iter->second << endl;
    }

    iter = student.begin();

    // Output: 1
    cout << " " << (*iter).first << " - ";
    cout << iter->second;
    cout << endl;

    std::map<string, string> country_code = {
        {"IN", "INDIA"}, {"US", "USA"}, {"GER", "GERMANY"}};

    cout << " " << country_code["IN"] << endl;
    cout << " " << country_code["GER"] << endl;

    // Accessing element
    for (auto p : country_code) {
        cout << " " << p.first << "\t" << p.second << endl;
    }

    // Find an element
    cout << "-> Find a key,value\n";
    iter = student.find(8);
    if (iter != student.end()) {
        cout << " Element Found\n";
    } else {
        cout << " Element Not Found\n";
    }

    // clear
    cout << "-> clear and size methods\n";
    cout << " " << stud.size(); // Output: 2

    stud.clear();

    cout << " " << stud.size() << endl; // Output: 0

    // erase
    cout << "-> erase elements\n";
    map<int, string>::iterator itr;

    // display initial map values
    cout << " Initial Values:" << endl;

    for (itr = student.begin(); itr != student.end(); ++itr) {
        cout << "   " << itr->first << " " << itr->second << ", ";
    }

    cout << endl;

    // use itr iterator to point to the first map element
    itr = student.begin();

    // remove the first element
    student.erase(itr);

    // remove the element having key 4
    student.erase(6);

    // display final map values
    cout << " Final Values:" << endl;

    for (itr = student.begin(); itr != student.end(); ++itr) {
        cout << "   " << itr->first << " " << itr->second << ", ";
    }
    cout << endl;

    /* // remove a range of elements
    student.erase(student.find(3), student.find(5));

    // display final map values
    cout << " Final Values after range erase:" << endl;

    for (iter = student.begin(); iter != student.end(); ++iter) {
        cout << "   " << itr->first << " " << itr->second << ", ";
    }
    cout << endl; */
    {
        cout << " Range Erase:" << endl;
        map<int, string> mp = {{1, "one"}, {2, "two"}, {4, "four"}};
        cout << " Intial map\n";
        for (auto p : mp) {
            cout << "  " << p.first << "\t" << p.second << endl;
        }

        // Define the range to erase second to third elements
        auto first = next(mp.begin(), 1);
        auto last = next(mp.begin(), 3);

        // Remove all elements in the range [first, last)
        mp.erase(first, last);

        cout << " Final map after range erase\n";
        for (auto &p : mp)
            cout << "  " << p.first << ": " << p.second << '\n';
    }
    // extract
    cout << "-> Extract a key and change it\n";
    std::map<int, std::string> fruits{
        {1, "mango"}, {2, "papaya"}, {3, "guava"}};

    for (auto [k, v] : fruits)
        std::cout << ' ' << k << '(' << v << ')';
    std::cout << '\n';

    auto nh = fruits.extract(2);
    nh.key() = 4;

    for (auto [k, v] : fruits)
        std::cout << ' ' << k << '(' << v << ')';
    std::cout << '\n';

    fruits.insert(std::move(nh));

    for (auto [k, v] : fruits)
        std::cout << ' ' << k << '(' << v << ')';
    std::cout << '\n';
    // fruits == {{1, "mango"}, {3, "guava"}, {4, "papaya"}}

    cout << "-> count a key\n";
    int key1 = 1;
    int key2 = 9;

    // Counting the occurrence of key1 and key2
    int cnt1 = fruits.count(key1);
    int cnt2 = fruits.count(key2);

    cout << " Count of " << key1 << ": " << cnt1 << endl;
    cout << " Count of " << key2 << ": " << cnt2 << endl;

    map<char, int> mchar = {
        {'a', 1}, {'b', 2}, {'c', 3}, {'d', 4}, {'e', 5},
    };

    auto last = *mchar.rbegin();
    auto i = mchar.begin();

    cout << " Map contains " << "following elements: " << endl;

    do {
        cout << " " << i->first << " = " << i->second << endl;
    } while (mchar.value_comp()(*i++, last));

    map<int, int> map_bound;

    // insert elements in random order
    map_bound.insert({12, 30});
    map_bound.insert({11, 10});
    map_bound.insert({15, 50});
    map_bound.insert({14, 40});

    // when 11 is present
    cout << "-> upper_bound and lower_bound\n";
    auto it = map_bound.upper_bound(11);
    cout << " The upper bound of key 11 is ";
    cout << (*it).first << " " << (*it).second << endl;

    // when 13 is not present
    it = map_bound.upper_bound(13);
    cout << " The upper bound of key 13 is ";
    cout << (*it).first << " " << (*it).second << endl;

    // when 17 is exceeds the maximum key, so size
    // of map_bound is returned as key and value as 0.
    it = map_bound.upper_bound(17);
    cout << " The upper bound of key 17 is ";
    cout << (*it).first << " " << (*it).second;

    map<int, string> mlb = {
        {1, "Geeks"}, {3, "Geeksfor"}, {2, "GeeksforGeeks"}};

    auto itlb = mlb.lower_bound(2);

    cout << " " << itlb->first << ": " << it->second;
    //----------------------------------------Unordered_map-----------------------------------
    cout << "\n---------------------std::unordered_map----------------------\n";
    // create an unordered_map with integer key and value
    unordered_map<int, int> ump_integer;

    // create an unordered_map with string key and int value
    unordered_map<string, int> ump_string;

    // Initializer List
    unordered_map<string, int> unordered_map = {
        {"One", 1}, {"Two", 2}, {"Three", 3}};

    // Uniform Initialization
    std::unordered_map<string, int> unordered_map2{
        {"One", 1}, {"Two", 2}, {"Three", 3}};

    cout << "-> Key - Value" << endl;

    // loop across the unordered map
    // display the key-value pairs
    for (const auto &key_value : unordered_map) {
        string key = key_value.first;
        int value = key_value.second;
        cout << " " << key << " - " << value << endl;
    }

    cout << "-> Structure Binding: Key - Value" << endl;
    for (const auto &[key, value] : unordered_map) {
        cout << " " << key << " - " << value << endl;
    }

    cout << "-> Iterator: Key - Value" << endl;
    for (auto it = unordered_map.begin(); it != unordered_map.end(); it++) {
        cout << " " << it->first << " - " << it->second << endl;
    }

    std::unordered_map<string, int> unordered_map1;

    // insert key-value pair {"One", 1}
    unordered_map1["One"] = 1;

    // insert a pair {"Two", 2}
    unordered_map1.insert({"Two", 2});

    // insert two pairs {"Three", 3}, {"Four", 4}
    unordered_map1.insert({{"Three", 3}, {"Four", 4}});

    cout << "-> Key - Value" << endl;

    // display elements of unordered_map1
    for (const auto &key_value : unordered_map1) {
        string key = key_value.first;
        int value = key_value.second;

        cout << " " << key << " - " << value << endl;
    }

    std::unordered_map<string, string> capital_city{{"Nepal", "Kathmandu"},
                                                    {"India", "New Delhi"},
                                                    {"Australia", "Canberra"}};
    cout << "-> Capital City Map\n";
    for (auto const &i : capital_city) {
        cout << " " << i.first << "-" << i.second << endl;
    }
    cout << "-> Capital of Nepal is " << capital_city["Nepal"] << endl;
    cout << "-> Capital of Australia is " << capital_city.at("Australia")
         << endl;

    // change value for "India" using []
    capital_city["India"] = "New Delhi";

    capital_city.at("Australia") = "CANBERRA";
    capital_city.insert_or_assign("UK", "London");

    cout << "-> Before Changing UK, Capital City Map\n";
    for (auto const &i : capital_city) {
        cout << " " << i.first << "-" << i.second << endl;
    }
    auto pair = capital_city.extract("UK");
    pair.key() = "United Kingdom";
    capital_city.insert(std::move(pair));
    capital_city.insert_or_assign("United Kingdom", "LONDON");

    cout << "-> Updated Capital City Map\n";
    for (auto const &i : capital_city) {
        cout << " " << i.first << "-" << i.second << endl;
    }

    std::unordered_map<int, char> example{{1, 'a'}, {2, 'b'}};

    cout << "-> The contain method\n";
    for (int x : {2, 5})
        if (example.contains(x))
            std::cout << " " << x << ": Found\n";
        else
            std::cout << " " << x << ": Not found\n";

    std::unordered_map<int, string> student_umap{
        {111, "John"}, {132, "Mark"}, {143, "Chris"}};

    cout << "-> Initial Unordered Map:\n";
    display_unordered_map(student_umap);

    // remove element with key: 143
    student_umap.erase(111);

    cout << "-> Final Unordered Map: \n";
    display_unordered_map(student_umap);
    cout << "-> Using find():" << endl;
    cout << " Does id " << 143 << " exist? ";

    // find() returns student.end() if the key is not found
    if (student.find(143) != student.end()) {
        cout << " Yes";
    } else {
        cout << " No";
    }

    cout << "\n-> Using count():" << endl;
    cout << " Does id " << 1433 << " exist? ";

    // count() returns 0 if the key doesn't exist
    if (student.count(1433)) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    std::unordered_map<string, double> umap;

    // inserting values by using [] operator
    umap["PI"] = 3.14;
    umap["root2"] = 1.414;
    umap["log10"] = 2.302;
    umap["loge"] = 1.0;
    umap["e"] = 2.718;

    // Display bucket no. where key, value pair is located
    // using bucket(key)
    cout << "\n-> Information about bucket\n";
    for (auto &x : umap) {
        cout << " (" << x.first << ", " << x.second << ")";
        cout << " is in bucket= " << umap.bucket(x.first) << endl;
    }

    // Count the no.of buckets in the unordered_map
    // using bucket_count()
    int n = umap.bucket_count();
    cout << " umap has " << n << " buckets.\n";

    // Count no. of elements in each bucket using
    // bucket_size(position)
    for (int i = 0; i < n; i++) {
        cout << " Bucket " << i << " has " << umap.bucket_size(i)
             << " elements.\n";
    }

    // Prints elements present in each bucket
    for (unsigned i = 0; i < n; i++) {
        cout << " Bucket " << i << " contains: ";
        for (auto it = umap.begin(i); it != umap.end(i); it++)
            cout << "(" << it->first << ", " << it->second << ") ";
        cout << "\n";
    }

    // Declaration
    std::unordered_map<string, string> mymap;

    // Initialisation
    mymap = {
        {"Australia", "Canberra"}, {"U.S.", "Washington"}, {"France", "Paris"}};

    // prints the bucket number of the beginning element
    auto itmymap = mymap.begin();

    // stores the bucket number of the key k
    int number = mymap.bucket(itmymap->first);
    cout << " The bucket number of key " << itmymap->first << " is " << number
         << endl;

    // declaration of unordered_map
    std::unordered_map<char, int> sample;

    // insert elements
    sample.insert({'a', 10});
    sample.insert({'b', 10});
    sample.insert({'c', 10});
    sample.insert({'d', 10});
    sample.insert({'e', 10});
    sample.insert({'f', 10});

    cout << "-> Information about size, load_factor and max_load_factor\n";
    cout << " Current size is :  " << sample.size() << endl;
    cout << " Current load factor is : " << sample.load_factor() << endl;
    cout << " Current Max load factor is " << sample.max_load_factor() << endl;

    // Changing max load factor
    sample.max_load_factor(5.0 / 2.0);
    cout << " Current size is :  " << sample.size() << endl;
    cout << " Current load factor is : " << sample.load_factor() << endl;
    cout << " Current Max load factor is " << sample.max_load_factor() << endl;

    cout << " Size of container : " << sample.size() << endl;
    cout << " Initial bucket count : " << sample.bucket_count() << endl;

    // changing rehash
    sample.rehash(30);
    cout << " Size of container : " << sample.size() << endl;
    cout << " Now bucket count is :  " << sample.bucket_count() << endl;

    // declaration
    std::unordered_map<int, int> sample1, sample2;

    // the sample1 size is reserved for
    // the bucket to contain a minimum of
    // one elements
    sample1.reserve(1);

    // inserts key and element
    // in sample1
    sample1.insert({10, 100});
    sample1.insert({50, 500});

    // inserts key and element
    // in sample1

    // the sample1 size is reserved for
    // the bucket to contain a minimum of
    // three elements
    sample2.reserve(3);

    sample2.insert({20, 200});
    sample2.insert({30, 300});
    sample2.insert({30, 150});

    cout << " The size of Sample1 is: " << sample1.size();

    cout << "\n Key and Elements of Sample1 are:";
    for (auto it = sample1.begin(); it != sample1.end(); it++) {
        cout << "{" << it->first << ", " << it->second << "} ";
    }

    cout << "\n The size of Sample2 is: " << sample2.size();

    cout << "\n Key and Elements of Sample2 are:";
    for (auto it = sample2.begin(); it != sample2.end(); it++) {
        cout << "{" << it->first << ", " << it->second << "} ";
    }

    //----------------------------------------Multimap-----------------------------------
    // create a multimap
    cout << "\n---------------------std::multimap----------------------\n";
    multimap<int, string> my_multimap = {{1, "Un"},  {1, "One"}, {2, "Two"},
                                         {2, "Dos"}, {1, "Uno"}, {2, "Deux"}};

    cout << "-> Key - Value" << endl;

    // loop across the multimap
    // display the key-value pairs
    for (const auto &key_value : my_multimap) {
        int key = key_value.first;
        string value = key_value.second;

        cout << " " << key << " - " << value << endl;
    }
    multimap<string, int> numbers;

    // insert a pair {"Odd", 1}
    numbers.insert({"Odd", 1});

    // insert multiple pairs
    numbers.insert({{"Even", 2}, {"Even", 6}, {"Odd", 5}, {"Even", 4}});

    cout << "-> Key - Value" << endl;

    // display numbers
    for (const auto &key_value : numbers) {
        string key = key_value.first;
        int value = key_value.second;
        cout << " " << key << " - " << value << endl;
    }

    multimap<int, string> studentmmap{
        {111, "John"}, {132, "Mark"}, {143, "Chris"}, {143, "Christopher"}};

    cout << "-> Initial Multimap:" << endl;
    display_multimap(studentmmap);

    // remove element with key: 143
    studentmmap.erase(143);

    cout << "-> Multimap After Erasing Key 143: " << endl;
    display_multimap(studentmmap);

    // remove all multimap elements
    studentmmap.clear();

    cout << "-> Multimap After Clearing: " << endl;
    display_multimap(studentmmap);

    multimap<string, int> mymultimap;

    // check capacity before insertion
    string result = mymultimap.empty() ? "Yes" : "No";
    int multimap_size = mymultimap.size();

    cout << "-> Before Insertion";
    cout << "\n Is multimap empty? " << result << endl;
    cout << " multimap size: " << multimap_size << endl;

    // insert element
    mymultimap.insert({"apple", 2});

    // check capacity after insertion
    result = mymultimap.empty() ? "Yes" : "No";
    multimap_size = mymultimap.size();

    cout << "-> After Insertion" << endl;
    cout << " Is multimap empty? " << result << endl;
    cout << " multimap size: " << multimap_size << endl;

    mymultimap.insert({"apple", 5});
    mymultimap.insert({"banana", 3});
    mymultimap.insert({"apple", 2});
    mymultimap.insert({"cherry", 4});

    cout << "-> Multimap with string as key\n";
    for (auto i : mymultimap) {
        cout << " " << i.first << "-" << i.second << endl;
    }
    // find elements with the key "apple"
    string key_to_find = "apple";
    auto found = mymultimap.find(key_to_find);

    // print the found key
    if (found != mymultimap.end()) {
        cout << "-> Found key " << key_to_find << ": " << endl;
        cout << " " << found->first << " - " << found->second << endl;
    } else {
        cout << " Key " << key_to_find << " not found." << endl;
    }

    cout << "-> Printing all pairs with value keys as apple using bound "
            "functions\n";
    // lower_bound and upper_bound return iterators for the key given
    std::multimap<string, int>::iterator lb = mymultimap.lower_bound("apple");
    std::multimap<string, int>::iterator ub = mymultimap.upper_bound("apple");
    for (; lb != ub; lb++) {
        cout << " " << lb->first << "-" << lb->second << endl;
    }

    cout << "-> Printing all pairs with value keys as apple using equal range "
            "functions\n";
    // range is a pair of iterators representing the lower bound and upper bound
    // of the key.
    std::pair<std::multimap<string, int>::iterator,
              std::multimap<string, int>::iterator>
        range = mymultimap.equal_range("apple");
    for (; range.first != range.second; range.first++) {
        cout << " " << range.first->first << "-" << range.first->second << endl;
    }
    //----------------------------------------Unordered_multimap-----------------------------------
    cout << "-----------------std::unordered_multimap-------------------\n";
    std::unordered_multimap<int, std::string> unordered_multimap;
    std::unordered_multimap<int, string> my_unordered_multimap{
        {1, "Apple"}, {22, "Banana"}, {1, "Apricot"}, {3, "Avocado"}};

    // print the elements
    cout << "-> Unordered Multimap Elements:" << endl;
    for (const auto &pair : my_unordered_multimap) {
        cout << " " << pair.first << ": " << pair.second << endl;
    }
    {
        std::unordered_multimap<string, int> my_unordered_multimap;

        my_unordered_multimap.insert({"apple", 5});
        my_unordered_multimap.insert({"banana", 3});
        my_unordered_multimap.insert({"apple", 2});
        my_unordered_multimap.insert({"cherry", 4});

        // count the number of elements with a specific key
        string key_to_count = "apple";
        int count = my_unordered_multimap.count(key_to_count);
        cout << "-> Count of key " << key_to_count << ": " << count << endl;
    }
    {
        std::unordered_multimap<string, int> my_unordered_multimap;

        // check capacity before insertion
        string result = my_unordered_multimap.empty() ? "Yes" : "No";
        int multimap_size = my_unordered_multimap.size();

        cout << "-> Before Insertion";
        cout << "\n Is unordered_multimap empty? " << result << endl;
        cout << " unordered_multimap size: " << multimap_size << endl;

        // insert element
        my_unordered_multimap.insert({"apple", 2});

        // check capacity after insertion
        result = my_unordered_multimap.empty() ? "Yes" : "No";
        multimap_size = my_unordered_multimap.size();

        cout << "-> After Insertion" << endl;
        cout << " Is unordered_multimap empty? " << result << endl;
        cout << " unordered_multimap size: " << multimap_size << endl;
    }
    {
        std::unordered_multimap<string, int> my_unordered_multimap;

        my_unordered_multimap.insert({"apple", 5});
        my_unordered_multimap.insert({"banana", 3});
        my_unordered_multimap.insert({"apple", 2});
        my_unordered_multimap.insert({"cherry", 4});

        cout << "-> Elements with key as apple using equal_range\n";
        auto ituomap = my_unordered_multimap.equal_range("apple");
        for (; ituomap.first != ituomap.second; ituomap.first++) {
            cout << " " << ituomap.first->first << " : "
                 << ituomap.first->second << endl;
        }
        // erase elements with the key "apple"
        string key_to_erase = "apple";
        my_unordered_multimap.erase(key_to_erase);

        cout << "-> Elements after erasing key " << key_to_erase << ":" << endl;
        for (const auto &pair : my_unordered_multimap) {
            cout << " " << pair.first << " -> " << pair.second << endl;
        }

        // clear the entire unordered_multimap
        my_unordered_multimap.clear();

        cout << "-> Elements after clearing:" << endl;
        for (const auto &pair : my_unordered_multimap) {
            cout << " " << pair.first << " -> " << pair.second << endl;
        }
    }
    return 0;
}

// function to print multimap elements
void display_multimap(const multimap<int, string> &umap) {

    for (const auto &key_value : umap) {
        int key = key_value.first;
        string value = key_value.second;

        cout << " " << key << " - " << value << endl;
    }
}
// utility function to print unordered_map elements
void display_unordered_map(const unordered_map<int, string> &umap) {

    for (const auto &key_value : umap) {
        int key = key_value.first;
        string value = key_value.second;

        cout << " " << key << " - " << value << endl;
    }
}
