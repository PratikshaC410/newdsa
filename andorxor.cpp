#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b, x, y;
        cin >> a >> b >> x >> y;

        const int MAXV = 300;
        vector<long long> dist(MAXV + 1, LLONG_MAX);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        dist[a] = 0;
        pq.push({0, (int)a});

        while (!pq.empty())
        {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dist[u])
                continue;

            if (u + 1 <= MAXV && dist[u] + x < dist[u + 1])
            {
                dist[u + 1] = dist[u] + x;
                pq.push({dist[u + 1], u + 1});
            }

            int v = u ^ 1;
            if (v <= MAXV && dist[u] + y < dist[v])
            {
                dist[v] = dist[u] + y;
                pq.push({dist[v], v});
            }
        }

        if (dist[b] == LLONG_MAX)
            cout << -1 << "\n";
        else
            cout << dist[b] << "\n";
    }
}