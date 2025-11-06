class Solution {
public:
vector<vector<int>> ans;
    void solve(vector<int> &vis,vector<int> &curr){
        if(curr.size() == vis.size()){ ans.push_back(curr);  return; } 

        for(int i=0;i<vis.size();i++){
            if(!vis[i] && ((i+1)%(curr.size()+1) ==0 || ((curr.size()+1)%(i+1)) == 0) ){
                curr.push_back(i+1);
                vis[i] = 1;
                solve(vis,curr);
                vis[i] = 0;
                curr.pop_back();
            }
        }
    }
    int countArrangement(int n) {
        vector<int> vis(n,0),curr;
        solve(vis,curr);
        return ans.size();
    }
};