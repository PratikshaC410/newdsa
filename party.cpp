#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> children[2001];
int parent[2001];

int dfs(int node)
{
    int maxDepth = 0;
    for (int child : children[node])
    {
        maxDepth = max(maxDepth, dfs(child));
    }
    return maxDepth + 1;
}

int main()
{
    cin >> n;

    vector<int> roots;

    for (int i = 1; i <= n; i++)
    {
        int p;
        cin >> p;
        parent[i] = p;
        if (p == -1)
            roots.push_back(i);
        else
            children[p].push_back(i);
    }

    int ans = 0;
    for (int root : roots)
    {
        ans = max(ans, dfs(root));
    }

    cout << ans << endl;
    return 0;
}