class Solution {
public:
vector<vector<int>> ans;
    void solve(vector<int>&nums,vector<int> &vis,vector<int> &curr){
        if(curr.size() == vis.size()){ ans.push_back(curr);  return; } 
        for(int i=0;i<vis.size();i++){
            if(!vis[i]){
                curr.push_back(nums[i]);
                vis[i] = 1;
                solve(nums,vis,curr);
                vis[i] = 0;
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> vis(nums.size(),0);
        vector<int> curr = {};
        solve(nums,vis,curr);
        return ans;
    }
};