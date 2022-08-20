/*
Author: Aniket Kumar Giri
*/

/*************Sieve of Eratosthenes************/
vector<long long int> sieveOfEratosthenes(long long int m, long long int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;

    for (long long int i = 2; i * i < n + 1; i++) {
        if (isPrime[i] == true && (long long int)i * i <= n) {
            for (long long int j = i * i; j < n + 1; j += i) {
                isPrime[j] = false;
            }
        }
    }

    vector<long long int> primes;
    for (long long int i = m; i < n + 1; i++) {
        if (isPrime[i] == true) {
            primes.push_back(i);
        }
    }
    return primes;
}