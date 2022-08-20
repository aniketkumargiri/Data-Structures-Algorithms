/*
Author: Aniket Kumar Giri
*/

/**********Power of K Nearest to N*********/
long long int nearestPowerOfKtoN(long long int n, long long int k) {
    long long int lg = log(n) / log(k);
    long long int a = pow(k, lg);
    long long int b = pow(k, lg + 1);

    if ((n - a) < (b - n)) {
        return a;
    }
    return b;
}