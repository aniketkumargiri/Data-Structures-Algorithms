// Aggressive Cows: Largest Minimum Distance
#include <bits/stdc++.h>
using namespace std;

bool isPossible(int *arr, int n, int k, int mid)
{
    int co_ord = arr[0];
    int cowCnt = 1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] - co_ord >= mid)
        {
            cowCnt++;
            co_ord = arr[i];
        }

        if (cowCnt == k)
        {
            return true;
        }
    }

    return false;
}

int largestMinimum(int *arr, int n, int k)
{
    int low = 0;
    int high = arr[n - 1] - arr[0]; // maximum difference in the sorted array

    int res = -1;
    while (low <= high)
    {
        int mid = (low + high) >> 1;

        if (isPossible(arr, n, k, mid))
        {
            res = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return res;
}

int main()
{
    int arr[] = {1, 2, 4, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    int k; // 3
    cin >> k;
    cout << largestMinimum(arr, n, k) << endl;

    return 0;
}