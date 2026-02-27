#include <bits/stdc++.h>
using namespace std;

bool nonDec(vector<int> &v)
{
    for (int i = 0; i + 1 < v.size(); i++)
        if (v[i] > v[i + 1])
            return false;
    return true;
}

int solve(vector<int> a)
{
    // BFS over states (current array)
    // We want minimum size when game ends
    set<vector<int>> visited;
    queue<vector<int>> q;
    q.push(a);
    visited.insert(a);
    int ans = a.size();

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        if (nonDec(cur))
        {
            ans = min(ans, (int)cur.size());
            continue; // game ends here
        }
        // must remove one element
        for (int i = 0; i < cur.size(); i++)
        {
            auto next = cur;
            next.erase(next.begin() + i);
            if (!visited.count(next))
            {
                visited.insert(next);
                q.push(next);
            }
        }
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &x : a)
            cin >> x;
        cout << solve(a) << "\n";
    }
}