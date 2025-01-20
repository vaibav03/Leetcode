class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size(),m = heightMap[0].size();
             priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
            vector<vector<int>> vis(n,vector<int>(m,0));
             for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(i==0 || i==n-1 || j==0 || j==m-1){
                        pq.push({heightMap[i][j],i,j});
                        vis[i][j] = 1;
                    }
                }
             }
                int ans{};
               vector <int> row = {1,-1,0,0}, col = {0,0,1,-1};
                while(!pq.empty()){
                    auto node = pq.top();
                    pq.pop();
                    for(int i=0;i<4;i++){
                        int new_row = node[1]+row[i],new_col = node[2]+col[i],minheight=node[0];
                        if(new_row>=0 && new_row<n && new_col>=0 && new_col<m && !vis[new_row][new_col]){
                           ans+=max(0,minheight-heightMap[new_row][new_col]);
                           pq.push({max(minheight,heightMap[new_row][new_col]),new_row,new_col});
                           vis[new_row][new_col] = 1;
                        }
                    }
                }
    return ans;
    }
};