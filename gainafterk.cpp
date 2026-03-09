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
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        int total = 0;
        for (int i = 0; i < n - 1; i++)
            total += abs(a[i] - a[i + 1]);

        int maxGain = 0;

        maxGain = max(maxGain, abs(a[0] - a[1]));

        maxGain = max(maxGain, abs(a[n - 2] - a[n - 1]));

        for (int k = 1; k <= n - 2; k++)
        {
            int before = abs(a[k - 1] - a[k]) + abs(a[k] - a[k + 1]);
            int after = abs(a[k - 1] - a[k + 1]);
            maxGain = max(maxGain, before - after);
        }

        cout << total - maxGain << "\n";
    }

    return 0;
}