class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1);

        for (auto& r : roads) {
            int a = r[0], b = r[1], d = r[2];
            adj[a].push_back({b, d});
            adj[b].push_back({a, d});
        }

        vector<bool> visited(n+1, false);
        queue<int> q;
        q.push(1);
        visited[1] = true;

        int answer = INT_MAX;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto& [next, dist] : adj[node]) {
                answer = min(answer, dist);

                if (!visited[next]) {
                    visited[next] = true;
                    q.push(next);
                }
            }
        }

        return answer;
    }
};
