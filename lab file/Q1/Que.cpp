
#include <stdio.h>
#include <ctime>
#include "custom.cpp"

int algo(int arr[], int n, int key, int *itr) {
    int i;
    // Your algorithm implementation here
    for (i = 0; i < n; i++) {
        (*itr)++;
        if (arr[i] == key) {
            return 1; // Key found
        }
    }
    // ...
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

