class Solution {
public:
    pair<int, int> intToPos(int index, int n) {
        int row = n - 1 - index / n;
        int col = index % n;
        if ((n - row) % 2 == 0) {
            col = n - 1 - col;
        }
        return {row, col};
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<bool> visited(n * n, false);
        queue<pair<int, int>> q;  // {cell number, moves}
        q.push({0, 0});
        visited[0] = true;

        while (!q.empty()) {
            auto [ind, moves] = q.front();
            q.pop();

            if (ind == n * n - 1)
                return moves;

            for (int i = 1; i <= 6 && ind + i < n * n; ++i) {
                int nextInd = ind + i;
                auto [row, col] = intToPos(nextInd, n);
                if (board[row][col] != -1) {
                    nextInd = board[row][col] - 1;
                }
                if (!visited[nextInd]) {
                    visited[nextInd] = true;
                    q.push({nextInd, moves + 1});
                }
            }
        }

        return -1;
    }
};
