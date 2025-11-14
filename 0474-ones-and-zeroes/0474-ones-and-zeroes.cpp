class Solution {
public:
    int solve(vector<string>& strs, int i, int j,int ind,vector<vector<vector<int>>> &dp){
        if((i==0 && j==0)) return 0;
        if(i<0 || j<0 || ind>strs.size()) return -1e9;
        if(ind == strs.size()) return 0;
        if(dp[ind][i][j]!=-1) return dp[ind][i][j];

        int numOnes{},numZeroes{};
        for(auto c : strs[ind]){
            if(c == '0') numZeroes++;
        }
        numOnes = strs[ind].size() - numZeroes;

        int take = 1 + solve(strs,i - numZeroes, j - numOnes,ind+1,dp);
        int skip = solve(strs,i,j,ind+1,dp);
        //cout<<ind<<' '<<take<<" "<<skip<<endl;
        return dp[ind][i][j] = max(take,skip);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size();
        vector<vector<vector<int>>> dp(size,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        int ans = solve(strs,m,n,0,dp);
        return (ans<0) ? 0 : ans;
    }
};