class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<vector<int>> dp(k, vector<int>(k, 0));
        int ans = 1;

        for (int x : nums) {
            int r = x % k;
            for (int C = 0; C < k; C++) {
                int prev_r = (C - r + k) % k;
                dp[C][r] = max(dp[C][r], dp[C][prev_r] + 1);
                ans = max(ans, dp[C][r]);
            }
        }

        return ans;
    }
};