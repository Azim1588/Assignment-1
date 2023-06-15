#include <iostream>
#include "arrayOperations.h"

int main() {
    ArrayOperations arrayOps;
    try {
        arrayOps.readFromFile("data.txt"); // Read data from file

        int numberToCheck = 42;
        int index = arrayOps.checkInteger(numberToCheck); // Check if numberToCheck exists in the array
        if (index != -1) {
            std::cout << "Number " << numberToCheck << " found at index: " << index << std::endl;
        }
        else {
            std::cout << "Number " << numberToCheck << " not found in the array." << std::endl;
        }

        int modifyIndex = 15;
        int newValue = 99;
        std::pair<int, int> modifiedValue = arrayOps.modifyInteger(modifyIndex, newValue); // Modify the value at modifyIndex with newValue
        std::cout << "Modified value at index " << modifyIndex << ": "
            << "Old value = " << modifiedValue.first << ", New value = " << modifiedValue.second << std::endl;

        int newInteger = 123;
        arrayOps.addInteger(newInteger); // Add newInteger to the end of the array
        std::cout << "Added new integer to the end of the array: " << newInteger << std::endl;

        int replaceIndex = 7;
        int replaceValue = 0;
        arrayOps.replaceInteger(replaceIndex, replaceValue); // Replace the value at replaceIndex with replaceValue
        std::cout << "Replaced value at index " << replaceIndex << " with " << replaceValue << std::endl;

        int removeIndex = 33;
        arrayOps.removeInteger(removeIndex); // Remove the integer at removeIndex
        std::cout << "Removed integer at index " << removeIndex << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception occurred: " << e.what() << std::endl; // Handle and print any exceptions that occur
        return 1;
    }

    return 0;
}
