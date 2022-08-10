// K Closest Numbers
#include <bits/stdc++.h>
using namespace std;

// max heap
vector<int> kClosest(int arr[], int n, int k, int x) {
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; i++) {
        pq.push({abs(arr[i] - x), arr[i]});
        if (pq.size() > k) {
            pq.pop();
        }
    }

    vector<int> ans;
    while (!pq.empty()) {
        int ele = pq.top().second;
        ans.push_back(ele);
        pq.pop();
    }
    return ans;
}

int main() {
    int arr[] = {10, 2, 14, 4, 7, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    int k = 3;
    // cin >> k;

    int x = 5;
    // cin >> x;

    vector<int> ans = kClosest(arr, n, k, x);
    for (auto i : ans) {
        cout << i << " ";
    }
    return 0;
}