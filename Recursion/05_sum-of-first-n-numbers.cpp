// Sum of first n numbers
#include <bits/stdc++.h>
using namespace std;

void f(int i, int s) {
    if (i < 1) {
        cout << s << endl;
        return;
    }

    f(i - 1, s + i);
}

int main() {
    int n;
    cin >> n;
    f(n, 0);

    return 0;
}