// Search Element in a rotated Sorted Array
#include <bits/stdc++.h>
using namespace std;

int search(int *arr, int n, int key)
{
	int low = 0;
	int high = n - 1;

	while (low <= high)
	{
		int mid = (low + high) >> 1;
		if (arr[mid] == key)
		{
			return mid;
		}

		if (arr[low] <= arr[mid])
		{ // left part is sorted
			if (key >= arr[low] && key <= arr[mid])
			{
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
			}
		}
		else
		{ // righ part is sorted
			if (key >= arr[mid] && key <= arr[high])
			{
				low = mid + 1;
			}
			else
			{
				high = mid - 1;
			}
		}
	}

	return -1;
}

int main()
{
	int arr[] = {4, 5, 6, 7, 0, 1, 2};
	int n = sizeof(arr) / sizeof(arr[0]);

	int key;
	cin >> key;

	cout << search(arr, n, key) << endl;

	return 0;
}
