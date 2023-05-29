#include <iostream>
#include <ctime>
#include "custom.cpp"

int partition(int arr[], int low, int high, int& itr) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        itr++;
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

int quickSelect(int arr[], int low, int high, int k, int& itr) {
    itr++;
    if (k > 0 && k <= high - low + 1) {
        int pivotIndex = partition(arr, low, high, itr);

        if (pivotIndex - low == k - 1) {
            return arr[pivotIndex];
        }
        else if (pivotIndex - low > k - 1) {
            return quickSelect(arr, low, pivotIndex - 1, k, itr);
        }
        else {
            return quickSelect(arr, pivotIndex + 1, high, k - pivotIndex + low - 1, itr);
        }
    }

    // Return a value to indicate an error if k is out of range
    return -1;
}

int main() {
    int T;
    std::cin >> T;
    int size = 100;
    int i = 0;
    ResultHeader("SNo,Time,Size,Iterations,kth_smallest,sortkth");
    while (i++ < T) {
        std::cout << i << " ";
        int* arr = randArrayInt(size, 1);
        int k = i;
        int itr = 0;
        clock_t start_time, end_time;
        double execution_time;
// #############################################
        start_time = clock(); // Record the starting time

        int kth_smallest = quickSelect(arr, 0, size - 1, k, itr);

        end_time = clock(); // Record the ending time

        execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
// #############################################
        // sort(arr, arr + size);
        Result(i, execution_time, size, itr, kth_smallest, arr[k-1]);
        std::cout << std::endl;
        delete[] arr;
        size += 200;
    }
    std::cout << "\ndone\n";
    return 0;
}
