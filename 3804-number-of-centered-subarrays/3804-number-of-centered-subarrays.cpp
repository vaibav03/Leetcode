class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int n = nums.size(),ans{};
        for(int i=0;i<n;i++){
            int pre{};
            unordered_map<int,int> hash;
            for(int j=i;j<n;j++){
                hash[nums[j]]++;
                pre+= nums[j];
                if(hash[pre] >= 1) ans++;
            }
        }
        return ans;
    }
};