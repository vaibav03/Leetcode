class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int minr=INT_MAX,minc=INT_MAX,maxr=0,maxc=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    minr = min(minr,i);
                    minc = min(minc,j);
                    maxr = max(maxr,i);
                    maxc = max(maxc,j);
                }
            }
        }

        return (maxr-minr+1)*(maxc-minc+1);
    }
};