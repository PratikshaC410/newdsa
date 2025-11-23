class Solution {
public:
   int maxSumDivThree(vector<int>& nums) {
    vector<int> dp(3, 0);

    for (int x : nums) {
        vector<int> temp(dp);
        for (int r : dp) {
            int newSum = r + x;
            temp[newSum % 3] = max(temp[newSum % 3], newSum);
        }
        dp = temp;
    }

    return dp[0];
}
};