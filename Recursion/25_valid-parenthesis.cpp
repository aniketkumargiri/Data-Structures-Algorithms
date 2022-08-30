// Generate valid parenthesis
#include <bits/stdc++.h>
using namespace std;

void help(int open, int close, int n, string s, vector<string> &ans) {
    if (open + close == 2 * n) {
        ans.push_back(s);
        return;
    }

    if (open < n) {
        help(open + 1, close, n, s + "(", ans);
    }
    if (close < open) {
        help(open, close + 1, n, s + ")", ans);
    }
}

void f(int n) {
    vector<string> ans;
    help(0, 0, n, "", ans);

    for (auto &i : ans) {
        cout << i << endl;
    }
}

int main() {
    int n;
    cin >> n;
    f(n);

    return 0;
}