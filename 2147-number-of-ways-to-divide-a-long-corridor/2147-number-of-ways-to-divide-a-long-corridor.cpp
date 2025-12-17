class Solution {
public:
    int numberOfWays(string corridor) {
        long long ans = 1, n = corridor.size(),num{},bw{};
        int mod = 1e9 + 7;
        vector<int> v;
        for(int i=0;i<n;i++){
            if( corridor[i] == 'S'){
                v.push_back(i);
            }
        }

        if(v.size() < 2 || v.size()%2 == 1) return 0;
        for(int i=2;i<v.size();i++){
            int curr = v[i] - v[i-1];
            ans = (ans * curr)%mod;
            i++;
        }
        return ans;
    }
};