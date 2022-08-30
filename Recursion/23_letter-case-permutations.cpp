// Letter case permutation
#include <bits/stdc++.h>
using namespace std;

void solve(int idx, string s, int n, vector<string> &ans) {
    if (idx == n) {
        ans.push_back(s);
        return;
    }

    if (isalpha(s[idx])) {
        s[idx] = toupper(s[idx]);
        solve(idx + 1, s, n, ans);
        s[idx] = tolower(s[idx]);
        solve(idx + 1, s, n, ans);
    } else {
        solve(idx + 1, s, n, ans);
    }
}

vector<string> letterCasePermutation(string s) {
    vector<string> ans;
    solve(0, s, s.length(), ans);
    return ans;
}

int main() {
    string s = "a1b2";
    vector<string> ans = letterCasePermutation(s);

    for (auto i : ans) {
        cout << i << endl;
    }
    return 0;
}