class Solution {
public:
    vector<vector<int>> change = {{0,1}, {1,0}, {0,-1},{-1,0}};
    vector<int> ans;
    int cont{};
    void rec(vector<vector<int>>& matrix ,int i,int j, int ch ){
        int ni = i + change[ch][0] , nj = j + change[ch][1];
        if(cont  == 5) return ;
        cout<<ni<<" "<<nj<<endl;
        if((ni >= matrix.size() || nj >= matrix[0].size() || ni<0 || nj < 0) || (matrix[ni][nj] == -1000)) {
        cont++;
        return rec(matrix,i,j,(ch+1)%4);
        }

        cont = 0;
        ans.push_back(matrix[ni][nj]);
        matrix[ni][nj] = -1000;
        rec(matrix, ni,nj, ch);
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        ans.push_back(matrix[0][0]);
        matrix[0][0] = -1000;
        rec(matrix, 0,0,0);
        return ans;
    }
};