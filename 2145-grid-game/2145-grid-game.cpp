class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
         vector<long long > suf(n),pre(n);
        for(int i=n-1;i>=0;i--){
            if(i!=n-1)
            suf[i]+=suf[i+1];

            suf[i]+=grid[1][i];
        }
        for(int i=0;i<n;i++){
            if(i)
            pre[i]+=pre[i-1];

            pre[i]+=grid[0][i];
        }
        int ind = 0;
        long long ans = 1e12;
        for(int i=0;i<n;i++){
            ans =   min( 1ll*max(pre[n-1]-pre[i],suf[0]-suf[i]) , ans );
        }
        return ans;
    }
};