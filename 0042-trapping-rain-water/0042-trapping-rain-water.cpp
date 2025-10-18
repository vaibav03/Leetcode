class Solution {
public:
    int trap(vector<int>& heights) {
        int ans{},n = heights.size();
        vector<int> pre(n),suf(n);
        pre[0] = heights[0];
        suf[n-1] = heights[n-1];
        for(int i=1;i<n;i++){
            pre[i] = max(pre[i-1],heights[i]);
        }
        for(int i=n-2;i>=0;i--){
            suf[i] = max(suf[i+1],heights[i]);
        }

        for(int i=0;i<n;i++) cout<<pre[i]<<' ';

        cout<<endl;
        for(int i=0;i<n;i++) cout<<suf[i]<<' ';

        for(int i=1;i<n-1;i++){
            ans+= (min(pre[i],suf[i]) - heights[i]);
        }

        return ans;
    }
};