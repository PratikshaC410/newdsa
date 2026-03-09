class Solution
{
public:
    int countWays(string &s)
    {
        int n = s.size();

        vector<int> dp(n + 1, 0);

        dp[0] = 1;
        dp[1] = s[0] != '0' ? 1 : 0;
        for (int i = 2; i <= n; i++)
        {
            int oneDigit = s[i - 1] - '0';
            int twoDigit = stoi(s.substr(i - 2, 2));
            if (oneDigit >= 1 && oneDigit <= 9)
                dp[i] += dp[i - 1];

            if (twoDigit >= 10 && twoDigit <= 26)
                dp[i] += dp[i - 2];
        }

        return dp[n];
    }
};