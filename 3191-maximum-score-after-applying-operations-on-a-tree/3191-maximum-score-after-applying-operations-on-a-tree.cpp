class Solution {
public:
    long long dfs(int i,vector<int>adj[],vector<int>& v,vector<int>&vis)
    {  
        if(adj[i].size()==1 && i!=0)
            return (long long)v[i];
       long long s=0;
       vis[i]=1;
       for(auto j:adj[i])
       {    
           if(vis[j]==1)
            continue;
           s=s+dfs(j,adj,v,vis);
       } 
       return min((long long)v[i],s);
    }
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n=values.size();
        vector<int>adj[n];
        for(int i=0;i<n-1;i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        long long s=0;
        for(auto i:values)
            s=s+i;
        vector<int>vis(n,0);
        long long k=dfs(0,adj,values,vis);
        return s-k;
    }
};