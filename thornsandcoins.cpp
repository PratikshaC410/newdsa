#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        vector<int> dp(n, -1);

        dp[0] = (s[0] == '@') ? 1 : 0;

        for (int i = 1; i < n; i++)
        {
            if (s[i] == '*')
                continue;

            int coin = (s[i] == '@') ? 1 : 0;

            // can come from i-1
            if (i - 1 >= 0 && dp[i - 1] != -1)
                dp[i] = max(dp[i], dp[i - 1] + coin);

            // can come from i-2
            if (i - 2 >= 0 && dp[i - 2] != -1)
                dp[i] = max(dp[i], dp[i - 2] + coin);
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
            if (dp[i] != -1)
                ans = max(ans, dp[i]);

        cout << ans << "\n";
    }

    return 0;
}