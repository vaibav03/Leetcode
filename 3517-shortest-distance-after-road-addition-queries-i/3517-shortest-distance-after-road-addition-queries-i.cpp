class Solution {
public:
   
    int bfs (vector<vector<int>> &adj){
        queue<pair<int,int>> q;
        vector<int> vis(adj.size(),0);
        q.push({0,0});
        int ans = INT_MAX;
        while(!q.empty()){
            auto node  = q.front();
            q.pop();
            if(!vis[node.first])
            {
                vis[node.first] = 1;
                for(int x : adj[node.first]){
                q.push({x,node.second+1});
                }
            if(node.first==adj.size()-1)
            ans = min(ans,node.second);
            }
        }
        return ans;
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        for(int i=0;i<n-1;i++){
          adj[i].push_back(i+1);
        }
        vector<int> ans;
        for(auto x : queries){
            adj[x[0]].push_back(x[1]);
            ans.push_back(bfs(adj));
        }
        return ans;
    }
};