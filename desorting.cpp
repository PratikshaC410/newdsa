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

        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        // check if already not sorted
        bool sorted = true;
        for (int i = 1; i < n; i++)
        {
            if (a[i] < a[i - 1])
            {
                sorted = false;
                break;
            }
        }

        if (!sorted)
        {
            cout << 0 << '\n';
            continue;
        }
        // main logic
        long long mn = LLONG_MAX;
        for (int i = 0; i < n - 1; i++)
        {
            mn = min(mn, a[i + 1] - a[i]);
        }

        cout << (mn / 2 + 1) << '\n';
    }

    return 0;
}
