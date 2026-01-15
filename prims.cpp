#include <iostream>
using namespace std;
#define inf = 999;
int main()
{
    int v, source;
    cout << "Enter the number of vertices" << endl;
    cin >> v;
    int cost[20][20];
    int i, j;
    cout << "Enter the  cost matrix" << endl;
    for (i = 0; i < v; i++)
    {
        for (j = 0; j < v; j++)
        {
            cin >> cost[i][j];
        }
    }
    cout << "Enter source" << endl;
    cin >> source;

    int visited[20], dist[], path[];
    for (i = 0; i < v; i++)
    {
        dist[i] = cost[source][i];
        path[i] = source;
        visited[i] = 0;
    }
    visited[source] = 1;
    for (int iter = 0; iter < n; iter++)
    {
        int u = -1;
        int min = inf + 1;
        for (int i = 0; i < v; i++)
        {
            if (!visited[i] && dist[i] < min)
            {
                min = dist[i];
                u = i;
            }
        }
        if (u == -1)
            break;

        visited[u] = 1;
        for (int j = 0; j < v; j++)
        {
            if (!visited[j] && cost[u][j] != inf)
            {
                if (dist[v] > cost[u][v])
                {
                    dist[v] = cost[u][v];
                    path[j] = u;
                }
            }
        }
    }
}