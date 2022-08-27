/**
 * @file 03_minimum-no-of-coins.cpp
 * @author Anikthe_27 (aniket.kumar.giri2707@gmail.com)
 * @brief Minimum Number of Coins to make a target amount
 * @date 2022-08-27
 *
 * @copyright Copyright @ani, 2022
 *
 */

#include <bits/stdc++.h>
using namespace std;

// Recursion
int solve_rec(vector<int> &coins, int x) {
    // base case
    if (x == 0) {
        return 0;
    }
    if (x < 0) {
        return INT_MAX;
    }

    int mn = INT_MAX;
    for (int i = 0; i < coins.size(); i++) {
        int ans = solve_rec(coins, x - coins[i]);
        if (ans != INT_MAX) {
            mn = min(mn, 1 + ans);
        }
    }
    return mn;
}

// Memoization --> TC = O(N*N), SC = O(N)+O(N)
int solve_mem(vector<int> &coins, int x, vector<int> &dp) {
    // base case
    if (x == 0) {
        return 0;
    }
    if (x < 0) {
        return INT_MAX;
    }

    if (dp[x] != -1) {
        return dp[x];
    }

    int mn = INT_MAX;
    for (int i = 0; i < coins.size(); i++) {
        int ans = solve_mem(coins, x - coins[i], dp);
        if (ans != INT_MAX) {
            mn = min(mn, 1 + ans);
        }
    }
    dp[x] = mn;
    return dp[x];
}

// Tabulation --> TC = O(N*N), SC = O(N)
int solve_tab(vector<int> &coins, int x) {
    vector<int> dp(x + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= x; i++) {
        // I am trying to solve for every amount figure from 1 to x
        for (int j = 0; j < coins.size(); j++) {
            if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX) {
                dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
            }
        }
    }

    if (dp[x] == INT_MAX) {
        return -1;
    }
    return dp[x];
}

int minNoOfcoins(vector<int> &coins, int amount) {
    /*
    int ans = solve_rec(coins, amount);
    if (ans == INT_MAX) {
        return -1;
    }
    return ans;
    */

    /*
    vector<int> dp(amount + 1, -1);
    int ans = solve_mem(coins, amount, dp);
    if (ans == INT_MAX) {
        return -1;
    } else {
        return ans;
    }
    */

    return solve_tab(coins, amount);
}

int main() {
    vector<int> coins = {1, 2, 3};
    int target = 7;
    cout << minNoOfcoins(coins, target) << endl;
    return 0;
}