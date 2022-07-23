// Ceiling in a Sorted Array
#include <bits/stdc++.h>
using namespace std;

int ceilingInSortedArray(int N, int X, vector<int> &arr)
{
    int start = 0;
    int end = N - 1;
    int ans = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == X)
        {
            return arr[mid];
        }
        else if (arr[mid] > X)
        {
            ans = arr[mid];
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 8, 10, 10, 12, 19};
    int key;
    cin >> key;

    int ceil = ceilingInSortedArray(arr.size(), key, arr);
    cout << "ceiling of " << key << " is " << ceil << endl;
    
    return 0;
}