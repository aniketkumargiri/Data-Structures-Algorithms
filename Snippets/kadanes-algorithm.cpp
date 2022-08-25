/*
Author: Aniket Kumar Giri
*/

/*************Kadane's Algorithm************/
long long int maximumSubArraySum(vector<long long int> &a, long long int size) {
    long long int max_so_far = INT_MIN;
    long long int max_ending_here = 0;

    for (long long int i = 0; i < size; i++) {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
        }

        if (max_ending_here < 0) {
            max_ending_here = 0;
        }
    }
    return max_so_far;
}