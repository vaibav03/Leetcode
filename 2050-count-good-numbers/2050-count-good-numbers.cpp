class Solution {
public:
    int mod  = 1e9+7;
    int power(long long int base ,long long int powe){
    int ans = 1;
    while(powe>0){
        if(powe%2==0){
            base=base*base%mod;
            powe/=2;
        }
        else{
            powe--;
            ans= ans*base%mod;
        }
    }    
    return ans;
    }

    int countGoodNumbers(long long n) {
          int even = power(5,1ll*ceil(n/2.0)) ,odd =power(4,1ll*n/2);
         cout<<ceil(n/2.0)<<" "<<n/2<<endl;
         long long int ans = (1ll*(even%mod)*(odd%mod)%mod);        
        return ans%mod;
    }
};