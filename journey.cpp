#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        long long n, a, b, c;
        cin >> n >> a >> b >> c;
        long long lo = 1, hi = 3e9, ans = hi;

        while (lo <= hi)
        {
            long long mid = (lo + hi) / 2;

            long long full = mid / 3;
            long long rem = mid % 3;

            long long total = full * (a + b + c);
            if (rem >= 1)
                total += a;
            if (rem >= 2)
                total += b;

            if (total >= n)
            {
                ans = mid;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}