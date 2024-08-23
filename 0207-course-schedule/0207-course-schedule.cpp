class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
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
 int cnt{};
    while(!q.empty()){
    int node = q.front();
    q.pop();
    cnt++;
    for(auto i: adj[node]){
        indegree[i]--;
        if(!indegree[i])
         q.push(i);
    }
    }
    if(cnt==n) return true;
    else return 0;
    }
};