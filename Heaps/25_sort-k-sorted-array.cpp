// Sort a K sorted/nearly sorted array
#include <bits/stdc++.h>
using namespace std;

// min heap
vector<int> kSorted(int arr[], int n, int k) {
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++) {
        pq.push(arr[i]);
        if (pq.size() > k) {
            ans.push_back(pq.top());
            pq.pop();
        }
    }

    while (!pq.empty()) {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}

int main() {
    int arr[] = {6, 5, 3, 2, 8, 10, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    int k = 4;
    // cin >> k;

    vector<int> ans = kSorted(arr, n, k);
    for (auto i : ans) {
        cout << i << " ";
    }
    return 0;
}