#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        int n = nums.size();
       // if(n == 1) return min( max(0,nums[0]-k)/2 , )
        const int INF = 1e9;
        vector<vector<vector<int>>> dp(n+1,
            vector<vector<int>>(op1+1, vector<int>(op2+1, INF)));
        for(int i=0;i<=op1;i++){
            for(int j=0;j<=op2;j++){
                dp[0][i][j] = 0;
            }
        }

        dp[0][0][0] = 0; 
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= op1; j++) {
                for (int p = 0; p <= op2; p++) {

                    dp[i][j][p] = min(dp[i][j][p], dp[i-1][j][p] + nums[i-1]);

                    if (j > 0)
                        dp[i][j][p] = min(dp[i][j][p],
                            dp[i-1][j-1][p] + (nums[i-1] + 1) / 2);

                    if (p > 0 && nums[i-1] >= k)
                        dp[i][j][p] = min(dp[i][j][p],
                            dp[i-1][j][p-1] + max(0, nums[i-1] - k));

                    if (j > 0 && p > 0 && nums[i-1] >= k)
                        dp[i][j][p] = min(dp[i][j][p],
                            dp[i-1][j-1][p-1] + max(0, (nums[i-1] - k + 1) / 2));

                    if (j > 0 && p > 0 && (nums[i-1] + 1) / 2 >= k)
                        dp[i][j][p] = min(dp[i][j][p],
                            dp[i-1][j-1][p-1] + max(0, (nums[i-1] + 1) / 2 - k));
                }
            }
        }

        return dp[n][op1][op2];
    }
};
