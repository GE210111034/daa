#include<bits/stdc++.h>
using namespace std;

typedef vector<int> IntArray;


// Function to generate a random array with unique elements
IntArray GenerateIntArray(int size) {
    IntArray arr(size+1);

    // Generate a sequence of unique random numbers
    for (int i = 0; i < size; ++i) {
        arr[i] = i + 1; // Initialize array with consecutive numbers
    }
    // Shuffle the array to randomize the order
    random_shuffle(arr.begin(), arr.end());

    return arr;
}


