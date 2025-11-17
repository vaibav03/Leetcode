class Solution {
public:
    vector<vector<int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}};

    bool dfs(vector<vector<char>>& board, vector<vector<int>>& vis,
             int i, int j, const string& word, int idx) {

        if (idx == word.size()) return true;

        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) return false;
        if (vis[i][j] || board[i][j] != word[idx]) return false;

        vis[i][j] = 1;

        for (auto &d : dirs) {
            int x = i + d[0], y = j + d[1];
            if (dfs(board, vis, x, y, word, idx + 1)) {
                return true;
            }
        }

        vis[i][j] = 0;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dfs(board, vis, i, j, word, 0)) return true;
            }
        }
        return false;
    }
};
