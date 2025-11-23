class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        unordered_map<long long, unordered_map<int, int>> mp; 
         int n = nums.size();

    int prefixXor = 0;
    int diff = 0;  // even - odd
    int result = 0;

    // Initial state before starting (xor=0, diff=0)
    mp[0][0] = -1;

    for (int i = 0; i < n; i++) {
        prefixXor ^= nums[i];
        diff += (nums[i] % 2 == 0 ? 1 : -1);

        // If this (xor, diff) pair was seen before
        if (mp[prefixXor].count(diff)) {
            result = max(result, i - mp[prefixXor][diff]);
        } else {
            mp[prefixXor][diff] = i; // store first occurrence
        }
    }

    return result;
    }
};