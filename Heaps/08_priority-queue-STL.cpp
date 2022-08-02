// Max Heap using STL Priority Queue
#include <bits/stdc++.h>
using namespace std;

int main() {
    // max heap
    priority_queue<int> pq;
    pq.push(50);
    pq.push(55);
    pq.push(53);
    pq.push(52);
    pq.push(54);

    cout << "Top element: " << pq.top() << endl;
    cout << "Size of max heap: " << pq.size() << endl;

    cout << "Printing elements of the max heap: ";
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