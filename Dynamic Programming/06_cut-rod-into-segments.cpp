/**
 * @file 06_cut-rod-into-segments.cpp
 * @author Anikthe_27 (aniket.kumar.giri2707@gmail.com)
 * @brief Cut Rod into Segments of X, Y, Z
 * @date 2022-08-27
 *
 * @copyright Copyright @ani, 2022
 *
 */

#include <bits/stdc++.h>
using namespace std;

// Recursive
int solve_rec(int n, int x, int y, int z) {
    // base case
    if (n == 0) {
        return 0;
    }

    if (n < 0) {
        return INT_MIN;
    }

    int a = solve_rec(n, n - x, y, z) + 1;
    int b = solve_rec(n, x, n - y, z) + 1;
    int c = solve_rec(n, x, y, n - z) + 1;

    int ans = max({a, b, c});
    return ans;
}

// Memoization
int solve_mem(int n, int x, int y, int z, vector<int> &dp) {
    // base case
    if (n == 0) {
        return 0;
    }

    if (n < 0) {
        return INT_MIN;
    }

    if (dp[n] != -1) {
        return dp[n];
    }

    int a = solve_mem(n, n - x, y, z, dp) + 1;
    int b = solve_mem(n, x, n - y, z, dp) + 1;
    int c = solve_mem(n, x, y, n - z, dp) + 1;

    dp[n] = max({a, b, c});
    return dp[n];
}

// Tabulation
// Time: O(N), Space: O(N)
int solve_tab(int n, int x, int y, int z) {
    /*
    vector<int> dp(n + 1, INT_MIN);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        if (i - x >= 0) {
            dp[i] = max(dp[i], dp[i - x]) + 1;
        }
        if (i - y >= 0) {
            dp[i] = max(dp[i], dp[i - y]) + 1;
        }
        if (i - z >= 0) {
            dp[i] = max(dp[i], dp[i - z]) + 1;
        }
    }
    */

    vector<int> dp(n + 1, -1);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        if (i - x >= 0 && dp[i - x] != -1) {
            dp[i] = max(dp[i], dp[i - x]) + 1;
        }
        if (i - y >= 0 && dp[i - y] != -1) {
            dp[i] = max(dp[i], dp[i - y]) + 1;
        }
        if (i - z >= 0 && dp[i - z] != -1) {
            dp[i] = max(dp[i], dp[i - z]) + 1;
        }
    }

    if (dp[n] < 0) {
        return 0;
    } else {
        return dp[n];
    }
}

int cutSegments(int n, int x, int y, int z) {
    /*
    int ans = solve_rec(n, x, y, z);
    if (ans < 0) {
        return 0;
    } else {
        return ans;
    }
    */

    /*
    vector<int> dp(n + 1, -1);
    int ans = solve_mem(n, x, y, z, dp);
    if (ans < 0) {
        return 0;
    } else {
        return ans;
    }
    */

    return solve_tab(n, x, y, z);
}

int main() {
    int maxWays = cutSegments(7, 5, 2, 2);
    cout << maxWays << endl;
    
    return 0;
}