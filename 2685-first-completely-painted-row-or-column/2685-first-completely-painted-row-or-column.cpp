class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        map<int,pair<int,int>> M;
        vector<int> row(mat.size(),0), col(mat[0].size(),0);

        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                M[mat[i][j]] = {i,j};
            }
        }
        for(int i=0;i<arr.size();i++){
            int rowe = M[arr[i]].first,cole = M[arr[i]].second;
            row[rowe]++;
            col[cole]++;
            if(row[rowe]==mat[0].size() || col[cole]==mat.size())
            return i;
        }
        return 0;
    }

};