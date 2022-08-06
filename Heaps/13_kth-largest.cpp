// Kth Largest Element
#include <bits/stdc++.h>
using namespace std;

// min heap
int kthLargest(int arr[], int n, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < k; i++) {
        pq.push(arr[i]);
    }

    for (int i = k; i < n; i++) {
        if (arr[i] > pq.top()) {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    int ans = pq.top();
    return ans;
}

int main() {
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);

    int k = 4;
    // cin >> k;

    /*
    sort(arr, arr + n);
    cout << arr[n - k] << endl;
    */

    int ans = kthLargest(arr, n, k);
    cout << ans << endl;

    return 0;
}