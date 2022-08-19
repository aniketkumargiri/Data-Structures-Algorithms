/*
Author: Aniket Kumar Giri
*/

/******************Is Vowel*****************/
bool isVowel(char ch) { 
    return (0x208222 >> (ch & 0x1f)) & 1;
}
