#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        vector<bool> used(26, false);
        used[s[0] - 'A'] = true;

        bool ok = true;
        for (int i = 1; i < n; i++)
        {
            if (s[i] != s[i - 1])
            {
                if (used[s[i] - 'A'])
                {
                    ok = false;
                    break;
                }
                used[s[i] - 'A'] = true;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}
