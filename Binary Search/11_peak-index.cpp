// Peak Index in a Mountain Array
#include <bits/stdc++.h>
using namespace std;

int peakIndexInMountainArray(vector<int> &arr)
{
	int start = 0;
	int end = arr.size() - 1;

	while (start < end)
	{
		int mid = start + (end - start) / 2;

		if (arr[mid] < arr[mid + 1])
		{
			start = mid + 1;
		}
		else
		{
			end = mid;
		}
	}

	return start;
}

int main()
{
	// peak: arr[i - 1] < arr[i] > arr[i + 1]
	vector<int> arr = {3, 4, 5, 1};

	int peak = peakIndexInMountainArray(arr);
	cout << "Peak Index in a Mountain Array is: " << peak << endl;

	return 0;
}