// k-th element of two sorted arrays
#include <bits/stdc++.h>
using namespace std;

int kthElement(int *arr1, int *arr2, int n1, int n2, int k)
{
    if (n1 > n2)
    {
        return kthElement(arr2, arr1, n2, n1, k);
    }
    int low = max(0, k - n2);
    int high = min(k, n1);

    while (low <= high)
    {
        int cut1 = (low + high) >> 1;
        int cut2 = k - cut1;

        int left1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1];
        int left2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];

        int right1 = cut1 == n1 ? INT_MAX : arr1[cut1];
        int right2 = cut2 == n2 ? INT_MAX : arr2[cut2];

        if (left1 <= right2 && left2 <= right1)
        {
            if ((n1 + n2) % 2 == 0)
            {
                return max(left1, left2);
            }
            else
            {
                return max(left1, left2);
            }
        }
        else if (left1 > right2)
        {
            high = cut1 - 1;
        }
        else // left2 > right1
        {
            low = cut1 + 1;
        }
    }

    return 1;
}

int main()
{
    int arr1[] = {1, 3, 4, 7, 10, 12};
    int arr2[] = {2, 3, 6, 15};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    int k;
    cin >> k;
    cout << kthElement(arr1, arr2, n1, n2, k) << endl;

    return 0;
}