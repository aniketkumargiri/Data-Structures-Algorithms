// Median of two sorted arrays
#include <bits/stdc++.h>
using namespace std;

double median(int *arr1, int *arr2, int n1, int n2)
{
    if (n1 > n2)
    {
        return median(arr2, arr1, n2, n1);
    }

    int low = 0;
    int high = n2;

    while (low <= high)
    {
        int cut1 = (low + high) >> 1;
        int cut2 = (n1 + n2 + 1) / 2 - cut1;

        int left1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1];
        int left2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];

        int right1 = cut1 == n1 ? INT_MAX : arr1[cut1];
        int right2 = cut2 == n2 ? INT_MAX : arr2[cut2];

        if (left1 <= right2 && left2 <= right1)
        {
            if ((n1 + n2) % 2 == 0)
            {
                return (max(left1, left2) + min(right1, right2)) / 2.0;
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
        else
        {
            low = cut1 + 1;
        }
    }

    return 0.0;
}

int main()
{
    int arr1[] = {1, 3, 4, 7, 10, 12};
    int arr2[] = {2, 3, 6, 15};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    cout << median(arr1, arr2, n1, n2) << endl;

    return 0;
}