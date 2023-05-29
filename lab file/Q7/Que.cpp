
#include <stdio.h>
#include <ctime>
#include "custom.cpp"

void insertionSort(int arr[], int size, int& shiftCount, int& comparisonCount) {
    shiftCount = 0, comparisonCount = 0;
    for (int i = 1; i < size; ++i) {
        int key = arr[i];
        int j = i - 1;
        
        // Perform shifting and count shifts
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
            ++shiftCount;
        }
        
        // Perform comparison and count comparisons
        ++comparisonCount;
        
        arr[j + 1] = key;
    }
}

int main() {
    int T;
    scanf("%d", &T);
    int size = 1000;
    int itr = 0;
    int i = 0;
    int comparisonCount = 0, shiftCount = 0;
    ResultHeader("SNo,Size,ShiftCount,ComparisonCount");
    while(i++ < T){
        printf("%d ", i);
        int* arr = randArrayInt(size, 0);
        itr = 0;
    //####################################################    
        insertionSort(arr, size, shiftCount, comparisonCount);
    //####################################################
        // cout << "cout" << execution_time << flag << size << itr << key << endl;
        Result(i,size,shiftCount,comparisonCount);
        cout << endl;
        delete[] arr;
        size += 999;
    }
        printf("\ndone\n");
    return 0;
}

