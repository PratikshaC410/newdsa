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
        vector<long long> a(n), b(n);
        for (auto &x : a)
            cin >> x;
        for (auto &x : b)
            cin >> x;

        sort(a.rbegin(), a.rend());

        long long ans = 0;
        long long prefix_strikes = 0;
        int k = 0;

        for (int i = 0; i < n; i++)
        {
            long long x = a[i];
            int usable = i + 1;
            while (k < n && prefix_strikes + b[k] <= usable)
            {
                prefix_strikes += b[k];
                k++;
            }

            ans = max(ans, x * k);
        }

        cout << ans << "\n";
    }
    return 0;
}
