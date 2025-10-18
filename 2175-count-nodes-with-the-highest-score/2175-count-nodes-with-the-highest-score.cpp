class Solution {
public:
    long long ans = 0;
    int cnt = 0;

    int dfs(vector<vector<int>> &adj, int v, int n) {
        long long score = 1;  
        int size = 1;         

        for (int child : adj[v]) {
            int sub = dfs(adj, child, n);
            score *= sub;   
            size += sub;
        }

        int remaining = n - size; 
        if (remaining > 0)
            score *= remaining;    

        if (score > ans) {
            ans = score;
            cnt = 1;
        } else if (score == ans) {
            cnt++;
        }

        return size;
    }

    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size();
        vector<vector<int>> adj(n);

        for (int i = 0; i < n; i++) {
            if (parents[i] != -1)
                adj[parents[i]].push_back(i);
        }

        dfs(adj, 0, n);
        return cnt;
    }
};
