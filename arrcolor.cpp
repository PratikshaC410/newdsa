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
            cin >> a[i];

        // assign colors
        vector<int> color(n);
        for (int i = 0; i < n; i++)
            color[i] = i % 2;

        vector<pair<int, int>> p(n);
        for (int i = 0; i < n; i++)
            p[i] = {a[i], color[i]};
        sort(p.begin(), p.end());

        // check
        bool ok = true;
        for (int i = 0; i < n - 1; i++)
        {
            if (p[i].second == p[i + 1].second)
            {
                ok = false;
                break;
            }
        }

        cout << (ok ? "YES" : "NO") << "\n";
    }
}