/*
Author: Aniket Kumar Giri
*/

/**************Binary To Decimal*************/
long long int binaryToDecimal(string s) {
    long long int n = 0;
    long long int k = 0;
    long long len = s.length();
    
    for (long long int i = len - 1; i >= 0; i--) {
        if (s[i] == '1') {
            n += pow(2, k);
        }
        k++;
    }
    return n;
}