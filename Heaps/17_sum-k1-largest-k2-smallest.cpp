/**
 * @file 17_sum-k1-largest-k2-smallest.cpp
 * @author Anikthe_27 (aniket.kumar.giri2707@gmail.com)
 * @brief Sum of Elements between k1 largest and k2 smallest numbers
 * @date 2022-08-10
 *
 * @copyright Copyright @ani, 2022
 *
 */

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    long long kthLargest(long long arr[], int n, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++) {
            pq.push(arr[i]);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }
    long long kthSmallest(long long arr[], int n, int k) {
        priority_queue<int> pq;
        for (int i = 0; i < n; i++) {
            pq.push(arr[i]);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }

   public:
    long long sumBetweenTwoKth(long long arr[], long long N, long long K1,
                               long long K2) {
        // Your code goes here
        long long num2 = kthLargest(arr, N, K1);
        long long num1 = kthSmallest(arr, N, K2);
        int ans = 0;
        for (int i = 0; i < N; i++) {
            if (arr[i] > num1 && arr[i] < num2) {
                ans += arr[i];
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n;
        long long a[n + 5];
        for (int i = 0; i < n; i++) cin >> a[i];

        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
    }
    return 0;
}

// } Driver Code Ends
