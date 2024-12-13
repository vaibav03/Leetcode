class Solution {
public:
    long long findScore(vector<int>& nums) {
        vector<int> vis(nums.size(),0);
        
        vector<pair<int,int>> v;
        for(int i=0;i<nums.size();i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        
        long long sum{};
        for (auto it : v){
            if(!vis[it.second]){
                vis[it.second] = 1;
                if(it.second>=1)
                vis[it.second-1] = 1;
                if(it.second<nums.size()-1)
                vis[it.second+1] = 1;
                sum+=it.first;
            }
        }
        
        return sum;
    }
};