/**
 * @file 05_house-robbery-II.cpp
 * @author Anikthe_27 (aniket.kumar.giri2707@gmail.com)
 * @brief Maximum money in house robbery with circular, non-adjacent constraint
 * @date 2022-08-18
 *
 * @copyright Copyright @ani, 2022
 *
 */

#include <bits/stdc++.h>
using namespace std;

// Space Optimization --> TC = O(N), SC = O(1)
long long int solve_spOpt(vector<long long int>& nums) {
    long long int prev2 = 0;
    long long int prev1 = nums[0];

    for (long long int i = 1; i < nums.size(); i++) {
        long long int incl = nums[i] + prev2;
        long long int excl = 0 + prev1;

        long long int ans = max(incl, excl);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}

long long int houseRobber(vector<int>& nums) {
    long long int n = nums.size();
    if (n == 1) {
        return nums[0];
    }

    vector<long long int> first, second;
    for (long long int i = 0; i < n; i++) {
        if (i != n - 1) {
            first.push_back(nums[i]);
        }
        if (i != 0) {
            second.push_back(nums[i]);
        }
    }
    return max(solve_spOpt(first), solve_spOpt(second));
}

int main() {
    vector<int> nums = {1, 3, 2, 7};
    cout << houseRobber(nums) << endl;
    return 0;
}