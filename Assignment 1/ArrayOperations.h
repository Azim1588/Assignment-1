#include <vector>
#include <iostream>

class ArrayOperations {
public:
    // Reads data from a file and populates the dataArray.
    void readFromFile(const std::string& filename);

    // Checks if a given number exists in the dataArray.
    int checkInteger(int number);

    // Modifies the value at a specified index in the dataArray.
    // Returns a pair containing the original value and the modified value.
    std::pair<int, int> modifyInteger(int index, int newValue);

    // Adds an integer to the dataArray.
    void addInteger(int number);

    // Replaces the value at a specified index in the dataArray with a new value.
    void replaceInteger(int index, int newValue);

    // Removes an integer at a specified index from the dataArray.
    void removeInteger(int index);

private:
    // A 2D vector to store the integer values.
    std::vector<std::vector<int>> dataArray;
};
