class Solution {
public:
    bool solve(string s ,vector<string> & wordDict,int l,int r,vector<vector<int>> &dp){
        if(dp[l][r] != -1) return dp[l][r];

        for(int diff = 0;diff<=r-l+1;diff++){
            for(int ind=0;ind<wordDict.size();ind++){
                if(wordDict[ind] == s.substr(l,diff)){
                    if(l+diff == s.size()) return dp[l][r] = true;

                   bool ans =  solve(s,wordDict,l+diff,r,dp);
                   if(ans==true)
                   return dp[l][r] = ans;
                }
            }
        }
        return dp[l][r] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size()-1;
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(s,wordDict,0,s.size()-1,dp);
    }
};