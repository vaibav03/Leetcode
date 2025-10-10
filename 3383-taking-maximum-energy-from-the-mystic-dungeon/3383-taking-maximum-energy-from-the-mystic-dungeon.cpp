class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size(),ans=INT_MIN;
        vector<int> dp(n+1,0);
        for(int i=0;i<n;i++)
        dp[i] = energy[i];

        for(int i=k;i<n;i++){
            dp[i] = max(dp[i],dp[i-k] + energy[i]);
        }

        for(int i=max(n-k,0);i<n;i++) ans = max(ans,dp[i]);
        cout<<endl;

        return ans;
    }
};