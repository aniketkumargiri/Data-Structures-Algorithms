/*
Author: Aniket Kumar Giri
*/

vector<long long int> suffix(n);
suffix[n - 1] = a[n - 1];
for (long long int i = n - 2; i >= 0; i--) {
    suffix[i] = suffix[i + 1] + a[i];
}