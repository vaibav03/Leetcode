class Solution {
public:
    unordered_map<int, unordered_map<int,int>> row, col, box;
    vector<vector<char>> ans;

    void solve(vector<vector<char>>& board, int i, int j) {
        if (!ans.empty()) return; 
        if (i == 9) { 
            ans = board;
            return;
        }
        
        int ni = (j == 8) ? i + 1 : i;
        int nj = (j == 8) ? 0 : j + 1;
        
        if (board[i][j] != '.') {
            solve(board, ni, nj);
            return;
        }
        
        for (int val = 1; val <= 9; val++) {
            if (row[i][val] == 0 && col[j][val] == 0 && box[(i/3)*3 + j/3][val] == 0) {
                row[i][val] = col[j][val] = box[(i/3)*3 + j/3][val] = 1;
                board[i][j] = '0' + val;

                solve(board, ni, nj);

                row[i][val] = col[j][val] = box[(i/3)*3 + j/3][val] = 0;
                board[i][j] = '.';
            }
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int val = board[i][j] - '0';
                    row[i][val] = col[j][val] = box[(i/3)*3 + j/3][val] = 1;
                }
            }
        }

        solve(board, 0, 0);
        board = ans;
    }
};
