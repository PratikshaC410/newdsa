#include <bits/stdc++.h>
using namespace std;

int count_power(long long x, int p)
{
    int cnt = 0;
    while (x % p == 0)
    {
        x /= p;
        cnt++;
    }
    return cnt;
}

bool is_special(long long x)
{
    int v2 = count_power(x, 2);
    int v3 = count_power(x, 3);
    int v7 = count_power(x, 7);
    return min(v2, v3) > v7;
}

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

        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        int answer = -1;

        for (int k = 0; k < 42; k++)
        {
            bool ok = true;

            for (int i = 0; i < n; i++)
            {
                if (!is_special(a[i] + k))
                {
                    ok = false;
                    break;
                }
            }

            if (ok)
            {
                answer = k;
                break;
            }
        }

        cout << answer << "\n";
    }

    return 0;
}