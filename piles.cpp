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
        long long n, k;
        cin >> n >> k;

        if (k > n)
        {
            cout << -1 << '\n';
            continue;
        }

        for (int time = 0; time <= 60; time++)
        {
            long long low = n >> time;
            long long high = (n + (1LL << time) - 1) >> time;

            if (low <= k && k <= high)
            {
                cout << time << '\n';
                break;
            }
        }
    }
    return 0;
}
