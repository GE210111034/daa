#include <iostream>
#include <ctime>
#include "custom.cpp"
int partition(int arr[], int low, int high, int& itr) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {++itr;
        if(arr[j] <= pivot) { ++i; std::swap(arr[i], arr[j]);}
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}
void quickSort(int arr[], int low, int high, int& itr) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high, itr);
        quickSort(arr, low, pivotIndex - 1, itr);
        quickSort(arr, pivotIndex + 1, high, itr);
    }
}
int algo(int arr1[], int arr2[], int size1, int size2, int& itr) {
    quickSort(arr1, 0, size1 - 1, itr);
    quickSort(arr2, 0, size2 - 1, itr);
    int count = 0;
    int i = 0, j = 0;
    while (i < size1 && j < size2) {
        itr++;
        if (arr1[i] == arr2[j]) {
            count++;
            i++;
            j++;
        } else if (arr1[i] < arr2[j]) {
            i++;
        } else {
            j++;
        }
    }
    return count;
}
int main() {
    int T;
    cin >> T;
    int size = 100;
    int i = 0;
    ResultHeader("SNo,Time,Size,Iterations,Count");
    while (i++ < T) {
        cout << i << " ";
        int* arr1 = randArrayInt(size, 0);
        int* arr2 = randArrayInt(size, 0);
        int itr = 0;
// #############################################
        clock_t start_time, end_time;
        double execution_time;
        start_time = clock(); // Record the starting time
        int count = algo(arr1, arr2, size, size, itr);
        end_time = clock(); // Record the ending time
        execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
// ############################################# sort(arr, arr + size);
        Result(i, execution_time, size, itr, count);
        cout << endl;
        delete[] arr1;
        delete[] arr2;
        size += 10;
    }
    cout << "\ndone\n";
    return 0;
}
