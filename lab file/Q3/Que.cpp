
#include <stdio.h>
#include <ctime>
#include <cmath>
#include "custom.cpp"


int algo(int arr[], int n, int key, int* itr) {
    int step = static_cast<int>(sqrt(n)); // Define the jump size

    int prev = 0;
    while (arr[min(step, n) - 1] < key) {
        (*itr)++;
        prev = step;
        step += static_cast<int>(sqrt(n));
        if (prev >= n) {
            return 0; // Key not found
        }
    }

    while (arr[prev] < key) {
        (*itr)++;
        prev++;
        if (prev == min(step, n)) {
            return 0; // Key not found
        }
    }

    if (arr[prev] == key) {
        return 1; // Key found
    }

    return 0; // Key not found
}

int main() {
    int T;
    scanf("%d", &T);
    int size = 1000;
    int itr;
    int i=0;
    ResultHeader("SNo,Time,Flag,Size,Iterations,Key");
    while(i++ < T){
        printf("%d ", i);
        int* arr = randArray(size, 0);
        int key = randElement(arr, size, 0);
        sort(arr, arr + size);
        itr = 0;
    //####################################################    
        clock_t start_time, end_time;
        double execution_time;

        start_time = clock(); // Record the starting time

        // Call the function for which you want to calculate the time complexity
        int flag = algo(arr, size, key, &itr);

        end_time = clock(); // Record the ending time

        execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    //####################################################
        // cout << "cout" << execution_time << flag << size << itr << key << endl;
        Result(i,execution_time, flag, size, itr, key);
        cout << endl;
        delete[] arr;
        size += 999;
    }
        printf("\ndone\n");
    return 0;
}

