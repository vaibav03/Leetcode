class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(n == 0 || s[0] == '0') return 0;

        vector<int> dp(n, 0);
        dp[0] = 1;

        for(int i = 1; i < n; i++) {
            int one = s[i] - '0';
            int two = (s[i-1] - '0') * 10 + one;

            if(one >= 1 && one <= 9) dp[i] += dp[i-1];

            if(two >= 10 && two <= 26) {
                dp[i] += (i >= 2 ? dp[i-2] : 1);
            }
        }

        return dp[n-1];
    }
};
