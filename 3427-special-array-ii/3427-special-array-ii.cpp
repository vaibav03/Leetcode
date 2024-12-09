class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans(nums.size());
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]%2==nums[i]%2)
            ans[i]+= (ans[i-1]+1);
            else
            ans[i] = ans[i-1];
        }
        vector<bool> res;
        for(int i=0;i<queries.size();i++){
            if(ans[queries[i][1]] - ans[queries[i][0]])
            res.push_back(false);
            else
            res.push_back(true);
        }
        return res;
    }
};