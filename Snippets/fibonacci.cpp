/*
Author: Aniket Kumar Giri
*/

/*****************Fibonacci****************/
long long int fib(long long int n) {
    long long int prev2 = 0;
    long long int prev1 = 1;

    if (n == 0) {
        return prev2;
    }
    if (n == 1) {
        return prev1;
    }

    for (long long int i = 1; i < n; i++) {
        long long int curr = prev2 + prev1;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}