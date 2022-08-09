// print n to 1
#include <bits/stdc++.h>
using namespace std;

void f(int i, int n) {
    if (i > n) {
        return;
    }

    f(i + 1, n);
    cout << i << "\n";
}

int main() {
    int n;
    cin >> n;
    f(1, n);

    return 0;
}