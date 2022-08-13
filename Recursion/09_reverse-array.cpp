// Reverse an array
#include <bits/stdc++.h>
using namespace std;

void f(int a[], int i, int n) {
    if (i >= n / 2) {
        return;
    }

    swap(a[i], a[n - i - 1]);
    f(a, i + 1, n);
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
    f(a, 0, n);
    printArray(a, n);

    return 0;
}