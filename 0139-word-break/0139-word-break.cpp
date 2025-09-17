class Solution {
public:

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n+1);
        for(auto word : wordDict){
            int len = word.size();
            if( len<=n && s.substr(0,len) == word ) dp[word.size()-1] = true;
        }

        for(int i=0;i<n;i++){
            for(auto word : wordDict){
                int len = word.size();
                if(len<=i  && dp[i-len] && s.substr(i-len+1,len) == word  ) dp[i] = true;
            } 
        }
        for(int i=0;i<n;i++) cout<<dp[i]<<" ";
        cout<<endl;
        return dp[n-1];
    }
};