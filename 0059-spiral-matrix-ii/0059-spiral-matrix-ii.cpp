class Solution {
public:
    vector<vector<int>> change = {{0,1}, {1,0}, {0,-1},{-1,0}};
    int cont{},curr = 2;
    void rec(vector<vector<int>>& matrix ,int i,int j, int ch ){
        int ni = i + change[ch][0] , nj = j + change[ch][1];
        if(cont  == 5) return ;
        cout<<ni<<" "<<nj<<endl;
        if((ni >= matrix.size() || nj >= matrix[0].size() || ni<0 || nj < 0) || (matrix[ni][nj] != 0)) {
        cont++;
        return rec(matrix,i,j,(ch+1)%4);
        }

        cont = 0;
        matrix[ni][nj] = curr;
        curr++;
        rec(matrix, ni,nj, ch);
    }

    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int>(n,0));
        matrix[0][0] = 1;
        rec(matrix , 0, 0, 0);
        return matrix;
    }
};