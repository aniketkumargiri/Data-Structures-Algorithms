// Upper Bound
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a[] = {1, 4, 5, 6, 9, 9};
	int n = 6;

	cout << upper_bound(a, a + n, 4) - a << endl;
	cout << upper_bound(a, a + n, 7) - a << endl;
	cout << upper_bound(a, a + n, 9) - a << endl;
	cout << upper_bound(a, a + n, 10) - a << endl;

	return 0;
}