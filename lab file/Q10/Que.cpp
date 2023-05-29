#include <iostream>
#include "custom.cpp"

int partition(int arr[], int low, int high, int& shiftCount, int& comparisonCount) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        ++comparisonCount;
        if (arr[j] <= pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
            ++shiftCount;   // Count the number of shifts
        }
    }

    std::swap(arr[i + 1], arr[high]);
    ++shiftCount;   // Count the number of shifts

    return i + 1;
}

void quickSort(int arr[], int low, int high, int& shiftCount, int& comparisonCount) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high, shiftCount, comparisonCount);
        quickSort(arr, low, pivotIndex - 1, shiftCount, comparisonCount);
        quickSort(arr, pivotIndex + 1, high, shiftCount, comparisonCount);
    }
}

void quickSortWithCount(int arr[], int size, int& shiftCount, int& comparisonCount) {
    shiftCount = 0;
    comparisonCount = 0;
    quickSort(arr, 0, size - 1, shiftCount, comparisonCount);
}

int main() {
    int T;
    scanf("%d", &T);
    int size = 1000;
    int itr = 0;
    int i = 0;
    int comparisonCount = 0, shiftCount = 0;
    ResultHeader("SNo,Size,ShiftCount,ComparisonCount");
    while (i++ < T) {
        printf("%d ", i);
        int* arr = randArrayInt(size, 0);
        itr = 0;
        quickSortWithCount(arr, size, shiftCount, comparisonCount);
        Result(i, size, shiftCount, comparisonCount);
        cout << endl;
        delete[] arr;
        size += 999;
    }
    printf("\ndone\n");
    return 0;
}
