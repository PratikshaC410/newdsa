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
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            // a[i] the max red element
            // dp[j][0] = max reds in a[0..j] where j is NOT red
            // dp[j][1] = max reds in a[0..j] where j IS red

            vector<array<int, 2>> dp(n, {0, -1});

            dp[0][0] = 0;
            // can pick
            if (i != 0 && i != 1 && a[0] <= a[i])
                dp[0][1] = 1;

            for (int j = 1; j < n; j++)
            {
                // Don't pick j
                dp[j][0] = max(dp[j - 1][0], dp[j - 1][1]);

                bool blocked = (j == i || j == i - 1 || j == i + 1 || a[j] > a[i]);
                if (!blocked)
                {
                    if (dp[j - 1][0] != -1)
                        dp[j][1] = dp[j - 1][0] + 1;
                }
            }

            int free_reds = max(dp[n - 1][0], dp[n - 1][1]);

            ans = max(ans, a[i] + 1 + free_reds);
        }

        cout << ans << "\n";
    }

    return 0;
}