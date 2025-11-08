class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int mod = 12345;
        vector<vector<int>> pre(n,vector<int>(m,1));

        for(int i=0;i<n;i++){
            if(i!=0) pre[i][0] = (pre[i-1][m-1] * 1ll* grid[i-1][m-1])%mod;
            for(int j=1;j<m;j++){
                pre[i][j] = (pre[i][j-1]*1ll*grid[i][j-1])%mod;
            }
        }

        long long post = 1;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                pre[i][j] = (pre[i][j]*1ll*post)%mod;
                post = (grid[i][j]*1ll*post)%mod; 
            }
        }
        return pre;
    }
    
};