class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int ans = 0;
      for(int i=0;i<nums.size();i++){
        set<int> odd,eve;
        for(int j=i;j<nums.size();j++){
            if(nums[j]&1) odd.insert(nums[j]);
            else eve.insert(nums[j]);
            if(odd.size() == eve.size()) ans = max(ans , j-i+1);
        }
      }
      return ans;
    }
};