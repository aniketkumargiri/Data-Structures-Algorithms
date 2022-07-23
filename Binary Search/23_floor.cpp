// Floor in a Sorted Array
#include <bits/stdc++.h>
using namespace std;

int floorSearch(vector<int> &arr, int X, int N)
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
        else if (arr[mid] < X)
        {
            ans = arr[mid];
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 8, 10, 10, 12, 19};
    int key;
    cin >> key;

    int floor = floorSearch(arr, key, arr.size());
    cout << "Floor of " << key << " is: " << floor << endl;

    return 0;
}