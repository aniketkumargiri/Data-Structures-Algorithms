// Last Occurence of x using STL
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[] = {1, 4, 4, 4, 4, 9, 9, 10, 11};
    int n = sizeof(a) / sizeof(a[0]);

    int x;
    cin >> x; // 4, 9, 2, 0
    int idx = upper_bound(a, a + n, x) - a;
    idx--;

    if (idx >= 0 && a[idx] == x)
    {
        cout << idx << endl;
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}