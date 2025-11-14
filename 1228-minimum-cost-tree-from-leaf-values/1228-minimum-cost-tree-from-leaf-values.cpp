class Solution {
public:
int solve(vector<int> &arr,map<pair<int,int>, int> &maxi,int i ,int j,vector<vector<int>> &dp){
    if( i == j )  return 0;
    int ans = INT_MAX;
    if(dp[i][j] != -1 ) return dp[i][j];
    for(int k=i;k<j;k++){
         ans = min(solve(arr,maxi,i,k,dp) + solve(arr,maxi,k+1,j,dp) + maxi[{i,k}]*maxi[{k+1,j}] , ans);
    }
    return dp[i][j] = ans;
}
    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int,int>, int> maxi;
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(n,1e9));
        for(int i=0;i<n;i++){
            maxi[{i,i}] = arr[i];
            for(int j=i+1;j<n;j++){
                maxi[{i,j}] = max(maxi[{i,j-1}], arr[j]);
            }
        }

        for(int i=0;i<n;i++) dp[i][i] = 0;

        for(int start = n-1;start>=0 ;start--){
            for(int end = 0;end<n;end++){
                if(start >= end) continue;
                for(int k=start;k<end;k++){
                    dp[start][end] = min(dp[start][k] + dp[k+1][end]+ maxi[{start,k}]*maxi[{k+1,end}] , dp[start][end]);
                }
            }
        }
        return dp[0][n-1];
    }
};