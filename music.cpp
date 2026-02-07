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

        vector<string> rows(n);
        for (int i = 0; i < n; i++)
        {
            cin >> rows[i];
        }

        // Process from bottom to top
        for (int i = n - 1; i >= 0; i--)
        {
            for (int col = 0; col < 4; col++)
            {
                if (rows[i][col] == '#')
                {
                    cout << col + 1 << " ";
                    break;
                }
            }
        }
        cout << "\n";
    }

    return 0;
}
