#include <iostream>
using namespace std;

struct Edge
{
    int u, v, w;
};

int parent[10];

/* Find operation */
int find(int v)
{
    while (parent[v] != v)
        v = parent[v];
    return v;
}

/* Union operation */
void unionSet(int a, int b)
{
    parent[a] = b;
}

/* Sort edges by weight (Bubble Sort) */
void sortEdges(Edge edges[], int E)
{
    for (int i = 0; i < E - 1; i++)
    {
        for (int j = 0; j < E - i - 1; j++)
        {
            if (edges[j].w > edges[j + 1].w)
            {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

/* Kruskal's Algorithm */
void kruskal(Edge edges[], int V, int E)
{
    sortEdges(edges, E);

    int ecounter = 0;
    int k = 0;

    cout << "Edges in MST:\n";

    while (ecounter < V - 1)
    {
        int u = edges[k].u;
        int v = edges[k].v;
        int w = edges[k].w;
        k++;

        int x = find(u);
        int y = find(v);

        if (x != y)
        { // no cycle
            cout << u << " - " << v << " : " << w << endl;
            unionSet(x, y);
            ecounter++;
        }
    }
}

int main()
{
    int V = 4;
    int E = 5;

    Edge edges[5] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}};

    for (int i = 0; i < V; i++)
        parent[i] = i;

    kruskal(edges, V, E);

    return 0;
}
