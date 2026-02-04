class Solution {
public:
    bool ans(string &s, string &p ,int i , int j,vector<vector<int>> &dp){
        if(i == s.size() && j==p.size() ) return true;
        if(j == p.size()) return false;
        if(i == s.size()){
            while(j<p.size() && p[j]=='*') j++;
            return (j==p.size());
        }
        bool res = false;

        if(dp[i][j] != -1) return dp[i][j];

        if(p[j] == '*'){ res|=ans(s,p,i+1,j,dp);  res|=ans(s,p,i,j+1,dp); }
        else if(p[j] == '?') res|=ans(s,p,i+1,j+1,dp);
        else if(s[i] == p[j]) res|=ans(s,p,i+1,j+1,dp);

        return dp[i][j] = res;
    }
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return ans(s,p,0,0,dp);
    }
};