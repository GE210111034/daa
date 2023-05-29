#include <iostream>
using namespace std;
int algo(int arr[], int size, int key) {
    cout << "arr : ";
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
    int count = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (arr[i] + arr[j] == key) {
                cout << "Pair found: (" << arr[i] << ", " << arr[j] << ")" << endl;
                count++;
            }
        }
    }
    return count;
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

        int count = algo(arr, size, key);
        if (count == 0)
            cout << "No pair Found !" << endl;
        else
            cout << "Total No of pair Found: " << count << endl;

        delete[] arr;
    }

    cout << "\ndone\n";
    return 0;
}
