// Single Element in Sorted Array
#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(int a[], int n)
{
	int low = 1;
	int high = n - 2;

	while (low <= high)
	{
		int mid = (low + high) >> 1;
		
		if (a[mid] == a[mid ^ 1])
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}

	return a[low];
}

int main()
{

	int arr[] = {1, 1, 2, 3, 3, 4, 4};
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << singleNonDuplicate(arr, n) << endl;

	return 0;
}