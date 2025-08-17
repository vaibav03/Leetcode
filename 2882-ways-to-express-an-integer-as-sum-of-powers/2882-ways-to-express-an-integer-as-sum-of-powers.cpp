class Solution {
public:
    int MOD = 1e9 + 7;
    int dp(int n, int x,int pres,vector<vector<int>> &memo,int limit){        
        if(n==0) return 1;
        if(pres> limit || n<0) return 0; 
        if(memo[n][pres]!=-1) return memo[n][pres];

        return memo[n][pres] = ((dp(n,x,pres+1,memo,limit)%MOD) + (dp(n-pow(pres,x),x,pres+1,memo,limit)%MOD))%MOD;
    }
    int numberOfWays(int n, int x) { 
         int limit  = ceil(pow(n,1.0/x));
         cout<<limit<<endl;
         vector<vector<int>> memo(n+1,vector<int>(limit+1,-1));
         int ans = dp(n,x,1,memo,limit); 
         return ans; 
    }
};