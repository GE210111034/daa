#include <iostream>
#include <ctime>
#include "custom.cpp"

char algo(char arr[], int size, int& itr) {
    const int MAX_CHAR = 256;  // Assuming ASCII character set
    int charCount[MAX_CHAR] = {0};
    char highestChar = '\0';
    int highestCount = 0;
    for (int i = 0; i < size; i++) {
        itr++;
        char currentChar = arr[i];
        charCount[currentChar]++;
        int currentCount = charCount[currentChar];
        if (currentCount > highestCount) {
            highestChar = currentChar;
            highestCount = currentCount;
        }
    }
    return highestChar;
}
int main() {
    int T;
    std::cin >> T;
    int size = 100;
    int i = 0;
    ResultHeader("SNo,Time,Size,Iterations,char");
    while (i++ < T) {
        std::cout << i << " ";
        char* arr = randArrayChar(size, 1);
        int itr = 0;
// #############################################
        clock_t start_time, end_time;
        double execution_time;
        start_time = clock(); // Record the starting time
        char ch = algo(arr, size, itr);
        end_time = clock(); // Record the ending time
        execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
// #############################################
        Result(i, execution_time, size, itr, ch);
        std::cout << std::endl;
        delete[] arr;
        size += 200;
    }
    std::cout << "\ndone\n";
    return 0;
}

