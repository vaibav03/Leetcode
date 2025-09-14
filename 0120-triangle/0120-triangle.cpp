class Solution {
public:
    int solve(vector<vector<int>>& triangle,int i,int j){
        if(i>=triangle.size() || j>=triangle[triangle.size()-1].size()) return 0;

        return triangle[i][j] + min(solve(triangle,i+1,j),solve(triangle,i+1,j+1));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n-1].size();
        vector<int> dp(m),prev(m);
        for(int i=0;i<n;i++){
            for(int j=0;j<triangle[i].size();j++){
                int x = 1e9 ,y = 1e9;
                if(j!=triangle[i].size()-1)
                 x = prev[j];

                 if(j>0) y = prev[j-1];

                dp[j] = triangle[i][j] + min(x,y);
                
                 if(i==0 && j==0) dp[j] = triangle[i][j];
            }
            for(int i=0;i<dp.size();i++) cout<<dp[i]<<" ";
            cout<<endl;
            prev = dp;
        }


        return *min_element(dp.begin(),dp.end());
    }
};