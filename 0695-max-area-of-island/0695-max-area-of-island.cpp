class Solution {
public:
    vector<vector<int>> visitNeigh = {{1,0},{0,1},{-1,0},{0,-1}};
    int bfs(vector<vector<int>>& grid , vector<vector<int>> &vis ,int i ,int j){
        if(i>= grid.size() || j>=grid[0].size() || grid[i][j]==0 ||  vis[i][j]) return 0;
        
        int res = 1;
        vis[i][j] = 1;
        for(auto vec : visitNeigh){
            int x = i+ vec[0],y = j+vec[1];
            res += bfs(grid,vis,x,y);
        }
    return res;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    ans = max(ans , bfs(grid,vis,i,j));
                }
            }
        }
        return ans;
    }
};