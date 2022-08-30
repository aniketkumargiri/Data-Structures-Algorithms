// Tower of Hanoi
#include <bits/stdc++.h>
using namespace std;

void f(int n, char src, char aux, char dest) {
    if (n == 0) {
        return;
    }

    f(n - 1, src, dest, aux);
    cout << "Move disk " << n << " from rod " << src << " to rod " << dest << endl;
    f(n - 1, aux, src, dest);
}

int main() {
    int n;
    cin >> n;

    f(n, 'a', 'b', 'c');
    return 0;
}