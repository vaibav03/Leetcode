class Solution {
public:
    int mod = 1e9+7;
        long long exp_mod(long long base, long long n, long long mod) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        long long half = exp_mod(base, n / 2, mod);
        return (half * half) % mod;
    } else {
        return (base % mod * exp_mod(base, n - 1, mod)) % mod;
    }
}

        int countWays(vector<vector<int>>& ranges) {
        sort(ranges.begin(), ranges.end());
        int overlap = 1;
        int last = ranges[0][1];
        for (int i = 1; i < ranges.size(); ++i) {
            if (ranges[i][0] > last) {
                overlap++;
            }
            last = max(last, ranges[i][1]);
        }
        return exp_mod(2, overlap, mod);
    }

};