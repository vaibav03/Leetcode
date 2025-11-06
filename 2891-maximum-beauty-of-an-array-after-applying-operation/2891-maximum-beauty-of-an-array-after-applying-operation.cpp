class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        map<int,int> M;
        for(int i=0;i<nums.size();i++){
            M[nums[i]-k] += 1;
            M[nums[i]+k+1] += -1;
        }
        int ans{},sum{};
        for(auto it = M.begin();it!=M.end();it++){
            sum+= it->second;
            ans = max(sum,ans);
        }
        return ans;
    }
};