// Heapify Algorithm
#include <bits/stdc++.h>
using namespace std;

// Build min heap: 0 based indexing
void heapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[smallest] > arr[left]) {
        smallest = left;
    }
    if (right < n && arr[smallest] > arr[right]) {
        smallest = right;
    }

    if (smallest != i) {
        swap(arr[smallest], arr[i]);
        // heapify function call
        heapify(arr, n, smallest);
    }
}

int main() {
    // heapify --> O(log(n))
    // build heap --> O(N)
    int arr[] = {54, 53, 55, 52, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    cout << "Printing the array after heapifying:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
