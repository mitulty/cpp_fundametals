/**
 * @Author: Mitul
 * @Description:
 */
/*
- Sets are STL containers that store unique elements of the same type in a
sorted manner.
- As the value of every element in a set is unique, the value itself acts as the
key for identifying the element.
- Set has the following properties:
    -> Unique elements
    -> Immutable
    -> Sorted Order
    -> Associative
- Important methods of sets are: clear, erase, insert, empty, count, size,
emplace, emplace_hint, extract, next, find, equal_range, begin, end, rbegin,
rend, cbegin, cend, crbegin, & crend

- The STL unordered_set is an unordered associative container that provides the
functionality of an unordered set data structure.
- In contrast to a regular set, the order of values in an unordered set is
undefined. -Also, the unordered set is implemented as a hash table data
structure whereas the regular set is implemented as a binary search tree data
structure.
- Along with set methods, unordered_set has methods for hashing and bucket list
which are important for hash table implementation. These are: bucket,
bucket_count, bucket_size, hash_function, keq_eq, load_factor, max_bucket_count,
max_load_factor, max_size, rehash, & reserve.

- In Multiset, duplicate values are allowed. Multiple elements in the container
can have equivalent keys.

- In C++, unordered multisets store elements like a multiset but without any
specific order, allowing quick retrieval by value.

*/
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// function prototype for display_unordered_set()
void display_unordered_set(const unordered_set<string> &);
void print(std::string_view comment, const std::set<int> &data);

