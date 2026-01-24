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
        long long n;
        cin >> n;

        string s = to_string(n);
        int len = s.size();
        int firstDigit = s[0] - '0';

        int ans = 9 * (len - 1);

        long long candidate = 0;
        for (int i = 0; i < len; i++)
            candidate = candidate * 10 + firstDigit;

        ans += (candidate <= n) ? firstDigit : (firstDigit - 1);

        cout << ans << '\n';
    }
    return 0;
}
