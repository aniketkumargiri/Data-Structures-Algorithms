/*
Author: Aniket Kumar Giri
*/

/*******************Prime Divisors******************/
vector<long long int> primeFactors(long long int n) {
    vector<long long int> ans;
    long long int i = 2;

    while (n > 1) {
        if (n % i == 0) {
            ans.push_back(i);
            n /= i;
        } else {
            i++;
        }
    }
    return ans;
}