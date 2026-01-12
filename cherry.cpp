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

        vector<int> deg(n + 1, 0);
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            deg[u]++;
            deg[v]++;
        }

        int leaves = 0;
        for (int i = 2; i <= n; i++)
        {
            if (deg[i] == 1)
                leaves++;
        }

        if (leaves == 2)
            cout << "NO\n";
        else
            cout << "YES\n";
    }

    return 0;
}
