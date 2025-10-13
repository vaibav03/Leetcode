class Solution {
public:
    int solve(string word1,string word2, int i , int j,vector<vector<int>> &dp){
        if(j == word2.size()){
            return word1.size() - i ;
        }else if(i == word1.size()){
            return word2.size() - j ;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        int ans = 1e8;
        if(word1[i] == word2[j]) {
            ans = min(ans ,solve(word1,word2,i+1,j+1,dp));
        }else {
            ans  = min (ans,1 + solve(word1,word2,i+1,j,dp));
            ans = min(ans,1 + solve(word1,word2,i,j+1,dp));
            ans = min(ans, 1 + solve(word1,word2,i+1,j+1,dp));
        }
        return dp[i][j] = ans;
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1,vector<int>(word2.size()+1,-1));
        return solve(word1,word2,0,0,dp);
    }
};