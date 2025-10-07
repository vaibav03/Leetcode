class Solution {
public:
    unordered_map<int,int> row,col,upDiag,downDiag;
    void solve(int n,vector<string> &ans,int row,vector<vector<string>> &fin_ans){
        if(row==n){
            fin_ans.push_back(ans);
            return ;
        }

        for(int i=0;i<n;i++){
            if(col[i]==0 && upDiag[row-i]==0 && downDiag[row+i]==0){
                ans[row][i] = 'Q';
                col[i] = 1;
                upDiag[row-i] = 1;
                downDiag[row+i] = 1;

                solve(n,ans,row+1,fin_ans);
                upDiag[row-i] = 0;
                downDiag[row+i] = 0;
                col[i] = 0;
                ans[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string base ="";
        for(int i=0;i<n;i++) base+='.';
        vector<string> ans(n,base);
        vector<vector<string>> fin_ans;
        for(int i=0;i<n;i++) col[i] = 0;
        solve(n,ans,0,fin_ans);
        return fin_ans;
    }
};