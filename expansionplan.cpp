#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        long long n, x, y;
        cin >> n >> x >> y;
        string s;
        cin >> s;

        long long c4 = count(s.begin(), s.end(), '4');
        long long c8 = count(s.begin(), s.end(), '8');

        long long ax = abs(x), ay = abs(y);

        bool ok = (max(ax, ay) <= c4 + c8) && (ax + ay <= c4 + 2 * c8);
        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}