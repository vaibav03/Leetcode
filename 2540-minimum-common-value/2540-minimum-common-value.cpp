class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
       unordered_map<int,int> mp;
       for(auto x : nums1){
        if(mp.find(x) == mp.end()) mp[x]++;
       }
       for(auto x : nums2){
        if(mp.find(x)!= mp.end()) mp[x]++;
       }
       int ans = INT_MAX;
       for(auto x : mp){
        if(x.second>=2) ans = min(ans, x.first);
       }
       return (ans == INT_MAX) ? -1 : ans ;

    }
};