int main(int argc, char const *argv[]) {

    //----------------------------Set----------------------------------
    cout << "---------------------------std::set-------------------\n";
    // initialize set with elements
    std::set<int> my_set1 = {5, 3, 8, 1, 3};

    // create an empty set
    std::set<int> my_set2;
    set<int> my_set = {5, 3, 8, 1, 3};

    cout << "-> Print Set Elements: " << endl;
    for (int val : my_set) {
        cout << " " << val << " ";
    }
    cout << endl;
    // this is not allowed in a set
    // my_set[4] = 4

    cout << "-> Iterator Traversal: " << endl;
    std::set<int>::iterator it = my_set.begin();
    for (; it != my_set.end(); it++)
        cout << " " << *it << " ";
    cout << endl;

    set<int, greater<int>> my_set_sorted = {5, 3, 8, 1, 3};

    cout << "-> Print Set Elements Sorted: " << endl;
    for (int val : my_set_sorted) {
        cout << " " << val << " ";
    }
    cout << endl;

    my_set.insert(10);
    my_set.insert(30);
    my_set.insert(20);
    my_set.insert(50);
    my_set.insert(40);
    my_set.insert(50);

    // print the set elements
    cout << "-> Print Set Elements: " << endl;
    for (int i : my_set) {
        cout << " " << i << "  ";
    }
    cout << endl;

    // check if 40 exists
    int num = 40;
    if (my_set.count(num) == 1) {
        cout << " " << num << " exists." << endl;
    } else {
        cout << " " << num << " doesn't exist." << endl;
    }

    // check if 60 exists
    num = 60;
    if (my_set.count(num) == 1) {
        cout << " " << num << " exists." << endl;
    } else {
        cout << " " << num << " doesn't exist." << endl;
    }

    if (my_set.find(num) != my_set.end()) {
        cout << " " << num << " exists." << endl;
    } else {
        cout << " " << num << " doesn't exist." << endl;
    }

    num = 40;
    if (my_set.count(num) == 1) {
        cout << " " << num << " exists." << endl;
    } else {
        cout << " " << num << " doesn't exist." << endl;
    }
    // set before deletion
    cout << "-> The set before erasing: ";
    for (int i : my_set) {
        cout << " " << i << "  ";
    }

    // delete values from the set
    my_set.erase(10);
    my_set.erase(20);

    // set after deletion
    cout << "\n-> The set after erasing: ";
    for (int i : my_set) {
        cout << " " << i << "  ";
    }

    // delete all elements from the set
    my_set.clear();

    // set after clearing all elements
    cout << "\n-> The set after clearing all elements: ";
    for (int i : my_set) {
        cout << " " << i << "  ";
    }

    my_set.insert(3);
    my_set.insert(4);
    my_set.insert(5);
    my_set.insert(6);
    my_set.insert(7);
    my_set.insert(8);

    cout << "\n-> New Set";
    // check if the set is empty
    cout << "\n Empty: " << my_set.empty() << endl;

    // check the size of the set
    cout << " Size: " << my_set.size() << endl;

    // clear values from the set
    my_set.clear();

    // set after clear
    cout << "-> The set after clear: ";
    for (int i : my_set) {
        cout << i << "  ";
    }

    // use the capacity methods again
    cout << "\n Empty: " << my_set.empty() << endl;
    cout << " Size: " << my_set.size() << endl;

    my_set.insert(233);
    my_set.insert(412);
    my_set.insert(513);
    my_set.insert(416);
    my_set.insert(237);
    my_set.insert(867);
    my_set.insert(343);
    my_set.insert(432);
    my_set.insert(125);
    my_set.insert(346);
    my_set.insert(127);
    my_set.insert(128);

    cout << "-> Use of lower_bound, upper_bound and equal_range\n";
    for (int i : my_set) {
        cout << " " << i << "  ";
    }

    auto lower = my_set.lower_bound(128);
    auto upper = my_set.upper_bound(416);
    cout << "\n Elements between 128 and 416: ";
    for (; lower != upper; lower++)
        cout << " " << *lower << " ";

    auto range = my_set.equal_range(128);
    cout << "\n equal_range in set: " << (range.first == range.second) << endl;

    for (; range.first != range.second; range.first++)
        cout << " " << *range.first << " ";

    lower = my_set.lower_bound(128);
    upper = my_set.upper_bound(416);
    my_set.erase(lower, upper);
    cout << " \nErasing the range\n";
    for (int i : my_set) {
        cout << " " << i << "  ";
    }

    cout << "\n-> Use of extract\n";

    std::set<int> cont{1, 2, 3};
    print(" Start:", cont);

    // Extract node handle and change key
    auto nh = cont.extract(1);
    nh.value() = 4;

    print(" After extract and before insert:", cont);

    // Insert node handle back
    cont.insert(std::move(nh));

    print(" End:", cont);

    cout << "-> Merge two sets\n";
    cont.merge(my_set);
    cout << " cont set: ";
    for (int i : cont) {
        cout << " " << i << "  ";
    }
    cout << "\n my_set: ";
    for (int i : my_set) {
        cout << " " << i << "  ";
    }
    //----------------------------Unordered_Set----------------------------------
    cout << "\n-------------------------std::unordered_set-----------------\n";

    unordered_set<int> numbers{1, 100, 10, 70, 100};
    unordered_set<int> unordered_set2{1, 100, 2, 9};
    unordered_set<int> unordered_set1 = {1, 100, 2, 9};

    // loop across the unordered set
    // display the value
    cout << "-> numbers = ";
    for (auto &num : numbers) {
        cout << num << ", ";
    }
    cout << endl;
    unordered_set<string> countries;

    // inserts "Nepal" into countries
    countries.insert("Nepal");

    // inserts "Nepal" , "India", "USA", "Korea" into countries
    countries.insert({"Nepal", "India", "USA", "Korea"});

    cout << "-> Countries = ";
    // display elements of countries
    for (const auto &country : countries) {
        cout << country << ", ";
    }
    cout << endl;
    unordered_set<string> languages{"C++", "Python", "Java", "PHP"};

    cout << "-> Erase an element";
    cout << "\n Initial unordered set: ";
    display_unordered_set(languages);

    // remove element with value: "Python"
    languages.erase("Python");

    cout << " Final unordered set: ";
    display_unordered_set(languages);

    unordered_set<int> primes{2, 3, 5, 7, 11, 13};

    cout << "-> Using find():" << endl;
    cout << " Does number " << 12 << " exist? ";

    // find() returns primes.end() if the value is not found
    if (primes.find(12) != primes.end()) {
        cout << " Yes";
    } else {
        cout << " No";
    }

    cout << "\n-> Using count():" << endl;
    cout << " Does number " << 7 << " exist? ";

    // count() returns 0 if the value doesn't exist
    if (primes.count(7)) {
        cout << " Yes";
    } else {
        cout << " No";
    }
    unordered_set<int> numberset{1,   100, 10, 70, 100, 34, 576, 78, 98,   23,
                                 657, 78,  23, 56, 7,   23, 67,  79, 4233, 54};

    cout << "-> Size: " << numberset.size();

    cout << "\n-> Information about the bucket\n";
    cout << " Total number of buckets: " << numberset.bucket_count() << endl;
    cout << " Bucket for 657: " << numberset.bucket(657) << endl;
    cout << " Bucket for 6(does not exist): " << numberset.bucket(6) << endl;
    size_t n = numberset.bucket_count();
    for (size_t i = 0; i < n; i++)
        cout << " Number of elements in bucket " << i << ": "
             << numberset.bucket_size(i) << endl;
    cout << endl;

    for (size_t i = 0; i < n; i++) {
        cout << " Elements in bucket " << i << ": ";
        for (auto j = numberset.begin(i); j != numberset.end(i); j++)
            cout << " " << *j;
        cout << endl;
    }

    //-----------------------------------Multiset----------------------------
    cout << "---------------------------std::multiset-------------------\n";
    multiset<int> my_multiset = {5, 3, 8, 1, 3};

    cout << "-> Multiset: ";
    for (int val : my_multiset) {
        cout << val << " ";
    }

    cout << endl;
    multiset<int, greater<int>> mymultisetgreater = {5, 3, 8, 1, 3};

    cout << "-> Multiset in descending order: ";
    for (int val : mymultisetgreater) {
        cout << val << " ";
    }
    cout << endl;

    // add values to the multiset
    my_multiset.insert(10);
    my_multiset.insert(30);
    my_multiset.insert(20);
    my_multiset.insert(50);
    my_multiset.insert(40);
    my_multiset.insert(50);

    // print multiset after insertion
    cout << "-> Insert elements: ";
    for (int i : my_multiset) {
        cout << i << "  ";
    }
    cout << endl;

    // delete all occurences of 50 from the multiset
    cout << "-> Erase elements";
    my_multiset.erase(50);

    // print multiset after erase
    cout << "\n The multiset after erase: ";
    for (int i : my_multiset) {
        cout << i << "  ";
    }

    // delete all values from the multiset
    my_multiset.clear();

    // print multiset after clear
    cout << "\n The multiset after clear: ";
    for (int i : my_multiset) {
        cout << i << "  ";
    }

    multiset<int> mymultiset = {10, 20, 20, 20, 30, 40};

    // print multiset before clearing all values
    cout << "-> Clear Multiset\n";
    cout << " The multiset before clear: ";
    for (int i : mymultiset) {
        cout << i << "  ";
    }

    // check if the multiset is empty
    cout << "\n Empty: " << mymultiset.empty() << endl;

    // check the size of the multiset
    cout << " Size: " << mymultiset.size() << endl;

    // delete all values from the multiset
    mymultiset.clear();

    // multiset after clear
    cout << " The multiset after clear: ";
    for (int i : mymultiset) {
        cout << i << "  ";
    }

    // use the capacity methods again
    cout << "\n Empty: " << mymultiset.empty() << endl;
    cout << " Size: " << mymultiset.size() << endl;

    //------------------------------Unordered_Multiset--------------------------------
    cout << "---------------------std::unordered_multiset------------------\n";
    unordered_multiset<int> my_unordered_multiset = {10, 30, 20, 50, 40, 50};

    cout << "-> Access elements: ";
    for (int i : my_unordered_multiset) {
        cout << i << "  ";
    }

    // delete all occurrences of 50
    my_unordered_multiset.erase(50);

    // print unordered_multiset after erase
    cout << "\n-> The unordered_multiset after erase: ";
    for (int i : my_unordered_multiset) {
        cout << i << "  ";
    }

    cout << "\n-> Clear\n";
    // check if the unordered_multiset is empty
    cout << " Empty: " << my_unordered_multiset.empty() << endl;

    // check the size of the unordered_multiset
    cout << " Size: " << my_unordered_multiset.size() << endl;

    // delete all values from the unordered_multiset
    my_unordered_multiset.clear();

    // unordered_multiset after clear
    cout << " The unordered_multiset after clear: ";
    for (int i : my_unordered_multiset) {
        cout << i << "  ";
    }

    // use the capacity methods again
    cout << "\n Empty: " << my_unordered_multiset.empty() << endl;
    cout << " Size: " << my_unordered_multiset.size() << endl;

    // print unordered_multiset before searching
    cout << " The unordered_multiset: ";
    for (int i : my_unordered_multiset) {
        cout << i << "  ";
    }

    my_unordered_multiset = {10, 30, 20, 50, 40, 50};

    // find an element in the unordered_multiset
    int target = 20;
    unordered_multiset<int>::iterator itms = my_unordered_multiset.find(target);

    if (itms != my_unordered_multiset.end()) {
        cout << "\n-> Found " << target << " in the unordered_multiset."
             << endl;
    } else {
        cout << "\n-> " << target << " not found in the unordered_multiset."
             << endl;
    }

    // count occurrences of an element in the unordered_multiset
    int count_value = 20;
    int count_result = my_unordered_multiset.count(count_value);

    cout << "-> Count: " << count_value << " appears " << count_result
         << " times in the unordered_multiset." << endl;

    return 0;
}

// utility function to print unordered_set elements
void display_unordered_set(const unordered_set<string> &uset) {
    for (const auto &value : uset) {
        cout << value << ", ";
    }
    cout << endl;
}
void print(std::string_view comment, const std::set<int> &data) {
    std::cout << comment;
    for (auto datum : data)
        std::cout << ' ' << datum;

    std::cout << '\n';
}
