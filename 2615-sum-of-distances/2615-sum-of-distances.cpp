class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int,pair<long long,int>> m;
        int n = nums.size();
        vector<long long> ans(n,0);
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i]) == m.end()){
                m[nums[i]] = {i,1};
            }else{
                long long curr = m[nums[i]].second*1ll*i -  m[nums[i]].first; 
                ans[i] += curr;
                m[nums[i]].first+=i;
                m[nums[i]].second++;
            }
        }
        m.clear();
        for(int i=nums.size()-1;i>=0;i--){
            if(m.find(nums[i]) == m.end()){
                m[nums[i]] = {i,1};
            }else{
                long long curr = abs(m[nums[i]].second*1ll*i -  m[nums[i]].first); 
                ans[i] += curr;
                m[nums[i]].first+=i;
                m[nums[i]].second++;
            }
        }
        return ans;
    }
};