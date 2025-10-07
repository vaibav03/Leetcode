class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        int n = grid.size(),ans{};     
        vector<vector<int>> vis(n,vector<int>(n,0));
        vis[0][0] = 1; 
        pq.push({grid[0][0],{0,0}});
        vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
        
        while(!pq.empty()){
            auto x = pq.top();
            int v = x.first, i = x.second.first, j = x.second.second;
            pq.pop();

            for(auto x : dir){
                int ni = i+x[0], nj = j+x[1];
                if(ni>=0 && ni<n && nj>=0 && nj<n && !vis[ni][nj]){
                    if(ni==n-1 && nj==n-1) return max(v,grid[ni][nj]);

                    int maxi = max(v,grid[ni][nj]);
                    pq.push({maxi,{ni,nj}});
                    vis[ni][nj] = 1;
                }
            }

        }
        return 0;
    }
};