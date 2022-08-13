// Print all subsequences
#include <bits/stdc++.h>
using namespace std;

void print(vector<int> ds) {
    for (int i = 0; i < ds.size(); i++) {
        cout << ds[i] << " ";
    }
    cout << endl;
}

void f(int i, int n, vector<int> ds, int a[]) {
    if (i >= n) {
        print(ds);
        return;
    }

    // take
    ds.push_back(a[i]);
    f(i + 1, n, ds, a);
    ds.pop_back();

    // non-take
    f(i + 1, n, ds, a);
}

int main() {
    int a[] = {1, 2, 3};
    f(0, 3, vector<int>(), a);

    return 0;
}