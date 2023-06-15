#include "arrayOperations.h"
#include <fstream>
#include <iostream>

void ArrayOperations::readFromFile(const std::string& filename) {
    std::ifstream inputFile(filename);
    if (inputFile.is_open()) {
        int num;
        while (!inputFile.eof()) {
            std::vector<int> line;
            for (int i = 0; i < 10; ++i) {
                inputFile >> num;
                line.push_back(num);
            }
            dataArray.push_back(line); // Add the line to the dataArray
        }
        inputFile.close();
    }
    else {
        throw std::runtime_error("Unable to open file.");
    }
}

int ArrayOperations::checkInteger(int number) {
    for (int i = 0; i < dataArray.size(); ++i) {
        for (int j = 0; j < dataArray[i].size(); ++j) {
            if (dataArray[i][j] == number) {
                return i * 10 + j; // Calculate the index based on row and column
            }
        }
    }
    return -1; // Number not found, return -1
}

std::pair<int, int> ArrayOperations::modifyInteger(int index, int newValue) {
    if (index < 0 || index >= 100) {
        throw std::out_of_range("Invalid index."); // Check if the index is valid
    }

    int row = index / 10; // Calculate the row based on the index
    int col = index % 10; // Calculate the column based on the index
    int oldValue = dataArray[row][col]; // Store the old value before modification
    dataArray[row][col] = newValue; // Modify the value in the dataArray

    return std::make_pair(oldValue, newValue); // Return a pair of old and new values
}

void ArrayOperations::addInteger(int number) {
    std::vector<int> line;
    line.push_back(number); // Create a new line with the specified number
    dataArray.push_back(line); // Add the line to the dataArray
}

void ArrayOperations::replaceInteger(int index, int newValue) {
    if (index < 0 || index >= 100) {
        throw std::out_of_range("Invalid index."); // Check if the index is valid
    }

    int row = index / 10; // Calculate the row based on the index
    int col = index % 10; // Calculate the column based on the index
    dataArray[row][col] = newValue; // Replace the value at the specified index
}

void ArrayOperations::removeInteger(int index) {
    if (index < 0 || index >= 100) {
        throw std::out_of_range("Invalid index."); // Check if the index is valid
    }

    int row = index / 10; // Calculate the row based on the index
    int col = index % 10; // Calculate the column based on the index
    dataArray[row].erase(dataArray[row].begin() + col); // Erase the element at the specified index in the row

    if (dataArray[row].empty()) {
        dataArray.erase(dataArray.begin() + row); // If the row becomes empty, erase the row from the dataArray
    }
}
