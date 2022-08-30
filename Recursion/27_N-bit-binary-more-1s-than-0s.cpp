//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution {
    void solve(string s, int ones, int zeros, int n, int num,
               vector<string> &ans) {
        if (n == 0) {
            ans.push_back(s);
            return;
        }

        if (ones <= num) {
            solve(s + '1', ones + 1, zeros, n - 1, num, ans);
        }
        if (ones > zeros) {
            solve(s + '0', ones, zeros + 1, n - 1, num, ans);
        }
    }

   public:
    vector<string> NBitBinary(int n) {
        // Your code goes here
        int ones = 0;
        int twos = 0;
        vector<string> ans;

        solve("", ones, twos, n, n, ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        vector<string> ans = ob.NBitBinary(n);

        for (auto i : ans) cout << i << " ";

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends