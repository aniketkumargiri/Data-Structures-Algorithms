// Combination sum-II: Single pick allowed, no duplicates, sorted & lexographical
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;

void f(int idx, int n, int target, vector<int> ds, int a[]) {
    if (target == 0) {
        ans.push_back(ds);
        return;
    }

    for (int i = idx; i < n; i++) {
        if (i != idx && a[i] == a[i - 1]) {
            continue;
        }
        if (a[i] > target) {  // In case of only positive numbers
            break;
        }

        ds.push_back(a[i]);
        f(idx + 1, n, target - a[i], ds, a);
        ds.pop_back();
    }
}

int main() {
    int a[] = {1, 1, 1, 2, 2};
    int n = sizeof(a) / sizeof(a[0]);
    sort(a, a + n);

    int target;
    cin >> target;
    f(0, n, target, vector<int>(), a);

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
