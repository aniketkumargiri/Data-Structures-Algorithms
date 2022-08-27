/**
 * @file 04_max-sum-non-adjacents.cpp
 * @author Anikthe_27 (aniket.kumar.giri2707@gmail.com)
 * @brief Maximum Sum of Non-Adjacents Elements
 * @date 2022-08-27
 *
 * @copyright Copyright @ani, 2022
 *
 */

#include <bits/stdc++.h>
using namespace std;

// Recursion
int solve_rec(vector<int> &nums, int n) {
    // base case
    if (n < 0) {
        return 0;
    }
    if (n == 0) {
        return nums[0];
    }

    int incl = nums[n] + solve_rec(nums, n - 2);
    int excl = 0 + solve_rec(nums, n - 1);
    return max(incl, excl);
}

// Memoization --> TC = O(N), SC = O(N)+O(N)
int solve_mem(vector<int> &nums, int n, vector<int> &dp) {
    // base case
    if (n < 0) {
        return 0;
    }
    if (n == 0) {
        return nums[0];
    }

    if (dp[n] != -1) {
        return dp[n];
    }

    int incl = nums[n] + solve_mem(nums, n - 2, dp);
    int excl = 0 + solve_mem(nums, n - 1, dp);
    dp[n] = max(incl, excl);
    return dp[n];
}

// Tabulation --> TC = O(N), SC = O(N)
int solve_tab(vector<int> &nums) {
    int n = nums.size();
    vector<int> dp(n, 0);

    dp[0] = nums[0];
    for (int i = 1; i < n; i++) {
        int incl = nums[i] + dp[i - 2];
        int excl = 0 + dp[i - 1];
        dp[i] = max(incl, excl);
    }
    return dp[n - 1];
}

// Space Optimization --> TC = O(N), SC = O(1)
int solve_spOpt(vector<int> &nums) {
    int prev2 = 0;
    int prev1 = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        int incl = nums[i] + prev2;
        int excl = 0 + prev1;

        int ans = max(incl, excl);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}

int maximumNonAdjacentSum(vector<int> &nums) {
    int n = nums.size();
    /*
    return solve_rec(nums, n - 1);
    */

    vector<int> dp(n, -1);
    return solve_mem(nums, n - 1, dp);
}

int main() {
    vector<int> nums = {9, 9, 8, 2};
    cout << maximumNonAdjacentSum(nums) << endl;
    return 0;
}