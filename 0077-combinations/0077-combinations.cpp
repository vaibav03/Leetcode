class Solution {
public:
    vector<vector<int>> ans; 
    void solve(vector<int> &vis,vector<int> curr,int k){
        if(curr.size() == k){
            ans.push_back(curr);
            return ;
        }
        for(int i=0;i<vis.size();i++){
            if(!vis[i]){
                if( curr.empty() || curr[curr.size()-1]<i+1 ){
                    curr.push_back(i+1);
                    vis[i] = 1;
                    solve(vis,curr,k);
                    vis[i] = 0;
                    curr.pop_back();
                } 
            }
        }
    }   
    vector<vector<int>> combine(int n, int k) {
        vector<int> vis(n,0),curr;
        solve(vis,curr,k);
        return ans;
    }
};