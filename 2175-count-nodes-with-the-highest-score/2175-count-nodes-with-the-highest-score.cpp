class Solution {
public:
    long long ans{};
    int cnt{};
    int dfs(vector<vector<int>> &adj, int v){
        

        int right=0,left=0;
        if(adj[v].size()>=1)
        right = dfs(adj,adj[v][0]);
        if(adj[v].size()>=2)
        left = dfs(adj,adj[v][1]);

        int curr_r = (right == 0) ? 1 : right;
        int curr_l = (left == 0) ? 1 : left ;
        int x = (adj.size() - left - right - 1 == 0 ) ? 1 : adj.size() - left - right - 1;
        long long curr = 1ll*curr_r*curr_l*(x); 

            if(curr > ans){
                cnt = 1;
                ans = curr;
            }else if(curr == ans){
                cnt++;
            }
        return left+right+1;
    }
    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++) {
            if(parents[i]!=-1)
            adj[parents[i]].push_back(i);
            }

        dfs(adj,0);
        return cnt;
    }
};