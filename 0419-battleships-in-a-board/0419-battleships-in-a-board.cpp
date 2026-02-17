class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int ans{},n = board.size(),m = board[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == 'X'){
                    char top = '.',left = '.';
                    if(i>0) top = board[i-1][j];
                    if(j>0) left = board[i][j-1];

                    if(top!='X' && left!='X') ans++;
                } 
            }
        }
        return ans;
    }
};