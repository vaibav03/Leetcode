class Solution {
public:
    int largestPrime(int n) {
        vector<bool> isPrime(n+1,true);
        isPrime[1] = false;
        for(int i=2;i<=n;i++){
            for(int j=i*2;j<=n ; j+=i){
                isPrime[j] = false;
            }
        }


        int curr{},ans{};
        for(int i=0;i<=n;i++){
            if(isPrime[i] == true){
                curr+=i;
            }
            if(curr > n) return ans;
            else if(isPrime[curr] == true) ans  = curr;
        }
        return ans;
    }
};