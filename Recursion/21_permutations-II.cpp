// Print all permutations
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;

void f(int n, int freq[], vector<int> ds, int *a) {
    if (ds.size() == n) {
        ans.push_back(ds);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!freq[i]) {
            ds.push_back(a[i]);
            freq[i] = 1;
            f(n, freq, ds, a);
            freq[i] = 0;
            ds.pop_back();
        }
    }
}

int main() {
    int a[] = {1, 2, 3};
    int n = sizeof(a) / sizeof(a[0]);
    int freq[n] = {0};

    f(n, freq, vector<int>(), a);

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}