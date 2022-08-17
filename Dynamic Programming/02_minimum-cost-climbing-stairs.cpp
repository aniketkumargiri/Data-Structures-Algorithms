/**
 * @file 02_minimum-cost-climbing-stairs.cpp
 * @author Anikthe_27 (aniket.kumar.giri2707@gmail.com)
 * @brief Minimum Cost climbing stairs
 * @date 2022-08-17
 *
 * @copyright Copyright @ani, 2022
 *
 */

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

// Recursive --> TC = O(2^N)
int solve_rec(vector<int> &cost, int n) {
    // base case
    if (n == 0) {
        return cost[0];
    }
    if (n == 1) {
        return cost[1];
    }
    return cost[n] + min(solve_rec(cost, n - 1), solve_rec(cost, n - 2));
}

// Memoization --> TC = O(N), SC = O(N)+O(N)
int solve_mem(vector<int> &cost, int n, vector<int> &dp) {
    // base case
    if (n == 0) {
        return cost[0];
    }
    if (n == 1) {
        return cost[1];
    }

    // step3
    if (dp[n] != -1) {
        return dp[n];
    }

    // step2
    dp[n] =
        cost[n] + min(solve_mem(cost, n - 1, dp), solve_mem(cost, n - 2, dp));
    return dp[n];
}

// Tabulation --> TC = O(N), SC = O(N)
int solve_tab(vector<int> &cost, int n) {
    // step1: creation of dp array
    vector<int> dp(n + 1);

    // step2: base case analyse
    dp[0] = cost[0];
    dp[1] = cost[1];

    // 3rd step
    for (int i = 2; i <= n; i++) {
        dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
    }
    return min(dp[n - 1], dp[n - 2]);
}

// Space Optimization --> TC = O(N), SC = O(1)
int solve_spOpt(vector<int> &cost, int n) {
    int prev2 = cost[0];
    int prev1 = cost[1];

    if (n == 0) {
        return prev2;
    }
    if (n == 1) {
        return prev1;
    }

    for (int i = 2; i < n; i++) {
        int curr = cost[i] + min(prev2, prev1);
        prev2 = prev1;
        prev1 = curr;
    }
    return min(prev2, prev1);
}

int minCostClimbingStairs(vector<int> &cost) {
    int n = cost.size();
    /*
    return min(solve_rec(cost, n - 1), solve_rec(cost, n - 2));
    */

    /*
    // step1
    vector<int> dp(n + 1, -1);
    return min(solve_mem(cost, n - 1, dp), solve_mem(cost, n - 2, dp));
    */

    /*
    return solve_tab(cost, n);
    */

    return solve_spOpt(cost, n);
}

int main() {
    vector<int> cost = {10, 15, 20};
    cout << minCostClimbingStairs(cost) << endl;

    return 0;
}