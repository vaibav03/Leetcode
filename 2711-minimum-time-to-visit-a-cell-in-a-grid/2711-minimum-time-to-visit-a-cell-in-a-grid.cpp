class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
      int n = grid.size(), m = grid[0].size();
      priority_queue< vector<int>, vector<vector<int>>,greater<vector<int>> > q;
      vector<vector<int> > vis(n,vector<int> (m,INT_MAX));
      vector<int> row = {1, -1, 0, 0};
        vector<int> col = {0, 0, 1, -1};
        int ans = INT_MAX;
        q.push({0,0, 0});
        while (!q.empty()) {
        auto node = q.top();
        q.pop();
            int obs = node[0];
            int x = node[1], y = node[2];
            for (int i = 0; i < 4; i++) {
                int newX = x + row[i], newY = y + col[i];
                if (newX >= 0 && newY >= 0 && newX < n && newY < m) {
                    int newObs = obs + 1;
                    if(grid[newX][newY] <= newObs && vis[newX][newY]==INT_MAX) {
                        q.push({newObs, newX, newY});
                        vis[newX][newY] = newObs;
                    }
                    else{
                        for(int j=0;j<4;j++){
                        int checkX = x + row[j],checkY = y + col[j];
                        if(checkX >= 0 && checkY >= 0 && checkX < n && checkY < m && 
                        (obs+1)>=grid[checkX][checkY] && vis[newX][newY]==INT_MAX){
                        
                        if( ((obs-grid[newX][newY])%2) == 0)
                        q.push({grid[newX][newY]+1, newX, newY});
                        else
                        q.push({grid[newX][newY], newX, newY});
                        vis[newX][newY] = newObs;
                        break;
                        }
                        }
                    }
                }
            }
            if(node[1] == n-1 && node[2]==m-1)
            ans = min(ans,node[0]);
        }
        return (ans==INT_MAX) ? -1 : ans;   
         }
};