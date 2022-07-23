// Nth Root of a Number using Binary Search
#include <bits/stdc++.h>
using namespace std;

double multiply(double num, double n)
{
	double ans = 1.0;
	for (int i = 1; i <= n; i++)
	{
		ans *= num;
	}
	return ans;
}

void getNthRoot(int n, int m)
{
	double low = 1;
	double high = m;
	double eps = 1e-6;

	while ((high - low) > eps)
	{
		double mid = (low + high) / 2.0;
		if (multiply(mid, n) < m)
		{
			low = mid;
		}
		else
		{
			high = mid;
		}
	}

	cout << low << " " << high << endl;
}

int main()
{
	int n, m;
	cin >> n >> m;
	getNthRoot(n, m);

	// check using STL: pow funtion
	cout << pow(m, (double)(1.0 / (double)n));

	return 0;
}