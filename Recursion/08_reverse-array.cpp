// Reverse an array
#include <bits/stdc++.h>
using namespace std;

void f(int a[], int l, int r) {
    if (l >= r) {
        return;
    }

    swap(a[l], a[r]);
    f(a, l + 1, r - 1);
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    printArray(a, n);
    f(a, 0, n - 1);
    printArray(a, n);

    return 0;
}