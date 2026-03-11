#include <iostream>
#include <string>
#include <climits>
using namespace std;

int main()
{
    int n, d;
    cin >> n >> d;
    string s;
    cin >> s;

    vector<int> dp(n, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        if (s[i] == '0')
            continue;
        for (int j = 1; j <= d; j++)
        {
            if (i - j < 0)
                break;
            if (s[i - j] == '1' && dp[i - j] != INT_MAX)
            {
                dp[i] = min(dp[i], dp[i - j] + 1);
            }
        }
    }

    if (dp[n - 1] == INT_MAX)
        cout << -1 << endl;
    else
        cout << dp[n - 1] << endl;

    return 0;
}
