class Solution {

public:
    bool solve(string s,int l,int r,vector<vector<int>>& dp){
        if(dp[l][r]!=-1) return dp[l][r];
        if(l>=r) return dp[l][r] = true;
    
        if(s[l] == s[r]) return dp[l][r] = solve(s,l+1,r-1,dp);
        else return false;
    }
    int countSubstrings(string s) {
        int n = s.size(),ans{};
        vector<vector<int>> dp(n,vector<int> (n,-1));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(solve(s,i,j,dp)){
                    ans++;
                }
            }
        }
        return ans;
    }
};