class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        long long ans = 1e18 ,sum{};
        sum = accumulate(cost.begin(),cost.end(),0LL);

        map<char, long long> M;
        for(int i=0;i<s.size();i++){
            M[s[i]] += cost[i];
        }

        for(auto x : M){
            ans = min(ans , sum - x.second);
        }
        return ans;
    }
};