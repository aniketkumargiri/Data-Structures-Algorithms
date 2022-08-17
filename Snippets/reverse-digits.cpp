/*
Author: Aniket Kumar Giri
*/

/***************Reverse the digits**************/
long long int reverse(long long int n) {
    long long int rev = 0;
    while (n != 0) {
        long long int rem = n % 10;
        rev = rev * 10 + rem;
        n /= 10;
    }
    return rev;
}