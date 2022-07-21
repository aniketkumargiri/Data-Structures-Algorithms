// Count Occurence of x using STL
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a[] = {1, 4, 4, 4, 4, 9, 9, 9, 10, 11};
	int n = sizeof(a) / sizeof(a[0]);

	int first = -1;
	int last = -1;

	int x;
	cin >> x;

	int idxFirst = lower_bound(a, a + n, x) - a;
	if (idxFirst != n && a[idxFirst] == x)
	{
		first = idxFirst;
	}

	int idxLast = upper_bound(a, a + n, x) - a;
	idxLast--;
	if (idxLast >= 0 && a[idxLast] == x)
	{
		last = idxLast;
	}

	int occurences = -1;
	if (first != -1 && last != -1)
	{
		occurences = last - first + 1;
	}

	cout << "Occurences of " << x << " is: " << occurences << endl;

	return 0;
}