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

        long long sum = 0;
        long long mn = LLONG_MAX;

        for (int i = 0; i < n; i++)
        {
            long long x;
            cin >> x;
            sum += x;
            mn = min(mn, x);
        }

        cout << sum - mn << "\n";
    }

    return 0;
}