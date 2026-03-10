#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &a, vector<bool> &blocked, int idx, bool last_red, int max_val)
{
    int n = a.size();
    if (idx == n)
        return 0;

    // Don't pick
    int not_pick = solve(a, blocked, idx + 1, false, max_val);

    // Pick
    int pick = 0;
    if (!last_red && !blocked[idx] && a[idx] <= max_val)
    {
        pick = 1 + solve(a, blocked, idx + 1, true, max_val);
    }

    return max(pick, not_pick);
}

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
            vector<bool> blocked(n, false);
            blocked[i] = true;
            if (i > 0)
                blocked[i - 1] = true;
            if (i < n - 1)
                blocked[i + 1] = true;

            int cnt = 1 + solve(a, blocked, 0, false, a[i]);
            ans = max(ans, a[i] + cnt);
        }

        cout << ans << "\n";
    }

    return 0;
}