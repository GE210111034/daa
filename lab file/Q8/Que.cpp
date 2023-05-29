
#include <stdio.h>
#include <ctime>
#include "custom.cpp"

void selectionSort(int arr[], int size, int& shiftCount, int& comparisonCount) {
    shiftCount = 0, comparisonCount = 0;
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            ++comparisonCount;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        // Swap elements and count shifts
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            ++shiftCount;
        }
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
        selectionSort(arr, size, shiftCount, comparisonCount);
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

