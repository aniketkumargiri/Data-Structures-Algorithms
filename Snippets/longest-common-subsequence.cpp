/*
Author: Aniket Kumar Giri
*/

/**********Longest Common Subsequence*********/
int longestCommonSubsequence(string s1, string s2, long long int m, long long int n) {
    long long int dp[m + 1][n + 1];
    for (long long int i = 0; i < m + 1; i++) {
        for (long long int j = 0; j < n + 1; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}