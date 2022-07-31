// Printing the Heap
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

    void print() {
        for (int i = 0; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    // heap object
    heap h;

    // printing the max heap
    h.print();

    return 0;
}
/*
Heap is a complete binary tree that comes with a heap order property
Heap Order Property: Max Heap, Min Heap
Max Heap: Every root node is aleways greater than its children
Min Heap: Every root node is aleways smaller than its children
CBT: every level is completely filled except the last level
     nodes always lean towards the left
*/