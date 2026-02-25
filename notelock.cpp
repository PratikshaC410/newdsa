#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int ans = 0, last_safe = -1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                if (last_safe >= i - k + 1)
                {
                    last_safe = i;
                }
                else
                {
                    int pp = i;
                    for (int j = i - 1; j >= max(0, i - k + 1); j--)
                        if (s[j] == '1')
                        {
                            pp = j;
                            break;
                        }
                    ans++;
                    last_safe = i;
                }
            }
        }
        cout << ans << "\n";
    }
}