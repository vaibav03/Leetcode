class Solution {
public:
    int mod = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        vector<long long> dist(n,LLONG_MAX),ways(n);
        for(auto x : roads){
            adj[x[0]].push_back({x[1],x[2]});
            adj[x[1]].push_back({x[0],x[2]});
        } 

        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
        pq.push({0,0});
        dist[0] = 0;
        ways[0] = 1;
        while(!pq.empty()){
           auto [distN,node] = pq.top();
           pq.pop();
           for(auto [v,edW] : adj[node]){
            if(dist[v] > edW + distN ){
                dist[v] = edW + distN;
                ways[v] = ways[node];
                pq.push({dist[v],v});
            }else if(dist[v] == edW + distN){
                ways[v]+=ways[node]%mod;
            }
           }
        }
        return ways[n-1]%mod;
    }
};