// Frequency Sort
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

// min heap
vector<int> kFrequent(int arr[], int n) {
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp[arr[i]]++;
    }

    priority_queue<pi, vector<pi>, greater<pi>> pq;
    for (auto i : mp) {
        pq.push({i.second, i.first});
    }

    vector<int> ans;
    while (!pq.empty()) {
        int freq = pq.top().first;
        int ele = pq.top().second;
        for (int i = 0; i < freq; i++) {
            ans.push_back(ele);
        }
        pq.pop();
    }
    return ans;
}

int main() {
    int arr[] = {1, 1, 2, 1, 1, 3, 2, 2, 4, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<int> ans = kFrequent(arr, n);
    for (auto i : ans) {
        cout << i << " ";
    }
    return 0;
}