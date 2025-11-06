class Solution {
public:
    int mod = 1e9 + 7;

    long long sum(long long n) {
        long long inv2 = 500000004; // modular inverse of 2 under mod 1e9+7
        return (n % mod) * ((n + 1) % mod) % mod * inv2 % mod;
    }

    int maxProfit(vector<int>& inventory, int orders) {
        sort(inventory.begin(), inventory.end(), greater<int>());
        for (int i = 0; i < inventory.size(); i++) cout << inventory[i] << " ";
        cout << endl;
        inventory.push_back(0);

        long long ans = 0;
        int n = inventory.size();

        for (int j = 1; j < n; j++) {
            long long curr = inventory[j - 1];
            long long prev = inventory[j];
            long long currOrders = (curr - prev) * j;
            long long curr_sum = ((sum(curr) - sum(prev) + mod) % mod * j) % mod;


            if (currOrders > orders) {
                long long lev = orders / j;
                long long rem = orders % j;
                ans = (ans + ((sum(curr) - sum(curr - lev) + mod) % mod * j) % mod) % mod;
                ans = (ans + rem * (curr - lev)) % mod;
                return ans % mod;
            } else {
                ans = (ans + curr_sum) % mod;
                orders -= currOrders;
            }
        }

        return ans % mod;
    }
};
