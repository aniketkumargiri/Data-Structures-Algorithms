// count the subsequences whose sum is k
#include <bits/stdc++.h>
using namespace std;

int f(int i, int s, int n, int k, int a[]) {
    if (i == n) {
        if (s == k) {
            return 1;
        } else {
            return 0;
        }
    }

    // take
    s += a[i];
    int first = f(i + 1, s, n, k, a);
    s -= a[i];

    // non-take
    int second = f(i + 1, s, n, k, a);

    return first + second;
}

int main() {
    int a[] = {1, 2, 1};
    int k;
    cin >> k;

    cout << f(0, 0, 3, k, a) << endl;

    return 0;
}