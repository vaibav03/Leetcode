class Solution {
public:
    int numSub(string s) {
        long long  cont{},ans{},mod = 1e9 +7;
        for(int i=0;i<s.size();i++){
            if(s[i] == '1') cont++;
            else if(s[i] == '0'){
                cont = (cont*(cont+1)/2)%mod;
                ans = (ans + cont)%mod;
                cont = 0;
            }
        }
        cont = (cont*(cont+1)/2)%mod;
        return  (ans + cont)%mod;
    }
};