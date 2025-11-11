class Solution {
public:
    void bfs(vector<vector<char>>& grid,vector<vector<int>> & vis,int i, int j){
        if(i>=grid.size() || j>=grid[0].size() || i<0 || j<0) return ;

        if(grid[i][j] == '1' && !vis[i][j]){
            vis[i][j] = 1;
            bfs(grid,vis,i+1,j);
            bfs(grid,vis,i-1,j);
            bfs(grid,vis,i,j+1);
            bfs(grid,vis,i,j-1);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int islands{};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == '1'){ bfs(grid,vis,i,j); islands++;}
            }
        }
    return islands;
    }
};