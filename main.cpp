
#include <stdio.h>
#include <time>
#include "custom.cpp"

// Comparison function for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Function to find the kth smallest element
int findKthSmallest(int arr[], int size, int k) {
    // Sort the array using qsort
    qsort(arr, size, sizeof(int), compare);

    // Return the kth smallest element
    return arr[k - 1];
}

int main() {
    int T;
    scanf("%d", &T);
    int size = 1000;
    int itr;
    int i=0;
    // ResultHeader("Time,Flag,Size,Iterations,Key");
    while(i++ < T){ 
        printf("%d ", i);
        int* arr = randArrayInt(size, 0);
        // int key = randElement(arr, size, 0);
        int k = i > size ? i % size : i;
        printf("unsorted : %d", arr[k]);
        printf("kth : %d", findKthSmallest(arr, size, k));
        sort(arr, arr + size);
        printf(" sorted: %d", arr[k - 1]);
    //####################################################    
        // itr = 0;
        // clock_t start_time, end_time;
        // double execution_time;

        // start_time = clock(); // Record the starting time

        // // Call the function for which you want to calculate the time complexity
        // int flag = algo(arr, size, key, &itr);

        // end_time = clock(); // Record the ending time

        // execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    //####################################################
        // cout << "cout" << execution_time << flag << size << itr << key << endl;
        // Result(i,execution_time, flag, size, itr, key);
        print("\n");
        delete[] arr;
        size += 999;
    }
        printf("\ndone\n");
    return 0;
}

