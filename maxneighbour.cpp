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

        vector<vector<int>> grid(n, vector<int>(n));

        int num = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                grid[i][j] = num++;
            }
        }

        int maxCost = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int cost = grid[i][j];

                if (i > 0)
                    cost += grid[i - 1][j];
                if (i < n - 1)
                    cost += grid[i + 1][j];
                if (j > 0)
                    cost += grid[i][j - 1];
                if (j < n - 1)
                    cost += grid[i][j + 1];

                maxCost = max(maxCost, cost);
            }
        }

        cout << maxCost << "\n";
    }

    return 0;
}