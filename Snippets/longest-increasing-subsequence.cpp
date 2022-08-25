/*
Author: Aniket Kumar Giri
*/

/**********Longest Increasing Subsequence*********/
long long int longestIncreasingSubsequence(vector<long long int>& nums) {
    long long int n = nums.size();
    vector<long long int> ans;
    ans.push_back(nums[0]);

    for (long long int i = 1; i < n; i++) {
        if (ans.back() < nums[i])
            ans.push_back(nums[i]);
        else {
            long long int idx = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
            ans[idx] = nums[i];
        }
    }
    return ans.size();
}