/**
 * @file 18_kth-largest-sum-subarray.cpp
 * @author Anikthe_27 (aniket.kumar.giri2707@gmail.com)
 * @brief K-th Largest Sum Subarray
 * @date 2022-08-10
 *
 * @copyright Copyright @ani, 2022
 *
 */
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
   public:
    /*
     // sorting
     int kthLargest(vector<int> &arr, int n, int k) {
         //	Write your code here.
         vector<int> sum;
         for (int i = 0; i < n; i++) {
             int s = 0;
             for (int j = i; j < n; j++) {
                 s += arr[j];
                 sum.push_back(s);
             }
         }

         sort(sum.begin(), sum.end());
         return sum[sum.size() - k];
     }
     */

    // min heap
    int kthLargest(vector<int> &Arr, int N, int K) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < N; i++) {
            int sum = 0;
            for (int j = i; j < N; j++) {
                sum += Arr[j];
                /*
                pq.push(sum);
                if (pq.size() > K) {
                    pq.pop();
                }
                */
                if (pq.size() < K) {
                    pq.push(sum);
                } else {
                    if (sum > pq.top()) {
                        pq.pop();
                        pq.push(sum);
                    }
                }
            }
        }
        return pq.top();
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N;
        cin >> K;
        vector<int> Arr(N);
        for (int i = 0; i < N; i++) {
            cin >> Arr[i];
        }
        Solution ob;
        int ans = ob.kthLargest(Arr, N, K);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends