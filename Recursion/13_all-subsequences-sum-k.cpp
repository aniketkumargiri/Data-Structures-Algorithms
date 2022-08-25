// Print subsequences whose sum is k
#include <bits/stdc++.h>
using namespace std;

void print(vector<int> ds) {
    for (int i = 0; i < ds.size(); i++) {
        cout << ds[i] << " ";
    }
    cout << endl;
}

void f(int i, int s, int n, int k, vector<int> ds, int a[],
       vector<vector<int>> &ans) {
    if (i == n) {
        if (s == k) {
            // print(ds);
            ans.push_back(ds);
        }
        return;
    }

    // take
    ds.push_back(a[i]);
    s += a[i];
    f(i + 1, s, n, k, ds, a, ans);
    s -= a[i];
    ds.pop_back();

    // non-take
    f(i + 1, s, n, k, ds, a, ans);
}

int main() {
    int a[] = {1, 2, 1};
    int k;
    cin >> k;

    vector<vector<int>> ans;
    f(0, 0, 3, k, vector<int>(), a, ans);

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}