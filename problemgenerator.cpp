#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        string a;
        cin >> a;

        vector<int> cnt(7, 0);

        for (char c : a)
        {
            cnt[c - 'A']++;
        }

        int needed = 0;
        for (int i = 0; i < 7; ++i)
        {
            if (cnt[i] < m)
                needed += (m - cnt[i]);
        }

        cout << needed << '\n';
    }

    return 0;
}
