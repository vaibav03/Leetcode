class Solution {
public:
    vector<vector<int>> dp;
    void solve(vector<int>& candidates,int target,int ind,vector<int> &curr){
        if(target == 0){ dp.push_back(curr); return;}

        if(ind==candidates.size()) return;
        if(target>=candidates[ind]){
            curr.push_back(candidates[ind]);
            solve(candidates,target-candidates[ind],ind,curr);
            curr.pop_back();
        }
        solve(candidates,target,ind+1,curr);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        solve(candidates,target,0,curr);
        return dp;
    }
};