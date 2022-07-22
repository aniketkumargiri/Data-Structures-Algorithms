// Search Element in a rotated Sorted Array using pivot
#include <bits/stdc++.h>  
using namespace std;

int getPivot(int arr[], int n)
{
    int start = 0;
    int end = n - 1;

    while (start < end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] >= arr[0])
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

int binarySearch(int arr[], int start, int end, int key)
{
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

int findPosition(int arr[], int n, int k)
{
    int pivot = getPivot(arr, n);

    if (k >= arr[pivot] && k <= arr[n - 1]) // Binary Search on second line
    {
        return binarySearch(arr, pivot, n - 1, k);
    }
    else // Binary Search on first line
    {
        return binarySearch(arr, 0, pivot, k);
    }
}

int main()
{
    int arr[] = {4, 5, 6, 7, 0, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    int key;
    cin >> key;

    cout << findPosition(arr, n, key) << endl;

    return 0;
}