// print n to 1
#include <bits/stdc++.h>
using namespace std;

void f(int i, int n) {
    if (i < 1) {
        return;
    }

    cout << i << "\n";
    f(i - 1, n);
}

int main() {
    int n;
    cin >> n;
    f(n, n);

    return 0;
}