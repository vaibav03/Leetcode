class Solution {
public:
    vector<vector<int>> dp;
    void solve(vector<int>& candidates,int target,int ind,vector<int> &curr){
        if(target == 0){ dp.push_back(curr); return;}

        if(ind==candidates.size()) return;
        if(target>=candidates[ind]){
            curr.push_back(candidates[ind]);
            int num = candidates[ind];
            // while(ind<candidates.size() && candidates[ind]==num) ind++;
            solve(candidates,target-num,ind +1,curr);
            curr.pop_back();
        }
        while(ind<candidates.size()-1 && candidates[ind]==candidates[ind+1]) ind++;
        solve(candidates,target,ind+1,curr);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> curr;
        solve(candidates,target,0,curr);
        return dp;

    }
};