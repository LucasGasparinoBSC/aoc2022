#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdint>
#include "SortOps.h"

int main(int argc, char const *argv[])
{
    // Check that there are 2 arguments
    if (argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    // Read argument 2 as the fileName, append the .txt termination
    std::string fileName = argv[1];
    fileName.append(".txt");

    // Open the file
    std::ifstream file(fileName);

    // Creatte a dummy vector to hold the total calories of each elf
    std::vector<uint64_t> totalCalories;

    // Create a dummy string to hold each line temporarily
    std::string line;

    // Check that the file is open
    if (!file.is_open())
    {
        std::cout << "Could not open file " << fileName << std::endl;
        return -1;
    }
    // Read the file
    else
    {
        // Create a temporary vector to hold each calorie for thhe elf
        std::vector<uint64_t> tmp;
        while (getline(file, line))
        {
            // If line is a number, store the calories in the tmp vector
            if (line != "")
            {
                // Convert string to integer
                tmp.push_back(std::stoi(line));
            }
            else
            {
                // Sum all entries in tmp
                uint64_t sum = 0;
                for (uint64_t i = 0; i < tmp.size(); i++)
                {
                    sum += tmp[i];
                }
                // Store the sum in the totalCalories vector
                totalCalories.push_back(sum);
                // Clear the tmp vector
                tmp.clear();
            }
        }
    }

    // Close the file
    file.close();

    // Copy the totalCalories vector to an array
    int* arr = new int[totalCalories.size()];
    for (uint64_t i = 0; i < totalCalories.size(); i++)
    {
        arr[i] = totalCalories[i];
    }

    // Create a SortOps object
    SortOps s;

    // Sort the array
    s.quickSort(arr, 0, totalCalories.size() - 1);

    // Find the top 3 values in thee list
    uint64_t max1;
    uint64_t maxTot = 0;
    uint64_t elfid = 0;
    for (uint64_t i = 0; i < 3; i++)
    {
        max1 = 0;
        for (uint64_t j = 0; j < totalCalories.size(); j++)
        {
            if (totalCalories[j] > max1)
            {
                max1 = totalCalories[j];
                elfid = j;
            }
        }
        maxTot += max1;
        std::cout << "Elf " << elfid << " ate " << max1 << " calories" << std::endl;
        totalCalories.erase(totalCalories.begin() + elfid);
        std::cout << "There are " << totalCalories.size() << " elves left" << std::endl;
    }
    std::cout << "The total calories eaten is " << maxTot << std::endl;

    // Delete the array
    delete[] arr;

    return 0;
}