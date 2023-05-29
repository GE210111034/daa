#include <iostream>
using namespace std;

void insertionSort(int arr[], int size, int& shiftCount, int& comparisonCount) {
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
    cin >> T;

    int i = 0;
    int start, size, key;
    float gap;

    while (i++ < T) {
        cout << "range (start:1 gap:2 size:10 key:5)";
        cin >> start >> gap >> size >> key;

        int *arr = new int[size];
        for (int i = 0; i < size; i++)
            arr[i] = start + (int)i * gap;

        int count = findAllPairsWithDifference(arr, size, key);
        if (count == 0)
            cout << "No pair Found !" << endl;
        else
            cout << "Total No of pair Found: " << count << endl;

        delete[] arr;
    }

    cout << "\ndone\n";
    return 0;
}
