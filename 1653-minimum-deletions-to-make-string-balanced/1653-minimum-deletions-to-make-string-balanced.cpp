class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> pre(n+1,0),suc(n+1,0);

        for(int i=1;i<=n;i++){
            pre[i] = pre[i-1];
            if(s[i-1] == 'b') pre[i]++;
        }

        for(int i=n-1;i>=0;i--){
            suc[i] = suc[i+1];
            if(s[i] == 'a') suc[i]++;
        }
        int ans = INT_MAX;
        for(int i=0;i<=n;i++){
            //cout<<pre[i]<<" "<<suc[i]<<endl;
            ans = min(ans , pre[i] + suc[i]);
        }
        return ans;
    }
};