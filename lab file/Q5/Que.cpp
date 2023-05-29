
#include <stdio.h>
#include <iostream>
using namespace std;
int findAllIndices(int arr[], int size) {
    cout << "arr : ";
    for(int i=0;i<size;i++) cout << arr[i] << " ";
    cout << endl;

    int count = 0;
    for (int k = size - 1; k >= 0; --k) {
        int i = 0;             // Pointer for the first element
        int j = k - 1;         // Pointer for the second element
        while (i < j) {
            int sum = arr[i] + arr[j];
            if (sum == arr[k]) {
                count++;
                cout << "Indices: " << i << ", " << j << ", " << k << endl;
                cout << "Sum: " << arr[i] << ", " << arr[j] << ", " << arr[k] << endl;
                ++i;  // Move the first pointer forward
                --j;  // Move the second pointer backward
            } else if (sum < arr[k]) {
                ++i;  // Increment the first pointer
            } else {
                --j;  // Decrement the second pointer
            }
        }
    }
    return count;
}

int main() {
    int T;
    scanf("%d", &T);
    int i=0;
    int start, size;
    float gap;
    while(i++ < T){
       cout << "range (start:1 gap:2 size:10)";
       cin >> start >> gap >> size;
       int *arr = new int[size]; 
       for(int i=0;i<size;i++) arr[i] = start + (int)i*gap;
       int count = findAllIndices(arr, size);
       if(!count) cout << "No Indices Found !" << endl;
       else cout << "Total No of Indices Found : " << count << endl;
    }
    printf("\ndone\n");
    return 0;
}

