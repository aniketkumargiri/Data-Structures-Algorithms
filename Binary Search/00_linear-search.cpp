// Linear search --> O(N)
#include <bits/stdc++.h>
using namespace std;

int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    int arr[] = {5, 2, 7, -2, 0, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    int key;
    cin >> key;

    int idx = linearSearch(arr, n, key);
    cout << "Index of key " << key << " is: " << idx << endl;

    return 0;
}