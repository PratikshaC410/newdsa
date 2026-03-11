#include <bits/stdc++.h>
using namespace std;

int main()
{
    int R, C;
    cin >> R >> C;

    vector<string> grid(R);
    for (int i = 0; i < R; i++)
        cin >> grid[i];

    queue<pair<int, int>> q;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (grid[i][j] == 'W')
                q.push({i, j});

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    bool impossible = false;

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (int d = 0; d < 4; d++)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || nx >= R || ny < 0 || ny >= C)
                continue;

            if (grid[nx][ny] == 'S')
            {
                impossible = true;
                break;
            }

            if (grid[nx][ny] == '.')
                q.push({nx, ny});
        }
    }
    if (impossible)
        break;
}

if (impossible)
{
    cout << "No\n";
}
else
{
    cout << "Yes\n";
    for (int i = 0; i < R; i++)
        cout << grid[i] << "\n";
}

return 0;
}