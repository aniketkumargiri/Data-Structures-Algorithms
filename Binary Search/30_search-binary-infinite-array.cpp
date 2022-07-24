// Find element in an array of infinite size
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

int findPos(int arr[], int key)
{
    int start = 0;
    int end = 1;

    while (arr[end] < key)
    {
        start = end;
        end = end * 2;
    }

    return binarySearch(arr, start, end, key);
}

int main()
{
    int arr[] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1};

    int ans = findPos(arr, 1);
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
