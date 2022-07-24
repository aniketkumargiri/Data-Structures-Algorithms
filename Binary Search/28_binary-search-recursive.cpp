// Binary search Recursive
#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int start, int end, int target)
{
    if (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        if (arr[mid] > target)
        {
            return binarySearch(arr, start, mid - 1, target);
        }
        return binarySearch(arr, mid + 1, end, target);
    }
    return -1;
}

int main()
{
    int arr[] = {3, 5, 7, 9, 10, 90, 100, 130, 140, 160, 170};

    int ans = binarySearch(arr, 0, 11, 7);
    if (ans == -1)
    {
        cout << "Element not found\n";
    }
    else
    {
        cout << "Element found at index " << ans << endl;
    }

    return 0;
}
