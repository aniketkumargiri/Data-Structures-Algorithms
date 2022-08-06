// K Largest Elements
#include <bits/stdc++.h>
using namespace std;

// min heap
vector<int> kLargests(int arr[], int n, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
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

    int k = 4;
    // cin >> k;

    vector<int> ans = kLargests(arr, n, k);
    for (auto i : ans) {
        cout << i << " ";
    }

    return 0;
}