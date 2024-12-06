class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        vector<int> vis(n+1,0);
        for(int i=0;i<banned.size();i++){
            if(banned[i]<=n)
            vis[banned[i]]=1;
        }
        int sum{},ans{};
        for(int i=1;i<=n;i++){
            if(!vis[i] && (sum+i)<=maxSum)
            {
                sum+=i;
                ans++;
            }
        }
        return ans;
    }
};