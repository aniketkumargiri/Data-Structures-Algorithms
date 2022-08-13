// Check if string is palindrome or not
#include <bits/stdc++.h>
using namespace std;

bool f(string s, int i, int n) {
    if (i >= n / 2) {
        return true;
    }

    if (s[i] != s[n - i - 1]) {
        return false;
    }
    f(s, i + 1, n);
}

int main() {
    string s;
    cin >> s;

    bool isTrue = f(s, 0, s.length());
    if (isTrue) {
        cout << "Given string is a palindrome\n";
    } else {
        cout << "Given string is not a palindrome\n";
    }

    return 0;
}