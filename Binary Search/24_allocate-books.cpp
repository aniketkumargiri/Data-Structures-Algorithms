// Maximum number of pages allocated is minimum
#include <bits/stdc++.h>
using namespace std;

bool isPossible(int *arr, int n, int m, int mid)
{
    int stuCnt = 1;
    int noOfpages = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > mid)
        {
            return false;
        }
        if (noOfpages + arr[i] > mid)
        {
            stuCnt++;
            noOfpages += arr[i];
        }
        else
        {
            noOfpages += arr[i];
        }
    }

    if (stuCnt > m)
    {
        return false;
    }
    return true;
}

int minimumPages(int *arr, int n, int m)
{
    int low = *min_element(arr, arr + n);
    int high = accumulate(arr, arr + n, 0);

    int ans = -1;
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        if (isPossible(arr, n, m, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}

int main()
{
    int arr[] = {10, 20, 30, 40};
    int n = sizeof(arr) / sizeof(arr[0]);

    int m; // 2
    cin >> m;
    cout << minimumPages(arr, n, m) << endl;

    return 0;
}

/*
1. Each student gets a least one book
2. Each book should be allocated to a student
3. Book allocation should be in a contiguous manner
// You have to allocate the book to 'm' students such that the maximum number of pages assigned to a stdent is minimum.
*/