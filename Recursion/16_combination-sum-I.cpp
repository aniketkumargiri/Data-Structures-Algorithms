// Combination sum: Multiple pick allowed
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;

void f(int i, int n, int target, vector<int> ds, int a[]) {
    if (i == n) {
        if (target == 0) {
            ans.push_back(ds);
        }
        return;
    }

    // pick
    if (a[i] <= target) {
        ds.push_back(a[i]);
        f(i, n, target - a[i], ds, a);
        ds.pop_back();
    }

    // not pick
    f(i + 1, n, target, ds, a);
}

int main() {
    int a[] = {2, 3, 6, 7};
    int target;
    cin >> target;

    f(0, 4, target, vector<int>(), a);

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
