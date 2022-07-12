// binary search --> Only for Sorted Array --> O(log(N))
#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int n, int key)
{
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (arr[mid] == key)
        {
            return mid;
        }

        // go to right part
        else if (arr[mid] < key)
        {
            start = mid + 1;
        }
        else // (arr[mid] > key)
        {
            end = mid - 1;
        }

        mid = start + (end - start) / 2;
    }

    return -1;
}

int main()
{
    // Only in case of monotonic functions
    int even[] = {2, 4, 6, 8, 12, 18};
    int odd[] = {3, 8, 11, 14, 16};

    int evenIdx = binarySearch(even, 6, 6);
    cout << "Index of 6 is: " << evenIdx << endl;

    int oddIdx = binarySearch(odd, 5, 14);
    cout << "Index of key 14 is: " << oddIdx << endl;

    return 0;
}