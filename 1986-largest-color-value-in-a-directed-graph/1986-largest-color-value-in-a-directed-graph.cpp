class Solution {
public:
bool hasCycle(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &recStack) {
    vis[node] = 1;
    recStack[node] = 1;

    for (int neighbor : adj[node]) {
        if (!vis[neighbor]) {
            if (hasCycle(neighbor, adj, vis, recStack))
                return true;
        } else if (recStack[neighbor]) {
            return true; 
        }
    }

    recStack[node] = 0;
    return false;
}

void countColors(vector<vector<int>> &adj, vector<int> &vis, vector<vector<int>> &dp, string &colors, int ind) {
    if (vis[ind]) return; 

    vis[ind] = 1;
    for (auto child : adj[ind]) {
        countColors(adj, vis, dp, colors, child);
        for (int i = 0; i < 26; i++) {
            dp[ind][i] = max(dp[ind][i], dp[child][i]);
        }
    }

    dp[ind][colors[ind] - 'a'] += 1;
}


int largestPathValue(string colors, vector<vector<int>>& edges) {
    int n = colors.size();
    vector<vector<int>> adj(n);
    for (const auto &e : edges) {
        adj[e[0]].push_back(e[1]);
    }

    vector<int> vis(n, 0), recStack(n, 0);
    for (int i = 0; i < n; ++i) {
        if (!vis[i] && hasCycle(i, adj, vis, recStack)) {
            return -1;
        }
    }

    vector<int> visit(n, 0);
    vector<int> inDegree(n, 0);
    vector<vector<int>> dp(colors.size(),vector<int> (26,0));

    for (const auto &e : edges) {
        inDegree[e[1]]++;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            countColors(adj, visit, dp, colors, i);
        }
    }
    int res{};

    for(int i=0;i<dp.size();i++){
        res = max(res,*max_element(dp[i].begin(),dp[i].end()));
    }

    return res;
}
};