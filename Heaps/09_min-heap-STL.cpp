// Min Heap using STL Priority Queue
#include <bits/stdc++.h>
using namespace std;

int main() {
    // min heap
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(50);
    pq.push(55);
    pq.push(53);
    pq.push(52);
    pq.push(54);

    cout << "Top element: " << pq.top() << endl;
    cout << "Size of min heap: " << pq.size() << endl;

    cout << "Printing elements of the min heap: ";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }

    if (pq.empty()) {
        cout << "\nPriority Queue is empty\n";
    } else {
        cout << "\nPriority Queue is not empty\n";
    }

    return 0;
}