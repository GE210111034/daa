#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// Global file stream object for writing to "output.csv"
ofstream outputFile;

int* randArrayInt(int size, int dpt) {
    int* arr = new int[size];
    int start = 1, end;
    if (!dpt) {
        end = size * 2;
        // Generate a range of unique numbers
        int* uniqueArr = new int[end - start + 1];
        for (int i = 0; i < end - start + 1; i++) {
            uniqueArr[i] = start + i;
        }
        // Shuffle the unique numbers
        srand(time(nullptr));
        random_shuffle(uniqueArr, uniqueArr + end - start + 1);
        
        // Take the first 'size' elements from the shuffled array
        for (int i = 0; i < size; i++) {
            arr[i] = uniqueArr[i];
        }
        delete[] uniqueArr;
    } else {
        end = size * 0.66;
        // Generate random numbers with the possibility of duplicates
        srand(time(nullptr));
        for (int i = 0; i < size; i++) {
            arr[i] = start + rand() % (end - start + 1);
        }
    }
    return arr;
}

int randElement(int* arr, int size, int dpt) {
    if (dpt == 0) {
        srand(time(nullptr));  // Seed the random number generator
        int randIndex = rand() % size;
        return arr[randIndex];
    } else if (dpt == 1) {
        unordered_set<int> duplicates;
        unordered_set<int> uniqueElements;
        for (int i = 0; i < size; i++) {
            if (uniqueElements.find(arr[i]) != uniqueElements.end()) {
                duplicates.insert(arr[i]);
            } else {
                uniqueElements.insert(arr[i]);
            }
        }
        if (duplicates.empty()) {
            // Return middle element if no appropriate key is found
            return (int) size * 0.5; 
        }

        srand(time(nullptr));  // Seed the random number generator
        int randIndex = rand() % duplicates.size();
        auto it = duplicates.begin();
        advance(it, randIndex);
        int result = *it;
        return result;
    }

    // Invalid dpt value, return -1 or any other value to indicate an error
    return (int) size * 0.5; // Return middle element if no appropriate key is found
}


// Function to write the header to the output file
void ResultHeader(const string& header) {
    outputFile.open("output.csv", ofstream::out | ofstream::app);
    outputFile << header << endl;
    outputFile.close();
}

// Function to write a row of values to the output file
template<typename... Args>
void Result(const Args&... args) {
    ostringstream oss;
    bool isFirst = true;
    ((oss << (isFirst ? "" : ",") << args, isFirst = false), ...);
    string line = oss.str();

    outputFile.open("output.csv", ofstream::out | ofstream::app);
    outputFile << line << endl;
    outputFile.close();
}




