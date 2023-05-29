
#include <stdio.h>
#include <ctime>
#include <cmath>
#include "custom.cpp"

void merge(int arr[], int left, int mid, int right, int* itr) {
    (*itr)++;
    int n1 = mid - left + 1;  // Size of the left subarray
    int n2 = right - mid;     // Size of the right subarray

    int* P = new int[n1];     // Temporary array for the left subarray
    int* Q = new int[n2];     // Temporary array for the right subarray

    // Copy data to the temporary arrays
    for (int i = 0; i < n1; ++i) {
        P[i] = arr[left + i];
    }
    for (int j = 0; j < n2; ++j) {
        Q[j] = arr[mid + 1 + j];
    }

    int i = 0;    // Index for the left subarray
    int j = 0;    // Index for the right subarray
    int k = left; // Index for the merged array

    // Merge the two subarrays back into the original array
    while (i < n1 && j < n2) {
        if (P[i] <= Q[j]) {
            arr[k++] = P[i++];
        } else {
            arr[k++] = Q[j++];
        }
    }

    // Copy the remaining elements from the left subarray, if any
    while (i < n1) {
        arr[k++] = P[i++];
    }

    // Copy the remaining elements from the right subarray, if any
    while (j < n2) {
        arr[k++] = Q[j++];
    }

    // Free the temporary arrays
    delete[] P;
    delete[] Q;
}

void mergeSort(int arr[], int left, int right, int* itr) {
    (*itr)++;
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Recursively sort the two halves
        mergeSort(arr, left, mid, itr);
        mergeSort(arr, mid + 1, right, itr);

        // Merge the sorted halves
        merge(arr, left, mid, right, itr);
    }
}

int algo(int arr[], int size, int key, int* itr) {
    mergeSort(arr, 0, size - 1, itr);
    int count = 0;
    for (int i = 0; i < size; i++) {
        (*itr)++;
        if (arr[i] == key) {
            count++;
            for (int j = i + 1; arr[j] == key; j++, count++);
            break;
        }
    }
    return count;
}

int main() {
    int T;
    scanf("%d", &T);
    int size = 100;
    int itr;
    int i=0;
    ResultHeader("SNo,Time,Count,Size,Iterations,Key");
    while(i++ < T){
        printf("%d ", i);
        int* arr = randArrayInt(size, 1);
        int key = randElement(arr, size, 1);
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
        size += 200;
    }
        printf("\ndone\n");
    return 0;
}

