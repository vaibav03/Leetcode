class Solution {
public:
    int binExp(long long num ,int powe , int mod){
        long long res = 1;
        while(powe > 0){
            if(powe %2 == 0){
                num = num*num % mod; 
                powe/=2;
            }else{
                res = (res*num*1ll)%mod;
                powe--;
            }
        }
        return res;
    }
    int modInv(long long num, int mod){
        return binExp(num,mod - 2,mod);
    }
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<long long,long long> M;
        for(auto x : points){
            M[x[1]]++;
        }
        long long sum{},mod = 1e9 +7;
        long long ans{};
        for(auto x : M){
            M[x.first] = x.second*1ll*(x.second - 1) /2;
            sum+=M[x.first];
        }
        for(auto x : M){
            long long curr = M[x.first]*1ll*(sum - M[x.first]);
            ans = (ans + curr)%mod;
        }
        int inv = modInv(2, mod);
        return (ans* inv) %mod;
    }
};