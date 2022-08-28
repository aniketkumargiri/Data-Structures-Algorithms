// Subset Sum
#include <bits/stdc++.h>
using namespace std;

void f(int i, int n, int s, vector<int> &ds, int a[]) {
    if (i == n) {
        ds.push_back(s);
        // cout << s << endl;
        return;
    }

    f(i + 1, n, s + a[i], ds, a);
    f(i + 1, n, s, ds, a);
}

int main() {
    int a[] = {3, 1, 2};
    vector<int> ds;
    f(0, 3, 0, ds, a);

    for (int i = 0; i < ds.size(); i++) {
        cout << ds[i] << endl;
    }

    return 0;
}