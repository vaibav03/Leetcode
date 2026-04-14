class Solution {
public:
    bool isValidRow(vector<vector<char>>& board,int row){
        unordered_set<char> s;
        for(int i=0;i<9;i++){
            if(board[row][i] == '.') continue;
            if(s.find(board[row][i]) == s.end()) s.insert(board[row][i]);
            else return false;
        }
        return true;
    }
    bool isValidCol(vector<vector<char>>& board, int col){
        unordered_set<char> s;
        for(int i=0;i<9;i++){
            if(board[i][col] == '.') continue;
            if(s.find(board[i][col]) == s.end()) s.insert(board[i][col]);
            else  return false;
        }
        return true;
    }
    bool isValidBox(vector<vector<char>>& board, int row, int col){
        unordered_set<char> s;
        for(int i=row;i<row+3;i++){
            for(int j = col;j<col+3;j++){
                if(board[i][j] == '.') continue;
                if(s.find(board[i][j])==s.end()) s.insert(board[i][j]);
                else return false;
            }
        }
            return true;
        
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size(),m = board[0].size();
        int validRows{}, validCols{}, validBox{};
        for(int i=0;i<n;i++){
            if(!isValidRow(board,i)) return false;
        }
        for(int i=0;i<m;i++){
            if(!isValidCol(board,i)) return false;
        }

        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                if(!isValidBox(board,i,j)) return false;
            }
        }
        return true;
    }
};