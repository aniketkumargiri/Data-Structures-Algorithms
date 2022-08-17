/*
Author: Aniket Kumar Giri
*/

vector<long long int> prefix(n);
prefix[0] = a[0];
for (long long int i = 1; i < n; i++) {
    prefix[i] = prefix[i - 1] + a[i];
}