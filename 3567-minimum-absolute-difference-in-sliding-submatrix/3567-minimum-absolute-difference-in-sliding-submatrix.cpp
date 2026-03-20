class Solution {
public: 
    int giveAns(vector<vector<int>> & grid, int i ,int j,int k){
        if(k == 1) return 0;
        vector<int> vals;
        for(int x = i;x<i+k;x++){
            for(int y = j;y<j+k;y++){
                vals.push_back(grid[x][y]);
            }
        }
        sort(vals.begin(),vals.end());
        int ans = INT_MAX;
        for(int i=1;i<vals.size();i++){
            if(vals[i] != vals[i-1])
            ans = min(ans, vals[i] - vals[i-1]);
        }
        return (ans ==INT_MAX) ? 0 : ans;
    }
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n-k+1, vector<int>(m-k+1));

        for(int i=0;i<=n-k;i++){
            for(int j=0;j<=m-k;j++){
                ans[i][j] = giveAns(grid,i,j,k);
                cout<<i<<" "<<j<<" "<<ans[i][j]<<endl;
            }
        }
        return ans;
    }
};