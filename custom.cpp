#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Global file stream object for writing to "output1.csv"
FILE* outputFile;

int* randArrayInt(int size, int dpt) {
    int* arr = (int*)malloc(size * sizeof(int));
    int start = 1, end;
    if (!dpt) {
        end = size * 2;
        // Generate a range of unique numbers
        int* uniqueArr = (int*)malloc((end - start + 1) * sizeof(int));
        for (int i = 0; i < end - start + 1; i++) {
            uniqueArr[i] = start + i;
        }
        // Shuffle the unique numbers
        srand(time(NULL));
        for (int i = end - start; i > 0; i--) {
            int j = rand() % (i + 1);
            int temp = uniqueArr[i];
            uniqueArr[i] = uniqueArr[j];
            uniqueArr[j] = temp;
        }

        // Take the first 'size' elements from the shuffled array
        for (int i = 0; i < size; i++) {
            arr[i] = uniqueArr[i];
        }
        free(uniqueArr);
    }
    else {
        end = size * 0.66;
        // Generate random numbers with the possibility of duplicates
        srand(time(NULL));
        for (int i = 0; i < size; i++) {
            arr[i] = start + rand() % (end - start + 1);
        }
    }
    return arr;
}

int randElement(int* arr, int size, int dpt) {
    if (dpt == 0) {
        srand(time(NULL));  // Seed the random number generator
        int randIndex = rand() % size;
        return arr[randIndex];
    }
    else if (dpt == 1) {
        int* duplicates = (int*)malloc(size * sizeof(int));
        int* uniqueElements = (int*)malloc(size * sizeof(int));
        int duplicateCount = 0;
        int uniqueCount = 0;
        for (int i = 0; i < size; i++) {
            bool isDuplicate = false;
            for (int j = 0; j < uniqueCount; j++) {
                if (arr[i] == uniqueElements[j]) {
                    isDuplicate = true;
                    break;
                }
            }
            if (isDuplicate) {
                duplicates[duplicateCount++] = arr[i];
            }
            else {
                uniqueElements[uniqueCount++] = arr[i];
            }
        }
        if (duplicateCount == 0) {
            // Return middle element if no appropriate key is found
            free(duplicates);
            free(uniqueElements);
            return size / 2;
        }

        // Sort the array
        for (int i = 0; i < duplicateCount - 1; i++) {
            for (int j = 0; j < duplicateCount - i - 1; j++) {
                if (duplicates[j] > duplicates[j + 1]) {
                    int temp = duplicates[j];
                    duplicates[j] = duplicates[j + 1];
                    duplicates[j + 1] = temp;
                }
            }
        }

        srand(time(NULL));  // Seed the random number generator
        int randIndex = rand() % duplicateCount;
        int result = duplicates[randIndex];
        free(duplicates);
        free(uniqueElements);
        return result;
    }

    // Invalid dpt value, return -1 or any other value to indicate an error
    return size / 2; // Return middle element if no appropriate key is found
}

// Function to write the header to the output file
void ResultHeader(const char* header) {
    outputFile = fopen("output1.csv", "a");
    fprintf(outputFile, "%s\n", header);
    fclose(outputFile);
}

// Function to write a row of values to the output file
void Result(const char* format, ...) {
    va_list args;
    va_start(args, format);
    char line[256];
    vsprintf(line, format, args);
    va_end(args);

    outputFile = fopen("output1.csv", "a");
    fprintf(outputFile, "%s\n", line);
    fclose(outputFile);
}
