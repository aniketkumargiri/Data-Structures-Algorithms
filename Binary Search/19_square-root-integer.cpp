// Square root of a Number using Binary Search
#include <bits/stdc++.h>
using namespace std;

long long int squareRoot(int n)
{
    long long int start = 0;
    long long int end = n;
    long long int ans = -1;

    while (start <= end)
    {
        long long int mid = start + (end - start) / 2;
        long long int square = mid * mid;

        if (square == n)
        {
            return mid;
        }
        else if (square < n)
        {
            ans = mid;
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
    long long int n;
    cout << "Enter the number:" << endl;
    cin >> n;

    cout << squareRoot(n) << endl;

    return 0;
}