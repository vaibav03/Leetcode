class Solution {
public:
int cost (vector<int> v1,vector<int> v2){
    return abs(v1[0] - v2[0]) + abs(v1[1] - v2[1]); 
}
    int rec(vector<vector<int>> &src,vector<vector<int>> &sink, int i ,vector<int> &vis){
        if(i == src.size()) return 0;
        int ans = INT_MAX;
        for(int ind = 0;ind< sink.size();ind++){
            if(vis[ind] == 0 ){
                vis[ind] = 1;
                ans = min(ans, rec(src,sink,i+1,vis) + cost(src[i], sink[ind]) );
                vis[ind] = 0;
            }
        }
        return ans;
    }
    int minimumMoves(vector<vector<int>>& grid) {
        vector<vector<int>> src,sink;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 0) sink.push_back({i,j});
                else {
                       while(grid[i][j] > 1){
                        grid[i][j]--;
                         src.push_back({i,j});
                        }
                    }
            }
        }
        vector<int> vis(src.size(),0);
        return rec(src,sink, 0, vis);
    }
};