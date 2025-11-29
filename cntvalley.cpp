class Solution {
public:
    int countHillValley(vector<int>& nums) {
          vector<int> arr;
        arr.reserve(nums.size());

        // Remove consecutive duplicates
        for (int x : nums) {
            if (arr.empty() || arr.back() != x) {
                arr.push_back(x);
            }
        }

        int count = 0;
        int n = arr.size();

        // Count hills and valleys
        for (int i = 1; i < n - 1; i++) {
            if ((arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) ||
                (arr[i] < arr[i - 1] && arr[i] < arr[i + 1])) {
                count++;
            }
        }

        return count; 
    }
};