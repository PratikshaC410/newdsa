#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        long long h;
        cin >> n >> m >> h;

        vector<long long> orig(n);
        for (int i = 0; i < n; i++)
            cin >> orig[i];

        vector<long long> added(n, 0);

        for (int i = 0; i < m; i++)
        {
            int b;
            long long c;
            cin >> b >> c;
            b--;

            added[b] += c;

            if (orig[b] + added[b] > h)
            {

                fill(added.begin(), added.end(), 0);
            }
        }

        for (int i = 0; i < n; i++)
        {
            cout << orig[i] + added[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}
