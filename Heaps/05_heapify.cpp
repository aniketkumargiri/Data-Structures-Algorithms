// Heapify Algorithm
#include <bits/stdc++.h>
using namespace std;

// Build max heap
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[largest] < arr[left]) {
        largest = left;
    }
    if (right <= n && arr[largest] < arr[right]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[largest], arr[i]);
        // heapify function call
        heapify(arr, n, largest);
    }
}

int main() {
    // heapify --> O(log(n))
    // build heap --> O(N)
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for (int i = n / 2; i > 0; i--) {
        heapify(arr, n, i);
    }

    cout << "Printing the array after heapifying:\n";
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
/*
CBT: leaf nodes
                (n/2+1)th --> nth node
*/