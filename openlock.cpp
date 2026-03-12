#include <bits/stdc++.h>
using namespace std;

int openLock(vector<string> &deadends, string target)
{
    unordered_set<string> dead(deadends.begin(), deadends.end());
    unordered_set<string> visited;

    if (dead.count("0000"))
        return -1;

    queue<string> q;
    q.push("0000");
    visited.insert("0000");
    int moves = 0;

    while (!q.empty())
    {
        int sz = q.size();

        while (sz--)
        {
            string curr = q.front();
            q.pop();

            if (curr == target)
                return moves;

            for (int i = 0; i < 4; i++)
            {
                string up = curr;
                up[i] = (up[i] - '0' + 1) % 10 + '0';

                string down = curr;
                down[i] = (down[i] - '0' + 9) % 10 + '0';

                for (string &next : {up, down})
                {
                    if (!visited.count(next) && !dead.count(next))
                    {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }
        }
        moves++;
    }

    return -1;
}