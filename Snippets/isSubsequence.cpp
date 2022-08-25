/*
Author: Aniket Kumar Giri
*/

/****************Is Subsequence***************/
bool isSubSequence(string s1, string s2, long long int m, long long int n) {
    long long int j = 0;
    for (long long int i = 0; i < n && j < m; i++) {
        if (s1[j] == s2[i]) {
            j++;
        }
    }
    return (j == m);
}