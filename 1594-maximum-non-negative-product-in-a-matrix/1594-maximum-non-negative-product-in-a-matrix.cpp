class Solution {
public:
const int mod = 1e9 + 7;
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<long long>>> dp(n,vector<vector<long long>>(m,{LLONG_MIN,LLONG_MAX}));
        dp[0][0][0] = grid[0][0];
        dp[0][0][1] = grid[0][0];
        cout<<"dijidfj"<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                    long long mx  = LLONG_MIN;
                    long long mi = LLONG_MAX;
                    long long top1,top2,l1,l2;
                    vector<long long> vec;
                    if(i == 0 && j==0) continue;

                    if(i>0){
                     top1 = dp[i-1][j][0] *1ll* grid[i][j];
                      top2 = dp[i-1][j][1] *1ll* grid[i][j];
                      vec.push_back(top1);
                      vec.push_back(top2);
                    }
                    if(j>0){
                        l1 = dp[i][j-1][1] *1ll* grid[i][j];
                        l2 = dp[i][j-1][0] *1ll* grid[i][j];
                        vec.push_back(l1);
                        vec.push_back(l2);
                    }
                    
                    sort(vec.begin(),vec.end());
                    dp[i][j][0] = vec.back();
                    dp[i][j][1] = vec[0];
                    
                    cout<<"{"<<dp[i][j][0]<<","<<dp[i][j][1]<<"}"<<" ";
                }
                cout<<endl;
            }
        
        return (dp[n-1][m-1][0] < 0) ? -1 : (dp[n-1][m-1][0])%mod ;
    }
};