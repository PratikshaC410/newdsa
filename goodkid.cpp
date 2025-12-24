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
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        long long ans = 0;

        for (int i = 0; i < n; i++)
        {
            a[i]++;
            long long product = 1;
            for (int j = 0; j < n; j++)
            {
                product *= a[j];
            }
            ans = max(ans, product);
            a[i]--;
        }

        cout << ans << '\n';
    }

    return 0;
}
