// Insertion in Heap
#include <bits/stdc++.h>
using namespace std;
#define N 100

// 1 based indexing
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

    return 0;
}
