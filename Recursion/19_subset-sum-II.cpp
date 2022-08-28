// Subset Sum-II
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;

void f(int idx, int n, vector<int> ds, int a[]) {
    ans.push_back(ds);

    for (int i = idx; i < n; i++) {
        if (i > idx && a[i] == a[i - 1]) {
            continue;
        }
        ds.push_back(a[i]);
        f(i + 1, n, ds, a);
        ds.pop_back();
    }
}

int main() {
    int a[] = {1, 2, 2, 2, 3, 3};
    int n = sizeof(a) / sizeof(a[0]);
    sort(a, a + n);

    f(0, n, vector<int>(), a);

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}