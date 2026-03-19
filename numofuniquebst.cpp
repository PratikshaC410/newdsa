class Solution
{
public:
    int numTrees(int n)
    {
        vector<int> dp(n + 1, 0);

        dp[0] = 1;
        dp[1] = 1;

        for (int nodes = 2; nodes <= n; nodes++)
        {
            for (int root = 1; root <= nodes; root++)
            {
                int leftCount = dp[root - 1];      // nodes in left subtree
                int rightCount = dp[nodes - root]; // nodes in right subtree
                dp[nodes] += leftCount * rightCount;
            }
        }

        return dp[n];
    }
};