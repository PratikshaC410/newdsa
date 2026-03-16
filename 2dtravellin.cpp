#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n, k, a, b;
        cin >> n >> k >> a >> b;
        a--;
        b--;

        vector<ll> x(n), y(n);
        for (int i = 0; i < n; i++)
            cin >> x[i] >> y[i];

        auto dist = [&](int i, int j) -> ll
        {
            return abs(x[i] - x[j]) + abs(y[i] - y[j]);
        };

        ll ans = dist(a, b);

        if (k > 0)
        {
            ll costA = LLONG_MAX;
            if (a < k)
            {
                costA = 0;
            }
            else
            {
                for (int m = 0; m < k; m++)
                    costA = min(costA, dist(a, m));
            }

            ll costB = LLONG_MAX;
            if (b < k)
            {
                costB = 0;
            }
            else
            {
                for (int m = 0; m < k; m++)
                    costB = min(costB, dist(m, b));
            }

            ans = min(ans, costA + costB);
        }

        cout << ans << "\n";
    }
    return 0;
}