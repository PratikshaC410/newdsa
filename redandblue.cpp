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
        vector<int> r(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> r[i];

        int m;
        cin >> m;
        vector<int> b(m + 1);
        for (int i = 1; i <= m; i++)
            cin >> b[i];

        vector<vector<int>> curr(n + 1, vector<int>(m + 1, INT_MIN));
        vector<vector<int>> best(n + 1, vector<int>(m + 1, INT_MIN));

        curr[0][0] = 0;
        best[0][0] = 0;

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if (curr[i][j] == INT_MIN)
                    continue;

                if (i + 1 <= n)
                {
                    int newCurr = curr[i][j] + r[i + 1];
                    int newBest = max(best[i][j], newCurr);
                    if (newBest > best[i + 1][j] ||
                        (newBest == best[i + 1][j] && newCurr > curr[i + 1][j]))
                    {
                        curr[i + 1][j] = newCurr;
                        best[i + 1][j] = newBest;
                    }
                }

                if (j + 1 <= m)
                {
                    int newCurr = curr[i][j] + b[j + 1];
                    int newBest = max(best[i][j], newCurr);
                    if (newBest > best[i][j + 1] ||
                        (newBest == best[i][j + 1] && newCurr > curr[i][j + 1]))
                    {
                        curr[i][j + 1] = newCurr;
                        best[i][j + 1] = newBest;
                    }
                }
            }
        }

        cout << best[n][m] << "\n";
    }

    return 0;
}