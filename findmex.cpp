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
        vector<long long> a(n);
        for (auto &x : a)
            cin >> x;

        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        int m = a.size();

        int ans = 0;

        for (int s = 0; s < m; s++)
        {
            long long x = -a[s];
            int cur = 0;

            for (int j = s; j < m; j++)
            {
                if (a[j] + x == cur)
                {
                    cur++;
                }
                else if (a[j] + x > cur)
                {
                    break;
                }
            }
            ans = max(ans, cur);
        }

        cout << ans << "\n";
    }
    return 0;
}
