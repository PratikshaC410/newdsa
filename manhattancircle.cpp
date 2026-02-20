#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int top = 1e9, bottom = -1e9;
        int left = 1e9, right = -1e9;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                char c;
                cin >> c;

                if (c == '#')
                {
                    top = min(top, i);
                    bottom = max(bottom, i);
                    left = min(left, j);
                    right = max(right, j);
                }
            }
        }

        cout << (top + bottom) / 2 << " "
             << (left + right) / 2 << "\n";
    }

    return 0;
}