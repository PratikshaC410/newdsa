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

        int ans = INT_MAX;

        for (int c = 0; c < 26; c++)
        {
            int ops = 0;
            for (int i = 0; i < n; i++)
            {
                ops += abs(s[i] - ('a' + c));
            }
            ans = min(ans, ops);
        }

        cout << ans << "\n";
    }
}