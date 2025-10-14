class Solution {
public:
    int need{},have{};
    void dfs(vector<vector<int>> &adj, vector<int> &vis, int node, int parent) {
    for (auto neigh : adj[node]) {
        if (neigh == parent) continue;  
        if (vis[neigh]) {               
            have++;
            continue;
        }
        vis[neigh] = 1;
        dfs(adj, vis, neigh, node);
    }
}

    int makeConnected(int n, vector<vector<int>>& connections) {

        vector<int> vis(n,0);
        vector<vector<int>> adj(n);

        for(auto x : connections){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        for(int i=0;i<n;i++){
            if(!vis[i]){
                vis[i] = 1;
                dfs(adj,vis,i,-1);
                need++;
            }
        }
        need--;
        //cout<<need<<" "<<have<<endl;    
        return (have/2>=need) ? need : -1;
    }
};