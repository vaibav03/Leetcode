class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(n,vector<int>(0));
    vector<int> indegree(n,0);
    for(auto i : prerequisites){
        adj[i[1]].push_back(i[0]);
        indegree[i[0]]++;
    }
    
    queue<int> q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0)
         q.push(i);   
        
    }
    vector<int> ans;
    while(!q.empty()){
    int node = q.front();
    q.pop();
    ans.push_back(node);
    for(auto i: adj[node]){
        indegree[i]--;
        if(!indegree[i])
         q.push(i);
    }
    }
    if(ans.size()==n) return ans;
    else return {};
    }
};