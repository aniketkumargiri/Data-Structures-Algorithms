// Largest number smaller than x
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[] = {1, 4, 4, 4, 4, 9, 9, 10, 11};
    int n = sizeof(a) / sizeof(a[0]);

    int x;
    cin >> x; // 4, 2, 1, 9
    int idx = lower_bound(a, a + n, x) - a;
    idx--;

    if (idx >= 0)
    {
        cout << a[idx] << endl;
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}