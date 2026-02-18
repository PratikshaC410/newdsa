class Solution
{
public:
    int numberOfWays(int n)
    {

        const int MOD = 1e9 + 7;
        vector<long long> dp(n + 1, 0);

        dp[0] = 1;

        vector<int> coins = {1, 2, 6};

        for (int coin : coins)
        {
            for (int i = coin; i <= n; i++)
            {
                dp[i] = (dp[i] + dp[i - coin]) % MOD;
            }
        }
        vector<long long> ans = dp;

        for (int i = 4; i <= n; i++)
            ans[i] = (ans[i] + dp[i - 4]) % MOD;

        for (int i = 8; i <= n; i++)
            ans[i] = (ans[i] + dp[i - 8]) % MOD;

        return ans[n];
    }
};
