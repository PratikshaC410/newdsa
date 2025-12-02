class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> height(n, 0);
        long long result = 0;

        for (int i = 0; i < m; i++) {
            // Build histogram height
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) height[j] = 0;
                else height[j]++;
            }

            // Count submatrices ending at row i
            result += countHistogram(height);
        }

        return (int)result;
    }

    long long countHistogram(vector<int>& h) {
        int n = h.size();
        long long total = 0;
        stack<int> st;
        vector<long long> dp(n, 0);

        for (int i = 0; i < n; i++) {
            while (!st.empty() && h[st.top()] >= h[i])
                st.pop();

            if (!st.empty()) {
                int prev = st.top();
                dp[i] = dp[prev] + (long long)h[i] * (i - prev);
            } else {
                dp[i] = (long long)h[i] * (i + 1);
            }

            st.push(i);
            total += dp[i];
        }

        return total;
    }
};
