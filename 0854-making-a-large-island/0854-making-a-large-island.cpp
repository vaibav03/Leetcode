    class Solution {
    public:
    int explore(vector<vector<int>> & grid,int i, int j,int id){
    if(i>=grid.size() || j>=grid[0].size() || i<0 || j<0 || grid[i][j]!=1) return 0;
        int size = 1;
        grid[i][j] = id;
        size+=explore(grid,i+1,j,id);
        size+=explore(grid,i,j+1,id);
        size+=explore(grid,i-1,j,id);
        size+=explore(grid,i,j-1,id);
        return size;
    
}
    int largestIsland(vector<vector<int>>& grid) {
        int landid=2;
        vector<int> landsize;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    landsize.push_back(explore(grid,i,j,landid));
                    landid++;
                }
            }
        }
        int ans{};
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0){
                    unordered_set<int> s;
                    vector<int> row = {1,-1,0,0},col = {0,0,1,-1};
                    for(int ind=0;ind<4;ind++){
                        int new_row = i+row[ind],new_col = j+col[ind];
                        if(new_row>=0 && new_row<grid.size() && new_col>=0 && new_col<grid[i].size()){
                            s.insert(grid[new_row][new_col]);
                        }
                    }
                    int res=1;
                    for(auto it : s){
                        if(it>=2)
                        res+=landsize[it-2];
                    }
                    ans=max(ans,res);
                }
            }
        }
        if(ans==0) return grid.size()* grid[0].size();
        return ans;
    }
    };
    