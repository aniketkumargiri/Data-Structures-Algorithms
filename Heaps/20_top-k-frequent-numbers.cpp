// Top K Frequent Numbers
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

// min heap
vector<int> kFrequent(int arr[], int n, int k) {
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp[arr[i]]++;
    }

    priority_queue<pi, vector<pi>, greater<pi>> pq;
    for (auto i : mp) {
        pq.push({i.second, i.first});
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
    int arr[] = {1, 1, 2, 1, 1, 3, 2, 2, 4, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int k = 3;
    // cin >> k;

    vector<int> ans = kFrequent(arr, n, k);
    for (auto i : ans) {
        cout << i << " ";
    }
    return 0;
}