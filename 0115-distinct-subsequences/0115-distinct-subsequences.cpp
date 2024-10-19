class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<double>> dp(s.size()+1,vector<double>(t.size()+1,0));

        for(int i=0;i<=s.size();i++)
        dp[i][0]=1;

        for(int i=1;i<=s.size();i++){
            for(int j=1;j<=t.size();j++){
                double  take{},nottake{};
                if(s[i-1]==t[j-1])
                take = dp[i-1][j-1];

                nottake = dp[i-1][j];
                dp[i][j] = take+nottake;
            }
        }
    return (int)dp[s.size()][t.size()];
    }
};