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

        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += abs(a[i]);
        }

        int operations = 0;
        bool segment = false;

        for (int i = 0; i < n; i++)
        {
            if (a[i] < 0)
            {
                if (!segment)
                {
                    operations++;
                    segment = true;
                }
            }
            else if (a[i] > 0)
            {
                segment = false;
            }
        }

        cout << sum << " " << operations << "\n";
    }

    return 0;
}