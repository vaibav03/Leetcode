class Solution {
public:
    int ans{};
    int  subseq(string &s,string &t,int i,int j,vector<vector<int>> &dp){
        if(j == -1) {
            ans++;
            return 1;
        }else if(i == -1) {
            return 0 ;
        }

        if(dp[i][j]!=-1) {
            return dp[i][j];
        }
        if(s[i] == t[j]) {
            return dp[i][j] = subseq(s,t,i-1,j-1,dp) + subseq(s,t,i-1,j,dp);;
        } else{ 
             return dp[i][j] = subseq(s,t,i-1,j,dp);
         }
    }
    int numDistinct(string s, string t) {
        int n = s.size(),m = t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return subseq(s,t,s.size()-1,t.size()-1,dp);
    }
};