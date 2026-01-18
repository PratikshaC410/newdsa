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
        int n, m, k;
        cin >> n >> m >> k;

        vector<long long> a(n), b(m);
        for (auto &x : a)
            cin >> x;
        for (auto &x : b)
            cin >> x;

        string s;
        cin >> s;

        vector<long long> pref(k + 1, 0);
        for (int i = 1; i <= k; i++)
        {
            pref[i] = pref[i - 1] + (s[i - 1] == 'R' ? 1 : -1);
        }

        unordered_map<long long, int> robot_id;
        for (int i = 0; i < n; i++)
        {
            robot_id[a[i]] = i;
        }

        const int INF = 1e9;
        vector<int> death(n, INF);

        for (long long spike : b)
        {
            for (int i = 1; i <= k; i++)
            {
                long long need = spike - pref[i];
                auto it = robot_id.find(need);
                if (it != robot_id.end())
                {
                    int r = it->second;
                    death[r] = min(death[r], i);
                }
            }
        }

        vector<int> cnt(k + 2, 0);
        for (int i = 0; i < n; i++)
        {
            if (death[i] <= k)
                cnt[death[i]]++;
        }

        int alive = n;
        for (int i = 1; i <= k; i++)
        {
            alive -= cnt[i];
            cout << alive << " ";
        }
        cout << "\n";
    }
    return 0;
}
