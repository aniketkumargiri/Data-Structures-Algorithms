/*
Author: Aniket Kumar Giri
*/

/***************Is Perfect Square**************/
bool isPerfectSquare(long long int n) {
    if (ceil((long double)sqrt(n)) == floor((long double)sqrt(n))) {
        return true;
    } else {
        return false;
    }
}