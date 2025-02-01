/*
  @Author: Mitul Tyagi
  @Date:   2024-01-04 21:25:55
  @Description: Multidimensional Arrays
*/

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{

    {
        // 2D array
        // int packages [3][4] ; // 12 where we can store ints
        int packages[][4]{
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12},
            {3, 4, 5, 6}};

        // Read data from a 2D array
        for (size_t i{0}; i < 3; ++i)
        {
            for (size_t j{0}; j < 4; ++j)
            {

                std::cout << packages[i][j] << "   ";
            }
            std::cout << std::endl;
        }

        // Use std::size to query the size of array dimensions
        for (size_t i{0}; i < std::size(packages); ++i)
        {

            for (size_t j{0}; j < std::size(packages[i]); ++j)
            {

                std::cout << packages[i][j] << "   ";
            }
            std::cout << std::endl;
        }

        // 3D arrays are defined in the same way. We just use three sets of indexes
        //  3 lights per room, 5 rooms per house 7 houses per block
        int house_block[7][5][3]{
            {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}, {13, 14, 15}},
            {{16, 17, 18}, {19, 20, 21}, {22, 23, 24}, {25, 26, 27}, {28, 29, 30}},
            {{31, 32, 33}, {34, 35, 36}, {37, 38, 39}, {40, 41, 42}, {43, 44, 45}},
            {{46, 47, 48}, {49, 50, 51}, {52, 53, 54}, {55, 56, 57}, {58, 59, 60}},
            {{61, 62, 63}, {64, 65, 66}, {67, 68, 69}, {70, 71, 72}, {73, 74, 75}},
            {{76, 77, 78}, {79, 80, 81}, {82, 83, 84}, {85, 86, 87}, {88, 89, 90}},
            {{91, 92, 93}, {94, 95, 96}, {97, 98, 99}, {100, 101, 102}, {103, 104, 105}}};

        for (size_t i{0}; i < std::size(house_block); ++i)
        {
            for (size_t j{0}; j < std::size(house_block[i]); ++j)
            {
                for (size_t k{0}; k < std::size(house_block[i][j]); ++k)
                {

                    std::cout << house_block[i][j][k] << "     ";
                }
            }
        }
        // The dimensions can be omitted (only the leftmost dimension).
        const size_t num_cols{3};
        int packages2[][5]{
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9},
            {10, 11, 12},
            {100, 110, 120} // Can add as many triplets in packages2 as we want
        };

        std::cout << std::endl;
        std::cout << "Ommiting leftmost dimension for 2d array : " << std::endl;
        for (size_t i{0}; i < std::size(packages2); ++i)
        {
            for (size_t j{0}; j < std::size(packages2[i]); ++j)
            {
                std::cout << "Item (" << i << "," << j << ") : " << packages2[i][j] << std::endl;
            }
        }

        // For 3d and really any multi dimensional array , you have to specify
        // the number of elements in []'s , only the left most is not mandatory.
        // Below is the example for 3D reproduced.Omitting the 5 or the 3 or both
        // will cause a compile error.
        int house_block1[][5][3]{
            {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}, {13, 14, 15}},
            {{16, 17, 18}, {19, 20, 21}, {22, 23, 24}, {25, 26, 27}, {28, 29, 30}},
            {{31, 32, 33}, {34, 35, 36}, {37, 38, 39}, {40, 41, 42}, {43, 44, 45}},
            {{46, 47, 48}, {49, 50, 51}, {52, 53, 54}, {55, 56, 57}, {58, 59, 60}}

        };

        for (size_t i{0}; i < std::size(house_block1); ++i)
        {
            for (size_t j{0}; j < std::size(house_block1[i]); ++j)
            {
                std::cout << "[";
                for (size_t k{0}; k < std::size(house_block1[i][j]); ++k)
                {

                    std::cout << house_block1[i][j][k] << " ";
                }
                std::cout << "] "; // Separate elements for good visualization
            }
            std::cout << std::endl; // Separate elements for good visualization
        }

        // If you put less elements than the amount specified in the declaration, the compiler
        // will automaticaly fill out those left out with 0 or '\0' if the array is of char.
        //  Change the array to int house_block [] [5] [4], and because all inner arrays have 3,
        //  elements, the fourth will be autofilled with 0.
        //  Also remove some other elements, I chose the {4,5,6} array but you can add others
        //  when recording to make this a bit fun. The left out indexes will be auto filled with
        //  zeros
        int house_block2[][5][4]{// Try to make the last dimension 5 and show
                                 // that the compiler appends 2 zeros
                                 {
                                     {1, 2, 3}, {4}, {7, 8, 9}, {10, 11, 12}, {13, 14, 15} // The one element array will be autofilled
                                                                                           //  with zeros to complete 4 elements
                                 },
                                 {{16, 17, 18}, {19, 20, 21}, {22, 23, 24}, {25, 26, 27}, {28, 29, 30}},
                                 {{31, 32, 33}, {34, 35, 36}, {37, 38, 39}, {40, 41, 42}, {43, 44, 45}},
                                 {
                                     {46, 47, 48}, {49, 50, 51}, {52, 53, 54}, {55, 56, 57} //,{58,59,60}  // The spots for {58,59,60
                                                                                            // Will be autofilled with 0
                                 }

        };

        // Modify data
        house_block2[0][2][1] = 1021;

        std::cout << std::endl;
        std::cout << "Printing out 3d house_block array with defaulted elements : " << std::endl;

        for (size_t i{0}; i < std::size(house_block2); ++i)
        {

            for (size_t j{0}; j < std::size(house_block2[i]); ++j)
            {

                std::cout << "[";
                for (size_t k{0}; k < std::size(house_block2[i][j]); ++k)
                {

                    std::cout << house_block2[i][j][k] << " ";
                }
                std::cout << "] "; // Separate elements for good visualization
            }
            std::cout << std::endl; // Separate elements for good visualization
        }
    }
    { // Multidimensional Character Arrays
        const size_t name_length{15};

        char members[][name_length]{
            {'J', 'o', 'h', 'n'},
            {
                'S',
                'a',
                'm',
                'u',
                'e',
                'l',
            },
            {'R', 'a', 's', 'h', 'i', 'd'},
            {'R', 'o', 'd', 'r', 'i', 'g', 'e', 'z'}};

        // Declaring a 2D array

        // Printing out like this is unsafe : may go over and print
        // outside your valid memory block
        // until a terminating null character is encountered.

        std::cout << "Unsafe printing of members : " << std::endl;
        for (size_t i{0}; i < std::size(members); ++i)
        {
            std::cout << members[i] << std::endl;
        }

        // Can loop around manually printing out each character

        std::cout << std::endl;
        std::cout << "Printing out character by character manually : " << std::endl;
        for (size_t i{0}; i < std::size(members); ++i)
        {

            for (size_t j{0}; j < std::size(members[i]); ++j)
            {

                std::cout << members[i][j];
            }
            std::cout << std::endl;
        }

        // Better : Using C-string literals
        // Compared to initialization with charactes with in '', this
        //  is even easier to type. The entire string is a single entity
        // you can manage easily.
        char members1[][name_length]{
            "John",
            "Samuel",
            "Rashid",
            "Rodriguez"};

        // Printing out members1
        std::cout << "Printing out members1 (C-string literals) : " << std::endl;
        for (size_t i{0}; i < std::size(members1); ++i)
        {
            std::cout << members1[i] << std::endl;
        }
        // members1[3] = "Morack"; // Expression Must be modifiable lvalue
        for (size_t i{0}; i < std::size(members1[3]); ++i)
        {
            members1[3][i] = 'o';
        }

        // Printing out members1
        std::cout << "Printing out members1 (C-string literals) : " << std::endl;
        for (size_t i{0}; i < std::size(members1); ++i)
        {
            std::cout << members1[i] << std::endl;
        }
        // Updating our prediction declaration in the fortune teller game
        char predictions[][90]{
            "a lot of kinds running in the backyard!",
            "a lot of empty beer bootles on your work table.",
            "you Partying too much with kids wearing weird clothes.",
            "you running away from something really scary",
            "clouds gathering in the sky and an army standing ready for war",
            "dogs running around in a deserted empty city",
            "a lot of cars stuck in a terrible traffic jam",
            "you sitting in the dark typing lots of lines of code on your dirty computer",
            "you yelling at your boss. And oh no! You get fired!",
            "you laughing your lungs out. I've never seen this before.",
            "Uhm , I don't see anything!"

        };

        std::cout << std::endl;
        std::cout << "Prediction : " << predictions[5] << std::endl;
    }
    return 0;
}
