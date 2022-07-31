// Deletion in Heap
#include <bits/stdc++.h>
using namespace std;
#define N 100

class heap {
   public:
    int arr[N];
    int size;

    heap() {
        arr[0] = -1;
        size = 0;
    }

    // insertion in max heap
    void insert(int val) {  // log(n)
        size = size + 1;
        int index = size;
        arr[index] = val;

        while (index > 1) {
            int parent = index / 2;
            if (arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
            } else {
                return;
            }
        }
    }

    // deletion in max heap
    void deleteFromHeap() {  // log(n)
        if (size == 0) {
            cout << "Nothing to delete\n";
            return;
        }

        // put last element into first index
        arr[1] = arr[size];
        size--;

        // take root node to its correct position
        int i = 1;
        while (i < size) {
            int leftIndex = 2 * i;
            int rightIndex = 2 * 1 + 1;

            if (leftIndex < size && arr[i] < arr[leftIndex]) {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            } else if (rightIndex < size && arr[i] < arr[rightIndex]) {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            } else {
                return;
            }
        }
    }

    // printing the heap
    void print() {
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    // heap object
    heap h;

    // insertion in max heap
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    // printing the max heap
    h.print();

    // deletion in max heap
    h.deleteFromHeap();

    // printing the max heap after deletion
    h.print();

    return 0;
}
