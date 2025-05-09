class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size();
        int n = moveTime[0].size();
        
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({0, 0, 0});

        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};

        while (!pq.empty()) {
            auto [dist, r, c] = pq.top();
            pq.pop();

            if (r == m - 1 && c == n - 1)
                return dist;

            if (moveTime[r][c] == -1) continue;

            for (int i = 0; i < 4; ++i) {
                int nr = r + dx[i];
                int nc = c + dy[i];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && moveTime[nr][nc] != -1) {
                    int waitTime = max(0, moveTime[nr][nc] - dist);
                    pq.push({dist + 1 + waitTime, nr, nc});
                }
            }

            moveTime[r][c] = -1; 
        }

        return -1;
    }
};
