/**
 * @file 02_distinct-ways-to-climb-stairs.cpp
 * @author Anikthe_27 (aniket.kumar.giri2707@gmail.com)
 * @brief Count distint ways to Climb stairs
 * @date 2022-08-17
 *
 * @copyright Copyright @ani, 2022
 *
 */

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

// Recursive --> TC = O(2^N)
int solve_rec(long long n, int i) {
    // base case
    if (i == n) {
        return 1;
    }
    if (i > n) {
        return 0;
    }
    return (solve_rec(n, i + 1) % mod + solve_rec(n, i + 2) % mod) % mod;
}

// Memoization --> TC = O(N), SC = O(N)+O(N)
int solve_mem(int n, vector<int> &dp) {
    // base case
    if (n <= 1) {
        return 1;
    }

    // step3
    if (dp[n] != -1) {
        return dp[n] % mod;
    }

    // step2
    dp[n] = (solve_mem(n - 1, dp) % mod + solve_mem(n - 2, dp) % mod) % mod;
    return dp[n] % mod;
}

// Tabulation --> TC = O(N), SC = O(N)
int solve_tab(int n) {
    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = (dp[i - 1] % mod + dp[i - 2] % mod) % mod;
    }
    return dp[n] % mod;
}

// Space Optimization --> TC = O(N), SC = O(1)
int solve_spOpt(int n) {
    int prev2 = 1;
    int prev1 = 1;

    if (n == 0) {
        return prev2;
    }
    if (n == 1) {
        return prev1;
    }

    for (int i = 2; i <= n; i++) {
        int curr = (prev2 % mod + prev1 % mod) % mod;
        prev2 = prev1 % mod;
        prev1 = curr % mod;
    }
    return prev1 % mod;
}

int countDistinctWays(int n) {
    /*
    return solve_rec(n, 0);
    */

    /*
    // step1
    vector<int> dp(n + 1, -1);
    return solve_mem(n, dp);
    */

    /*
    return solve_tab(n);
    */

    return solve_spOpt(n);
}

int main() {
    int n;
    cin >> n;

    cout << countDistinctWays(n) << endl;

    return 0;
}