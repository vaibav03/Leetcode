class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for(int j=y;j<y+k;j++){
            int lo = x, hi = x+k-1;
            while(lo<hi){
                cout<<grid[lo][j]<<" "<<grid[hi][j]<<endl;
                swap(grid[lo][j],grid[hi][j]);
                lo++;
                hi--;
            }
        }
        return grid;
    }
};