class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if( !(r*c == mat.size()*mat[0].size()) ) return mat;
        vector<vector<int>> ans;
        vector<int> curr;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                curr.push_back(mat[i][j]);
                if(curr.size() == c){
                    ans.push_back(curr);
                    curr = {};
                }
            }
        }
        return ans;
    }
};