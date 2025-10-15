class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        int n = power.size();

        map<int, pair<int, long long>> M;
        for (int i = 0; i < n; i++) {
            M[power[i]].first++;
        }

        auto it = M.begin();
        it->second.second = 1LL * it->first * it->second.first;
        long long running_max = it->second.second;

        for (auto it = next(M.begin()); it != M.end(); ++it) {
            auto &x = *it;

            auto lb = M.lower_bound(x.first - 3);
            if (lb != M.begin() && lb->first > x.first - 3)
                --lb;

            if (lb->first <= x.first - 3)
                x.second.second = lb->second.second + 1LL * x.first * x.second.first;
            else
                x.second.second = 1LL * x.first * x.second.first;

            x.second.second = max(x.second.second, running_max);
            running_max = max(running_max, x.second.second);
        }

        long long ans = 0;
        for (auto &x : M) {
            cout << x.second.second << endl;
            ans = max(ans, x.second.second);
        }

        return ans;
    }
};
