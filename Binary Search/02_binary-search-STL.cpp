// Binary Search C++ STL
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a[] = {1, 4, 5, 8, 9};
	int n = 5;

	cout << binary_search(a, a + n, 4) << endl;
	cout << binary_search(a, a + n, 3) << endl;

	return 0;
}