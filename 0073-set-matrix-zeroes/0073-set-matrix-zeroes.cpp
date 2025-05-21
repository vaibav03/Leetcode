class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool isRow0 = false, isCol0 = false;

        for(int i=0;i<matrix.size();i++){
            if(!matrix[i][0]) isRow0 = true;
        }
        for(int j=0;j<matrix[0].size();j++){
            if(!matrix[0][j]) isCol0 = true;
        }

        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[i].size();j++){
                if(!matrix[i][j]) {
                    cout<<i<<" "<<j<<endl;
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for(int i=1;i<matrix.size();i++){
            if(!matrix[i][0]){
                for(int j=0;j<matrix[i].size();j++){
                    matrix[i][j] =0;
                }
            }
        }
        for(int i=1;i<matrix[0].size();i++){
            if(!matrix[0][i]){
                for(int j=0;j<matrix.size();j++){
                    matrix[j][i]=0;
                }
            }
        }

        if(isRow0){
            for(int i=0;i<matrix.size();i++){
                matrix[i][0]=0;
            }
        }
        if(isCol0){
            for(int i=0;i<matrix[0].size();i++){
                matrix[0][i] = 0;
            }
        }
    }
};