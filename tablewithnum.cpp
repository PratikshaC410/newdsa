#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n, h, l;
        cin >> n >> h >> l;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        int countH = 0, countL = 0;

        for (int x : a)
        {
            if (x <= h)
                countH++;
            if (x <= l)
                countL++;
        }

        int ans = min({countH, countL, n / 2});
        cout << ans << "\n";
    }

    return 0;
}