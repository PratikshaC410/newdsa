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

        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int need_even = 0, need_odd = 0;

        for (int i = 0; i < n; i++)
        {
            if ((i % 2) != (a[i] % 2))
            {
                if (i % 2 == 0)
                    need_even++;
                else
                    need_odd++;
            }
        }

        if (need_even != need_odd)
            cout << -1 << "\n";
        else
            cout << need_even << "\n";
    }

    return 0;
}
