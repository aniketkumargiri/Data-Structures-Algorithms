// print 1 to n
#include <bits/stdc++.h>
using namespace std;

void f(int i, int n) {
    if (i < 1) {
        return;
    }

    f(i - 1, n);
    cout << i << "\n";
}

int main() {
    int n;
    cin >> n;
    f(n, n);

    return 0;
}