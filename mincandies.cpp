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

        long long a[55];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        long long mn = a[0];
        for (int i = 1; i < n; i++)
        {
            if (a[i] < mn)
            {
                mn = a[i];
            }
        }

        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += (a[i] - mn);
        }

        cout << ans << "\n";
    }
    return 0;
}
