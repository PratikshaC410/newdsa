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
        int n, k;
        cin >> n >> k;

        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        vector<long long> prefMax(n), suffMax(n);
        prefMax[0] = 0;
        for (int i = 1; i < n; i++)
        {
            prefMax[i] = max(prefMax[i - 1], a[i - 1]);
        }

        suffMax[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--)
        {
            suffMax[i] = max(suffMax[i + 1], a[i + 1]);
        }

        for (int i = 0; i < n; i++)
        {
            long long A = a[i];
            int good = 0;

            for (int pos = 0; pos < n; pos++)
            {
                long long maxL = (pos == 0 ? 0 : prefMax[pos]);
                long long maxR = (pos == n - 1 ? 0 : suffMax[pos]);

                int cheats = 0;
                if (A < maxL)
                    cheats++;
                if (A < maxR)
                    cheats++;

                if (cheats <= k)
                    good++;
            }

            cout << good << " ";
        }
        cout << "\n";
    }
    return 0;
}
