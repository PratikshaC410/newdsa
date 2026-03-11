#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> parent(n + 1);
    parent[1] = 0;

    for (int i = 2; i <= n; i++)
    {
        cin >> parent[i];
    }

    vector<int> path;
    int cur = n;
    while (cur != 0)
    {
        path.push_back(cur);
        cur = parent[cur];
    }

    reverse(path.begin(), path.end());

    for (int node : path)
    {
        cout << node << " ";
    }

    return 0;
}
