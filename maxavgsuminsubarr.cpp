#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Sum of first k elements
        long long windowSum = 0;
        for (int i = 0; i < k; i++) {
            windowSum += nums[i];
        }

        long long maxSum = windowSum;

        // Slide the window
        for (int i = k; i < n; i++) {
            windowSum += nums[i] - nums[i - k]; // add new, remove old
            maxSum = max(maxSum, windowSum);
        }

        return (double)maxSum / k;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,12,-5,-6,50,3};
    int k = 4;

    cout << fixed << setprecision(5) << sol.findMaxAverage(nums, k) << endl;
    return 0;
}
