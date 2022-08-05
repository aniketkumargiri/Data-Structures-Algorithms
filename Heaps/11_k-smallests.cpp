// K Smallest Elements
#include <bits/stdc++.h>
using namespace std;

// max heap
vector<int> kSmallests(int arr[], int n, int k) {
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        pq.push(arr[i]);
        if (pq.size() > k) {
            pq.pop();
        }
    }

    vector<int> ans;
    while (!pq.empty()) {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}

int main() {
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);

    int k = 3;
    // cin >> k;

    vector<int> ans = kSmallests(arr, n, k);
    for (auto i : ans) {
        cout << i << " ";
    }

    return 0;
}