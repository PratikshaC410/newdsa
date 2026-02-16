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

        vector<int> freq(n + 1, 0);
        int ans = -1;

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            freq[x]++;

            // once found, keep it
            if (freq[x] >= 3)
                ans = x;
        }

        cout << ans << '\n';
    }

    return 0;
}
