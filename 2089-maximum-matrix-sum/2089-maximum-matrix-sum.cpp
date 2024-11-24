class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long int cnt{},mini=INT_MAX;

        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix.size();j++){
                if(matrix[i][j]<0)
                cnt++;

                matrix[i][j]=abs(matrix[i][j]);
                mini = min(mini,1ll*matrix[i][j]);
            }
        }
        long long int sum{};
        for( auto i : matrix){
            sum+=accumulate(i.begin(),i.end(),0);
        }
        return (cnt%2==0) ? sum : sum-2*mini;
    }
};