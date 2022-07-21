// Find Minimum Element In an Array
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

int main()
{
    int arr[5] = {8, 10, 17, 1, 3};

    int pivot = getPivot(arr, 5);
    cout << "Minimum element in the array is: " << arr[pivot] << endl;

    return 0;
}