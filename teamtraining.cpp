#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        long long x;
        cin >> n >> x;

        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        sort(a.begin(), a.end(), greater<long long>());

        long long teamSize = 0;
        long long ans = 0;

        for (int i = 0; i < n; i++)
        {
            teamSize++;

            if (teamSize * a[i] >= x)
            {
                ans++;
                teamSize = 0;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}