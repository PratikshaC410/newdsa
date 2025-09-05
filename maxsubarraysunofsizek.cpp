vclass Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
          int n = arr.size();
    if (k > n) return -1; // invalid case

    int left = 0, right = 0;
    int windowSum = 0;
    int maxSum = INT_MIN;

    while (right < n) {
        windowSum += arr[right]; // add the right element

        // When window size reaches k
        if (right - left + 1 == k) {
            maxSum = max(maxSum, windowSum);

            windowSum -= arr[left]; // remove the left element
            left++;                 // slide the window
        }

        right++; // expand window
    }

    return maxSum;
        
    }
};