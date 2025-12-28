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
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        int oddParity = a[0] % 2;

        bool ok = true;
        for (int i = 0; i < n; ++i)
        {
            if (i % 2 == 0)
            {
                if (a[i] % 2 != oddParity)
                {
                    ok = false;
                    break;
                }
            }
            else
            {
                if (a[i] % 2 != evenParity)
                {
                    ok = false;
                    break;
                }
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}
