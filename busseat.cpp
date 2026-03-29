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

        vector<bool> occupied(n + 2, false);

        // First passenger
        occupied[a[0]] = true;

        bool ok = true;

        for (int i = 1; i < n; i++)
        {
            int seat = a[i];

            if (!occupied[seat - 1] && !occupied[seat + 1])
            {
                ok = false;
                break;
            }

            occupied[seat] = true;
        }

        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}