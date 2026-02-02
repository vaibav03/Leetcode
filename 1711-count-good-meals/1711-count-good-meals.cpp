class Solution {
public:

    int countPairs(vector<int>& del) {
        long long ans{}, mod = 1e9+7;
        unordered_map<long long,long long> hash;
        for(auto x : del){
            hash[x]++;
        }
        for(auto [num, cnt] : hash){
            for(int i=1;i<=pow(2,21);i*=2){
                if(hash.find(i-num) != hash.end()){
                    long long pres = 0;
                    if(i-num == num){
                        pres = cnt*(cnt-1)/2;
                    } else{
                        pres = hash[num]*hash[i-num];
                    }
                    //cout<<hash[num]<<" "<hash[i-num]<<" "<<pres<<endl;
                    ans = (ans + pres)%mod;
                }
            }
            hash[num] = 0;
        }
        //cout<<ans<<endl;
        return (ans)%mod;
    }
};