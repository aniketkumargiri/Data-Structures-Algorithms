// Print all permutations
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;

void f(int idx, int n, vector<int> ds, int *a) {
    if (idx == n) {
        ans.push_back(ds);
        return;
    }

    for (int i = idx; i < n; i++) {
        // pick
        ds.push_back(a[i]);
        swap(a[i], a[idx]);
        f(idx + 1, n, ds, a);
        ds.pop_back();

        // return
        swap(a[i], a[idx]);
    }
}

int main() {
    int a[] = {1, 2, 3};
    f(0, 3, vector<int>(), a);

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}