/*
Author: Aniket Kumar Giri
*/

/****************Sum of Digits***************/
long long int sumOfDigits(long long int n) {
    long long int sum = 0;
    while (n != 0) {
        sum = sum + n % 10;
        n = n / 10;
    }
    return sum;
}