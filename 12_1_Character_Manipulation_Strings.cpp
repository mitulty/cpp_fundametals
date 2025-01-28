/*
  @Author: Mitul Tyagi
  @Date:   2024-01-07 11:17:31
  @Description: Character Manipulation and Strings
*/

#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[])
{
    { // Character manipulation

        // Check if character is alphanumeric
        std::cout << "---------------------------CHARACTER MANIPULATION---------------------------" << std::endl;
        std::cout << std::endl;
        std::cout << "std::isalnum : " << std::endl;

        std::cout << "C is alphanumeric : " << std::isalnum('C') << std::endl;
        std::cout << "^ is alphanumeric : " << std::isalnum('^') << std::endl;

        // Can use this as a test condition
        char input_char{'*'};
        if (std::isalnum(input_char))
        {
            std::cout << input_char << " is alhpanumeric." << std::endl;
        }
        else
        {
            std::cout << input_char << " is not alphanumeric." << std::endl;
        }

        // Check if character is alphabetic
        std::cout << std::endl;
        std::cout << "std::isalpha : " << std::endl;
        std::cout << "C is alphabetic : " << std::isalpha('e') << std::endl; // 0
        std::cout << "^ is alphabetic : " << std::isalpha('^') << std::endl; // -1
        std::cout << "6 is alphabetic : " << std::isalpha('7') << std::endl; // 0

        if (std::isalpha('e'))
        {
            std::cout << 'e' << " is alphabetic" << std::endl;
        }
        else
        {
            std::cout << 'e' << " is NOT alphabetic" << std::endl;
        }

        // Check if a character is blank
        std::cout << std::endl;
        std::cout << "std::isblank : " << std::endl;
        char message[]{"Hello there. How are you doing? The sun is shining."};
        std::cout << "message : " << message << std::endl;

        // Find and print blank index
        size_t blank_count{};
        for (size_t i{0}; i < std::size(message); ++i)
        {
            // std::cout << "Value : " << message[i] << std::endl;
            if (std::isblank(message[i]))
            {
                std::cout << "Found a blank character at index : [" << i << "]" << std::endl;
                ++blank_count;
            }
        }
        std::cout << "In total we found " << blank_count << " blank characters." << std::endl;

        // Check if character is lowercase or uppercase
        std::cout << "std::islower and std::isupper : " << std::endl;

        std::cout << std::endl;
        char thought[]{"The C++ Programming Language is one of the most used on the Planet"};
        size_t lowercase_count{};
        size_t upppercase_count{};

        // Print original string for ease of comparison on the terminal
        std::cout << "Original string  : " << thought << std::endl;

        for (auto character : thought)
        {
            std::cout << " " << character;
            if (std::islower(character))
            {
                ++lowercase_count;
            }
            if (std::isupper(character))
            {
                ++upppercase_count;
            }
        }
        std::cout << std::endl;
        std::cout << "Found " << lowercase_count << " lowercase characters and "
                  << upppercase_count << " uppercase characters." << std::endl;

        // Check if a character is a digit
        std::cout << std::endl;
        std::cout << "std::isdigit : " << std::endl;

        char statement[]{"Mr Hamilton owns 220 cows. That's a lot of cows! The kid exclamed."};
        std::cout << "statement : " << statement << std::endl;

        size_t digit_count{};

        for (auto character : statement)
        {
            if (std::isdigit(character))
            {
                std::cout << "Found digit : " << character << std::endl;
                ++digit_count;
            }
        }
        std::cout << "Found " << digit_count << " digits in the statement string" << std::endl;

        // Turning a character to lowercase using the std::tolower() function
        std::cout << std::endl;
        std::cout << "std::tolower and std::toupper: " << std::endl;
        char original_str[]{"Home. The feeling of belonging"};
        char dest_str[std::size(original_str)];

        // Turn this to uppercase. Change the array in place
        for (size_t i{}; i < std::size(original_str); ++i)
        {
            dest_str[i] = std::toupper(original_str[i]);
        }

        std::cout << "Original string : " << original_str << std::endl;
        std::cout << "Uppercase string : " << dest_str << std::endl;

        // Turn this to lowercase. Change the array in place
        for (size_t i{}; i < std::size(original_str); ++i)
        {
            dest_str[i] = std::tolower(original_str[i]);
        }

        std::cout << "Lowercase string : " << dest_str << std::endl;

        // Reverse the case. Change the original array
        std::cout << "Original string : " << original_str << std::endl;
        for (auto &character : original_str)
        // for (auto character : original_str) // This copies the character of original_str and applies opeartion to it.
        {
            if (std::islower(character))
                character = std::toupper(character);
            else if (std::isupper(character))
                character = std::tolower(character);
        }
        std::cout << "Case reversed string : " << original_str << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }
    { // C-String Manipulation

        // std::strlen : Find the length of a string
        //  real arrays and those decayed into pointers
        std::cout << "---------------------------STRING MANIPULATION---------------------------------" << std::endl;
        const char message1[]{"The sky is blue."};

        // Array decays into pointer when we use const char*
        const char *message2{"The sky is blue."};
        std::cout << "message1 : " << message1 << std::endl;

        // strlen ignores null character
        std::cout << "strlen(message1) : " << std::strlen(message1) << std::endl;

        // Includes the null character
        std::cout << "sizeof(message1) : " << sizeof(message1) << std::endl;

        // std::size works with arrays only
        std::cout << "std::size(message1) : " << std::size(message1) << std::endl;

        // strlen still works with decayed arrays
        std::cout << "strlen(message2) : " << std::strlen(message2) << std::endl;

        // Prints size of pointer
        std::cout << "sizeof(message2) : " << sizeof(message2) << std::endl;

        // std::strcmp - signature : int strcmp( const char *lhs, const char *rhs );
        // Returns negative value if lhs appears before rhs in lexicographical order,
        // Zero if lhs and rhs compare equal.
        // and Positive value if lhs appears after rhs in lexicographical order.
        std::cout << std::endl;
        std::cout << "std::strcmp : " << std::endl;
        const char *string_data1{"Alabama"};
        const char *string_data2{"Blabama"};

        char string_data3[]{"Alabama"};
        char string_data4[]{"Blabama"};

        // Print out the comparison
        std::cout << "std::strcmp (" << string_data1 << "," << string_data2 << ") : "
                  << std::strcmp(string_data1, string_data2) << std::endl;

        std::cout << "std::strcmp (" << string_data3 << "," << string_data4 << ") : "
                  << std::strcmp(string_data3, string_data4) << std::endl;

        string_data1 = "Alabama";
        string_data2 = "Alabamb";

        // string_data3 = "Alabama";
        // string_data4 = "Alabamb";

        // Print out the comparison
        std::cout << "std::strcmp (" << string_data1 << "," << string_data2 << ") : "
                  << std::strcmp(string_data1, string_data2) << std::endl;

        string_data1 = "Alacama";
        string_data2 = "Alabama";

        // Print out the comparison
        std::cout << "std::strcmp (" << string_data1 << "," << string_data2 << ") : "
                  << std::strcmp(string_data1, string_data2) << std::endl;

        string_data1 = "India";
        string_data2 = "France";

        // Print out the comparison
        std::cout << "std::strcmp (" << string_data1 << "," << string_data2 << ") : "
                  << std::strcmp(string_data1, string_data2) << std::endl;

        string_data1 = "Kigali";
        string_data2 = "Kigali";

        // Print out the comparison
        std::cout << "std::strcmp (" << string_data1 << "," << string_data2 << ") : "
                  << std::strcmp(string_data1, string_data2) << std::endl;

        // std::strncmp : int strncmp( const char *lhs, const char *rhs, std::size_t count );
        // Compares n characters in the strings
        // Returns : Negative value if lhs appears before rhs in lexicographical order.
        // Zero if lhs and rhs compare equal, or if count is zero.
        // Positive value if lhs appears after rhs in lexicographical order.
        // Print out the comparison

        const char *string_data_comp1{"Alabama"};
        const char *string_data_comp2{"Blabama"};
        size_t n{3};
        std::cout << std::endl;
        std::cout << "std::strncmp : " << std::endl;
        std::cout << "std::strncmp (" << string_data1 << "," << string_data2 << "," << n << ") : "
                  << std::strncmp(string_data_comp1, string_data_comp2, n) << std::endl;

        string_data_comp1 = "aaaia";
        string_data_comp2 = "aaance";

        std::cout << "std::strncmp (" << string_data_comp1 << "," << string_data_comp2 << "," << n << ") : "
                  << std::strncmp(string_data_comp1, string_data_comp2, n) << std::endl;

        n = 5;

        std::cout << "std::strncmp (" << string_data_comp1 << "," << string_data_comp2 << "," << n << ") : "
                  << std::strncmp(string_data_comp1, string_data_comp2, n) << std::endl;

        char string_data_comp3[]{"aaaoa"};
        char string_data_comp4[]{"aaance"};

        std::cout << "std::strncmp (" << string_data_comp3 << "," << string_data_comp4 << "," << n << ") : "
                  << std::strncmp(string_data_comp3, string_data_comp4, n) << std::endl;

        // Find the first occurrence of a character
        // CODE STOLEN FROM THE DOCS :
        std::cout << std::endl;
        std::cout << "std::strchr : " << std::endl;
        // doc : https://en.cppreference.com/w/cpp/string/byte/strchr

        // we use std::strchr to find all the characters one by one.

        const char *const str{"Try not. Do, or do not. There is no try."};
        // Can make this a const pointer to prevent users from making it point somewhere else
        char target = 'T';
        const char *result = str;
        size_t iterations{};
        std::cout << "Current String: " << result << std::endl;
        while ((result = std::strchr(result, target)) != nullptr)
        {
            std::cout << "Found '" << target
                      << "' starting at '" << result << "'\n";

            // Increment result, otherwise we'll find target at the same location
            ++result;
            ++iterations;
            std::cout << "Current String: " << result << std::endl;
        }
        std::cout << "iterations : " << iterations << std::endl;

        // A lesser version that will loop 25 times
        // Find the first occurrence of a character
        // CODE STOLEN FROM THE DOCS :
        std::cout << std::endl;
        std::cout << "std::strchr : " << std::endl;
        // doc : https://en.cppreference.com/w/cpp/string/byte/strchr

        // we use std::strchr to find all the characters one by one.

        const char *str_new{"Try not. Do, or do not. There is no try."};
        char target_new = 'T';
        const char *result_new{nullptr};
        size_t iterations_new{};

        std::cout << "Current String: " << str_new << std::endl;
        while ((result_new = std::strchr(str_new, target_new)) != nullptr)
        {
            std::cout << "Found '" << target_new
                      << "' starting at '" << result_new << "'\n";

            // Increment result, otherwise we'll find target at the same location
            ++str_new; // Making the pointer point to the next character
            ++iterations_new;
            std::cout << "Current String: " << str_new << std::endl;
        }
        std::cout << "iterations : " << iterations_new << std::endl;

        // Find last occurence
        // CODE STOLEN FROM THE DOCS :
        std::cout << std::endl;
        std::cout << "std::strrchr : " << std::endl;
        // doc : https://en.cppreference.com/w/cpp/string/byte/strrchr

        char input[] = "/home/user/hello.cpp";
        char *output = std::strrchr(input, '/');
        if (output)
            std::cout << output + 1 << std::endl; //+1 because we want to start printing past
                                                  // the character found by std::strrchr.
        std::cout << std::endl;
    }
    {
        // Concatenation
        std::cout << std::endl;
        std::cout << "std::strcat : " << std::endl;
        // doc : https://en.cppreference.com/w/cpp/string/byte/strcat

        char dest[50] = "Hello ";
        char src[50] = "World!";
        std::strcat(dest, src);                      // Some compilers (MSVC) think these functions are unsafe!
        std::cout << "dest : " << dest << std::endl; // Hello World
        std::strcat(dest, ", Goodbye World!");
        std::cout << "dest : " << dest << std::endl; // Hello World, Goodbye World!

        // More concatenation
        std::cout << std::endl;
        std::cout << "More std::strcat : " << std::endl;

        char *dest1 = new char[30]{'F', 'i', 'r', 'e', 'l', 'o', 'r', 'd', '\0'};
        char *source1 = new char[31]{',', 'T', 'h', 'e', ' ', 'P', 'h', 'o', 'e', 'n', 'i', 'x', ' ', 'K', 'i', 'n', 'g', '!', '\0'};

        // NOTE TO SELF :
        // Describe what's going to happen in std::strcat before you do the cat :
        // source is going to be appended to dest, and the process
        // will start by overriding the null character in dest

        std::cout << "std::strlen(dest1) :" << std::strlen(dest1) << std::endl;
        std::cout << "std::strlen(source1) : " << std::strlen(source1) << std::endl;

        std::cout << "Concatenating..." << std::endl;
        std::strcat(dest1, source1);

        std::cout << "std::strlen(dest1) :" << std::strlen(dest1) << std::endl;
        std::cout << "dest1 : " << dest1 << std::endl;

        // std::strncat  : concatenates n characters from src to dest and
        // returns a pointer to the result string
        // signature : char *strncat( char *dest, const char *src, std::size_t count );
        std::cout << std::endl;
        std::cout << "std::strncat:" << std::endl;
        char dest2[50]{"Hello"};

        char source2[30] = {" There is a bird on my window"};

        // You can even use the returned pointer immediately for print out
        // This is a pattern you'll see a lot in C++ code out there.
        std::cout << std::strncat(dest2, source2, 6) << std::endl;

        // Or you can do std::strncat separately and print dest2
        std::strncat(dest2, source2, 6);
        std::cout << "The concatenated string is : " << dest2 << std::endl;

        // std::strcpy - signature : char* strcpy( char* dest, const char* src );
        std::cout << std::endl;
        std::cout << "std::strcpy : " << std::endl;
        const char *source3 = "C++ is a multipurpose programming language.";
        char *dest3 = new char[std::strlen(source3) + 1]; // +1 for the null character
                                                          // Contains garbage data
                                                          // Not initialized

        std::strcpy(dest3, source3);

        std::cout << "sizeof(dest3) : " << sizeof(dest3) << std::endl;
        std::cout << "std::strlen(dest3) : " << std::strlen(dest3) << std::endl;
        std::cout << "dest3 : " << dest3 << std::endl;

        // std::strncpy : Copy n characters from src to dest -
        // signature : char *strncpy( char *dest, const char *src, std::size_t count );
        std::cout << std::endl;
        std::cout << "std::strncpy:" << std::endl;
        const char *source4 = "Hello";
        char dest4[] = {'a', 'b', 'c', 'd', 'e', 'f', '\0'}; // Have to put the terminating
                                                             // null char if we want to print

        std::cout << "dest4 : " << dest4 << std::endl;

        std::cout << "Copying..." << std::endl;
        std::strncpy(dest4, source4, 5);

        std::cout << "dest4 : " << dest4 << std::endl;
    }
    return 0;
}
