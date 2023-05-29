
#include <stdio.h>
#include <ctime>
#include "custom.cpp"

int algo(int arr[], int n, int key, int *itr) {
    int low = 0;
    int high = n - 1;
    
    while (low <= high) {
        (*itr)++;
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == key) {
            return 1;
        }
        else if (arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    
    return 0; // Key not found
}

int main() {
    int T;
    scanf("%d", &T);
    int size = 100;
    int itr;
    int i=0;
    ResultHeader("SNo,Time,Flag,Size,Iterations,Key");
    while(i++ < T){
        printf("%d ", i);
        int* arr = randArrayInt(size, 0);
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
        size += 200;
    }
        printf("\ndone\n");
    return 0;
}

