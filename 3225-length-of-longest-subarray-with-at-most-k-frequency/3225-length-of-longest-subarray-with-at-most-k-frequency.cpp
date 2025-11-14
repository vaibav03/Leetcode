class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int start{},end{},ans{};
        unordered_map<int,int> M;
        for(int i=0;i<nums.size();i++){
            if(M[nums[i]] < k){
                M[nums[i]]++;
            }else{
                while(start<nums.size() && nums[start]!=nums[i]){M[nums[start]]--; start++;  }
                start++;
            }
            ans = max(ans,i - start + 1);
        }
        return ans;
    }
};