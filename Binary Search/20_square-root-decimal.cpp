// Square root of a Number in Decimal Precision using Binary Search
#include <bits/stdc++.h>
using namespace std;

long long int squareRootInteger(int n)
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

double morePrecision(long long int n, int precision, int tempSolution)
{
    double factor = 1;
    double ans = tempSolution;

    for (int i = 0; i < precision; i++)
    {
        factor = factor / 10;
        for (double j = ans; j * j < n; j = j + factor)
        {
            ans = j;
        }
    }

    return ans;
}

int main()
{
    long long int n;
    cout << "Enter the number:" << endl;
    cin >> n;

    int tempSolution = squareRootInteger(n);
    cout << "Answer is: " << morePrecision(n, 3, tempSolution) << endl;

    return 0;
}