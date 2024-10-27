class Solution {
public:
    int trap(vector<int>& height) {
        stack <int> st;
        st.push(height[0]);
        int i = 1,ans{},curr{}, n = height.size();

        int prefix{},suffix{};
        vector<int> pref(n,0),suff(n,0);
        pref[0]=height[0];
        for(int i=1;i<height.size();i++){
           pref[i] = max(pref[i-1],height[i]);
        }
        suff[n-1] = height[n-1];
        for(int i=height.size()-2;i>=0;i--){
            suff[i] = max(suff[i+1],height[i]);
        }

        while(i<height.size()){
            ans+=(min(suff[i],pref[i])-height[i]);
            i++;
        }
        return ans;
    }
};