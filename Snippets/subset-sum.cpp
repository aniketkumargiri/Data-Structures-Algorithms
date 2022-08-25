/*
Author: Aniket Kumar Giri
*/

/*****************Subset Sum****************/
bool isSubsetSum(vector<long long int> arr, int s) {
    long long int n = arr.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(s + 1));

    for (long long int j = 0; j < s + 1; j++) {
        dp[0][j] = false;
    }
    for (long long int i = 0; i < n + 1; i++) {
        dp[i][0] = true;
    }

    for (long long int i = 1; i < n + 1; i++) {
        for (long long int j = 1; j < s + 1; j++) {
            if (arr[i - 1] <= j) {
                dp[i][j] = (dp[i - 1][j - arr[i - 1]]) || (dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][s];
}