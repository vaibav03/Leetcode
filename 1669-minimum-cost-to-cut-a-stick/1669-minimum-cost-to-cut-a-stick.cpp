class Solution {
public:

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        int size = cuts.size();
        vector<vector<int>> dp(size, vector<int>(size, 0));

        for(int low =size-1;low>=0;low--){
            for(int high = low+1;high<size;high++){
                if(high-low == 1){ dp[low][high] = 0; continue;}
                int ans = INT_MAX;
                for(int i=low+1;i<high;i++){
                    ans = min(ans, cuts[high] - cuts[low] + dp[low][i] + dp[i][high]);
                }
                dp[low][high] = ans;
            }
        }
        return dp[0][size-1];
    }
};
