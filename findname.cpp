#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    string target = "vika";

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<string> grid(n);
        for (int i = 0; i < n; i++)
            cin >> grid[i];

        int idx = 0;

        for (int col = 0; col < m && idx < 4; col++)
        {

            for (int row = 0; row < n; row++)
            {
                if (grid[row][col] == target[idx])
                {
                    idx++;
                    break;
                }
            }
        }

        cout << (idx == 4 ? "YES" : "NO") << "\n";
    }

    return 0;
}