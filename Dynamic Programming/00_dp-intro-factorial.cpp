/**
 * @file 01_dp-intro-factorial.cpp
 * @author Anikthe_27 (aniket.kumar.giri2707@gmail.com)
 * @brief Nth Fibonacci Number
 * @date 2022-08-17
 *
 * @copyright Copyright @ani, 2022
 *
 */

#include <bits/stdc++.h>
using namespace std;

// Recursive --> TC = O(2^N)
int solve_rec(int n) {
    // base case
    if (n == 0 || n == 1) {
        return n;
    }

    return solve_rec(n - 1) + solve_rec(n - 2);
}

// Memoization --> TC = O(N), SC = O(N)+O(N)
int solve_mem(int n, vector<int> &dp) {
    // base case
    if (n <= 1) {
        return n;
    }

    // step3
    if (dp[n] != -1) {
        return dp[n];
    }

    // step2
    dp[n] = solve_mem(n - 1, dp) + solve_mem(n - 2, dp);
    return dp[n];
}

// Tabulation --> TC = O(N), SC = O(N)
int solve_tab(int n) {
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// Space Optimization --> TC = O(N), SC = O(1)
int solve_spOpt(int n) {
    int prev2 = 0;
    int prev1 = 1;

    if (n == 0) {
        return prev2;
    }
    if (n == 1) {
        return prev1;
    }

    for (int i = 1; i < n; i++) {
        int curr = prev2 + prev1;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main() {
    int n;
    cin >> n;

    /*
    cout << solve_rec(n) << endl;
    */

    /*
    // step1
    vector<int> dp(n + 1, -1);
    cout << solve_mem(n, dp);
    */

    /*
    cout << solve_tab(n) << endl;
    */

    cout << solve_spOpt(n) << endl;

    return 0;
}