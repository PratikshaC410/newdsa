class Solution {
  public:
    int perfectSum(vector<int> &arr, int target) {
        int n = arr.size();
        const int MOD = 1e9 + 7;

        // dp[i][j] = number of subsets from first i elements with sum j
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

        // Base case: there's one subset (empty set) with sum = 0
        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;

        // Fill the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= target; j++) {
                if (arr[i - 1] <= j) {
                    // Include or exclude the current element
                    dp[i][j] = (dp[i - 1][j - arr[i - 1]] + dp[i - 1][j]) % MOD;
                } else {
                    // Cannot include current element
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][target];
    }
};
