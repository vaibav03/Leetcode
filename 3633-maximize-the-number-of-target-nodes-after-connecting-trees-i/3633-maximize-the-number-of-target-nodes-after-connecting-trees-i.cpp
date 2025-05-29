class Solution {
public:
        int bfs(const vector<vector<int>> &adj, vector<int> &vis, int node, int k) {
        if (vis[node] || k < 0) return 0;

        vis[node] = 1;
        if (k == 0) {
            vis[node] = 0;
            return 1;
        }

        int ans = 1; // count current node
        for (int child : adj[node]) {
            if (!vis[child]) {
                ans += bfs(adj, vis, child, k - 1);
            }
        }

        vis[node] = 0; // backtrack
        return ans;
    }


    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        if(k==0){
            vector<int> ans(edges1.size()+1,1);
            return ans;
        }
        vector<vector<int>> adj1(edges1.size()+1),adj2(edges2.size()+1);

        for(int i=0;i<edges1.size();i++){
            adj1[edges1[i][0]].push_back(edges1[i][1]);
            adj1[edges1[i][1]].push_back(edges1[i][0]);
        }
        for(int i=0;i<edges2.size();i++){
            adj2[edges2[i][0]].push_back(edges2[i][1]);
            adj2[edges2[i][1]].push_back(edges2[i][0]);
        }

        int max2 = 0;
        vector<int> vis2(adj2.size());
        for(int i=0;i<adj2.size();i++){
            int maxe =  bfs(adj2,vis2,i,k-1);
            max2 = max(max2,maxe);
        }

        vector<int> ans(adj1.size()),vis1(adj1.size());

        for(int i=0;i<adj1.size();i++){
            ans[i] = bfs(adj1,vis1,i,k);
            ans[i]+=max2;
        }
        return ans;
    }
};