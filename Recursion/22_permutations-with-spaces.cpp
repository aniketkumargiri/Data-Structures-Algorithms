//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    void solve(int i, string s, int n, string op, vector<string>& ans) {
        op.push_back(s[i]);
        if (i == n - 1) {
            ans.push_back(op);
            return;
        }

        // include
        op.push_back(' ');
        solve(i + 1, s, n, op, ans);
        op.pop_back();

        // exclude
        solve(i + 1, s, n, op, ans);
    }

   public:
    vector<string> permutation(string s) {
        // Code Here
        vector<string> ans;
        solve(0, s, s.length(), "", ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for (int i = 0; i < ans.size(); i++) {
            cout << "(" << ans[i] << ")";
        }
        cout << endl;
    }
}

// } Driver Code Ends
