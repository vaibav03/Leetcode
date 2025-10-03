class Solution {
public:
    vector<vector<int>> dp;
    void solve(int target,int ind,int k,vector<int> &curr){
        if(target == 0 && k==0) { dp.push_back(curr); return;}

        if(ind>9 || k==0 ) return;
        if(target>=ind){
            curr.push_back(ind);
            solve(target-ind,ind+1,k-1,curr);
            curr.pop_back();
        }
        solve(target,ind+1,k,curr);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curr;
        solve(n,1,k,curr);
        return dp;
    }
};