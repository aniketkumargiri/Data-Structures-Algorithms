// First Occurence --> O(log(N))
#include <bits/stdc++.h>
using namespace std;

int firstOccurence(int arr[], int n, int key)
{
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;
    int ans = -1;

    while (start <= end)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            end = mid - 1;
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

    return ans;
}

int main()
{
    int arr[] = {1, 2, 3, 3, 3, 3, 3, 3, 3, 3, 5};

    int idx = firstOccurence(arr, 11, 3);
    cout << "First Occurence of 3 is: " << idx << endl;

    return 0;
}