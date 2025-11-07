class Solution {
public:
    int mod = 1e9 + 7;
    long long fac(int n){
        long long ans = 1;
        for(int i=1;i<=n;i++){
            ans*=i;
            ans%=mod;
        }
        return ans%mod;
    }
    long long power(long long a ,long long b){
        long long res = 1;
        while(b>0){
            if(b%2 == 1){ res = (res*a)%mod; b--;}
            else{
                a = (a*a)%mod;
                b/=2;
            }
        }
        return res%mod;
    }
    
    int countAnagrams(string s) {
        string word = "";
        long long ans = 1,i{};
        while(i < s.size()){
            long long tot{};
            unordered_map<char,long long> M;

            while(s[i]!=' ' && i<s.size()) {
                tot++;
                M[s[i]]++;
                i++;
            }
            tot = fac(tot);
            for(auto x : M){
                int facs = fac(x.second);
                int modinv = power(facs,mod-2);
                tot = (tot*modinv)%mod;
            }
            ans*=tot;
            ans%=mod;
            i++;
        }
        return ans;
    }
};