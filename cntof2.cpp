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
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int total_twos = 0;
        for (int x : a)
        {
            if (x == 2)
                total_twos++;
        }

        if (total_twos % 2 != 0)
        {
            cout << -1 << "\n";
            continue;
        }

        int need = total_twos / 2;
        int cur = 0;

        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] == 2)
                cur++;
            if (cur == need)
            {
                cout << i + 1 << "\n";
                break;
            }
        }
    }

    return 0;
}
