class Solution {
public:
    int solve(vector<int> &cuts, int low, int high, vector<vector<int>> &dp) {
        if (high - low <= 1) return 0;  

        if (dp[low][high] != -1) return dp[low][high];

        int ans = INT_MAX;
        for (int i = low + 1; i < high; i++) {  
            int cost = (cuts[high] - cuts[low]) +
                       solve(cuts, low, i, dp) +
                       solve(cuts, i, high, dp);
            ans = min(ans, cost);
        }
        return dp[low][high] = (ans == INT_MAX ? 0 : ans);
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        int size = cuts.size();
        vector<vector<int>> dp(size, vector<int>(size, -1));

        return solve(cuts, 0, size - 1, dp);
    }
};
