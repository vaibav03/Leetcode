class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int x = pow(2,nums.size());
        vector<vector<int>> ans;
        for(int i=0;i<x;i++){
            vector<int> curr;
            for(int j=0;j<nums.size();j++){
                if( ((1<<j)& i )) curr.push_back(nums[j]);
            }
            ans.push_back(curr);
        }
        return ans; 
    }
};