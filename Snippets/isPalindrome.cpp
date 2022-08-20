/*
Author: Aniket Kumar Giri
*/

/****************Is Palindrome***************/
bool isPalindrome(string s, long long int start, long long int end) {
    while (start < end) {
        if (s[start] != s[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}