class Solution {
public:
    vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
    
    bool isPossible(int row, int col, int day, vector<vector<int>>& cells) {
        vector<vector<int>> grid(row, vector<int>(col, 0));
        
        for (int i = 0; i <= day; i++) {
            grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
        }
        
        queue<pair<int,int>> q;
        for (int c = 0; c < col; c++) {
            if (grid[0][c] == 0) {
                q.push({0, c});
                grid[0][c] = 1; 
            }
        }
        
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            if (r == row - 1) return true;
            
            for (auto& d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr >= 0 && nr < row && nc >= 0 && nc < col && grid[nr][nc] == 0) {
                    grid[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int l = 0, r = cells.size() - 1;
        int ans = 0;
        
        while (l <= r) {
            int mid = ( l + r )/ 2;
            if (isPossible(row, col, mid, cells)) {
                ans = mid + 1;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};