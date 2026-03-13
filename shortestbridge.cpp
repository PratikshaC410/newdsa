int shortestBridge(vector<vector<int>> &grid)
{
    int n = grid.size();
    queue<pair<int, int>> q;

    // ✅ DFS: mark entire island 1 as 2, push all to queue
    function<void(int, int)> dfs = [&](int r, int c)
    {
        // check bounds
        if (r < 0 || r >= n || c < 0 || c >= n)
            return;

        // check cell value is 1
        if (grid[r][c] != 1)
            return;

        // mark as visited
        grid[r][c] = 2;
        q.push({r, c});

        // go in all 4 directions
        dfs(r + 1, c); // down
        dfs(r - 1, c); // up
        dfs(r, c + 1); // right
        dfs(r, c - 1); // left
    };

    // trigger DFS from first '1' found
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (grid[i][j] == 1)
            {
                dfs(i, j);
                goto done; // stop after finding first island
            }
done:

    // ✅ BFS: expand outward from island 1, level by level
    int steps = 0;
    while (!q.empty())
    {
        int sz = q.size();
        while (sz--)
        {
            auto [r, c] = q.front();
            q.pop();

            // check all 4 neighbors
            int nr, nc;

            // down
            nr = r + 1;
            nc = c;
            if (nr < n && grid[nr][nc] != 2)
            {
                if (grid[nr][nc] == 1)
                    return steps;
                grid[nr][nc] = 2;
                q.push({nr, nc});
            }

            // up
            nr = r - 1;
            nc = c;
            if (nr >= 0 && grid[nr][nc] != 2)
            {
                if (grid[nr][nc] == 1)
                    return steps;
                grid[nr][nc] = 2;
                q.push({nr, nc});
            }

            // right
            nr = r;
            nc = c + 1;
            if (nc < n && grid[nr][nc] != 2)
            {
                if (grid[nr][nc] == 1)
                    return steps;
                grid[nr][nc] = 2;
                q.push({nr, nc});
            }

            // left
            nr = r;
            nc = c - 1;
            if (nc >= 0 && grid[nr][nc] != 2)
            {
                if (grid[nr][nc] == 1)
                    return steps;
                grid[nr][nc] = 2;
                q.push({nr, nc});
            }
        }
        steps++;
    }
    return -1;
}