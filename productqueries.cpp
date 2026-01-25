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

        vector<int> dp(n + 1, INT_MAX / 2);
        for (int val : a)
        {
            for (int j = n; j >= val; j--)
            {
                if (dp[j / val] != INT_MAX / 2)
                {
                    dp[j] = min(dp[j], dp[j / val] + 1);
                }
                if (j == val)
                {
                    dp[j] = min(dp[j], 1);
                }
            }
        }

        for (int i = 1; i <= n; i++)
        {
            int ans = (dp[i] == INT_MAX / 2 ? -1 : dp[i]);
            cout << ans << (i == n ? "\n" : " ");
        }
    }
    return 0;
}
