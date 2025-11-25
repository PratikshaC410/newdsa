#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
private:
    pair<int, int> countZerosOnes(const string& s) {
        int zeros = 0;
        int ones = 0;
        for (char c : s) {
            if (c == '0') {
                zeros++;
            } else {
                ones++;
            }
        }
        return {zeros, ones};
    }

public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (const string& s : strs) {
            pair<int, int> counts = countZerosOnes(s);
            int zeros = counts.first;
            int ones = counts.second;
            
            for (int j = m; j >= zeros; --j) {
                for (int k = n; k >= ones; --k) {
                    dp[j][k] = max(dp[j][k], 1 + dp[j - zeros][k - ones]);
                }
            }
        }

        return dp[m][n];
    }
};