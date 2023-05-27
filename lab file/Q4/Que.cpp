
#include <stdio.h>
#include <ctime>
#include <cmath>
#include "custom.cpp"


int binarySearch(int arr[], int low, int high, int key, int *itr) {
    while (low <= high) {
        (*itr)++;
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return -1;
}

int algo(int arr[], int size, int key, int *itr) {
    int index = binarySearch(arr, 0, size - 1, key, itr);
    
    if (index == -1) {
        return 0;
    }
    
    int count = 1;
    
    int left = index - 1;
    while (left >= 0 && arr[left] == key) {
        (*itr)++;
        count++;
        left--;
    }
    
    int right = index + 1;
    while (right < size && arr[right] == key) {
        (*itr)++;
        count++;
        right++;
    }
    
    return count;
}

int main() {
    int T;
    scanf("%d", &T);
    int size = 1000;
    int itr;
    int i=0;
    ResultHeader("SNo,Time,Count,Size,Iterations,Key");
    while(i++ < T){
        printf("%d ", i);
        int* arr = randArray(size, 1);
        int key = randElement(arr, size, 1);
        sort(arr, arr + size);
        itr = 0;
    //####################################################    
        clock_t start_time, end_time;
        double execution_time;

        start_time = clock(); // Record the starting time

        // Call the function for which you want to calculate the time complexity
        int count = algo(arr, size, key, &itr);

        end_time = clock(); // Record the ending time

        execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    //####################################################
        // cout << "cout" << execution_time << flag << size << itr << key << endl;
        Result(i,execution_time, count, size, itr, key);
        cout << endl;
        delete[] arr;
        size += 999;
    }
        printf("\ndone\n");
    return 0;
}

