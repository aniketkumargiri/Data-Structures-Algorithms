// Print any subsequences whose sum is k
#include <bits/stdc++.h>
using namespace std;

void print(vector<int> ds) {
    for (int i = 0; i < ds.size(); i++) {
        cout << ds[i] << " ";
    }
    cout << endl;
}

bool f(int i, int s, int n, int k, vector<int> ds, int a[]) {
    if (i == n) {
        if (s == k) {
            print(ds);
            return true;
        } else {
            return false;
        }
    }

    // take
    ds.push_back(a[i]);
    s += a[i];
    if (f(i + 1, s, n, k, ds, a) == true) {
        return true;
    }
    s -= a[i];
    ds.pop_back();

    // non-take
    if (f(i + 1, s, n, k, ds, a) == true) {
        return true;
    }

    return false;
}

int main() {
    int a[] = {1, 2, 1};
    int k;
    cin >> k;

    bool isTrue = f(0, 0, 3, k, vector<int>(), a);
    if (isTrue) {
        cout << "Subsequence printed succesfully\n";
    } else {
        cout << "No valid subsequence exits for such input\n";
    }

    return 0;
}