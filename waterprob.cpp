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
        string s;
        cin >> s;

        int ans = 0;
        for (int i = 0; i < n;)
        {
            if (s[i] == '#')
            {
                i++;
                continue;
            }
            int j = i;
            while (j < n && s[j] == '.')
                j++;
            int len = j - i;

            bool touches_left = (i == 0);
            bool touches_right = (j == n);

            if (touches_left || touches_right)
            {
                ans += len;
            }
            else
            {
                ans += (len + 1) / 2;
            }

            i = j;
        }

        cout << ans << '\n';
    }

    return 0;
}
