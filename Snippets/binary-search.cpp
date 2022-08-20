/*
Author: Aniket Kumar Giri
*/

/*************Binary Search************/
long long int binarySearch(vector<long long int> &a, long long int low, long long int high, long long int target) {
    while (low <= high) {
        long long int mid = low + (high - low) / 2;
        if (a[mid] == target) {
            return mid;
        } else if (a[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}