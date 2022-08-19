/*
Author: Aniket Kumar Giri
*/

/**************Decimal To Binary*************/
string decimalToBinary(long long int n) {
    string s = "";
    while (n) {
        s = to_string(n % 2) + s;
        n >>= 1;
    }
    return s;
}