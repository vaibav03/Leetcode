class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto &x : edges) {
            int u = x[0], v = x[1], w = x[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, 2 * w});
        }

        const int INF = 1e9;
        vector<int> vis(n);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();
            if (vis[node]) continue;
            vis[node] = 1;
            if (node == n - 1) return d;
            for (auto &[next, w] : adj[node]) {
                if (!vis[next]) {
                    pq.push({d+w, next});
                }
            }
        }

        return -1;
    }
};
