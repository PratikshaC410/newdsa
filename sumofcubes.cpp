#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long x;
        cin >> x;

        bool found = false;

        for (long long a = 1; a * a * a < x; a++)
        {

            long long rem = x - a * a * a;

            long long lo = 1, hi = 100001;
            while (lo <= hi)
            {
                long long mid = lo + (hi - lo) / 2;
                long long cube = mid * mid * mid;

                if (cube == rem)
                {
                    found = true;
                    break;
                }
                else if (cube < rem)
                    lo = mid + 1;
                else
                    hi = mid - 1;
            }

            if (found)
                break;
        }

        cout << (found ? "YES" : "NO") << "\n";
    }
}