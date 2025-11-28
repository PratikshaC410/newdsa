class Solution {
public:
    int n, k;
    vector<vector<int>> graph;
    vector<int> values;
    int components = 0;

    long long dfs(int u, int parent) {
        long long sum = values[u];

        for (int v : graph[u]) {
            if (v == parent) continue;
            long long childSum = dfs(v, u);

            if (childSum % k == 0) {
                components++;   // cut this edge
            } else {
                sum += childSum;
            }
        }

        return sum;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        this->n = n;
        this->k = k;
        this->values = values;

        graph.assign(n, {});
        for (auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        long long total = dfs(0, -1);

        // Don't add +1 for root; it's already counted if divisible
        if (total % k == 0) components++;

        return components;
    }
};
