#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;

        vector<long long> a(n + 1), pref(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            pref[i] = pref[i - 1] + a[i];
        }

        while (q--)
        {
            int l, r;
            long long x;
            cin >> l >> r >> x;

            long long range_sum = pref[r] - pref[l - 1];

            long long delta = (r - l + 1LL) * x - range_sum;

            long long new_sum = pref[n] + delta;

            cout << new_sum << " ";
        }
        cout << "\n";
    }
    return 0;
}
