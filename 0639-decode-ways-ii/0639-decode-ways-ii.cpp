class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;
        const int mod = 1e9 + 7;
        int n = s.size();
        vector<long long> dp(n, 0);

        dp[0] = (s[0] == '*') ? 9 : 1;

        for (int i = 1; i < n; i++) {
            if (s[i-1] != '*' && s[i] != '*') {
                int ones = s[i] - '0';
                int twos = (s[i-1] - '0') * 10 + ones;

                if (ones >= 1) dp[i] = (dp[i] + dp[i-1]) % mod;
                if (twos >= 10 && twos <= 26)
                    dp[i] = (dp[i] + ((i >= 2) ? dp[i-2] : 1)) % mod;
            }
            else if (s[i-1] == '*' && s[i] == '*') {
                dp[i] = (dp[i] + dp[i-1] * 9) % mod;
                dp[i] = (dp[i] + ((i >= 2) ? dp[i-2] * 15 : 15)) % mod;
            }
            else if (s[i-1] == '*') {
                int ones = (s[i] == '0') ? 0 : s[i] - '0';
                if (ones >= 1) dp[i] = (dp[i] + dp[i-1]) % mod;

                if (s[i] >= '0' && s[i] <= '6')
                    dp[i] = (dp[i] + ((i >= 2) ? dp[i-2] * 2 : 2)) % mod;
                else if (s[i] >= '7' && s[i] <= '9')
                    dp[i] = (dp[i] + ((i >= 2) ? dp[i-2] : 1)) % mod;
            }
            else if (s[i] == '*') {
                dp[i] = (dp[i] + dp[i-1] * 9) % mod;
                if (s[i-1] == '1')
                    dp[i] = (dp[i] + ((i >= 2) ? dp[i-2] * 9 : 9)) % mod;
                else if (s[i-1] == '2')
                    dp[i] = (dp[i] + ((i >= 2) ? dp[i-2] * 6 : 6)) % mod;
            }
        }

        return dp[n-1];
    }
};
