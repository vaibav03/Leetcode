class Solution {
public:
        int sumDivisors(int n){
        int numDiv = 0, ans = 0;
        int sq = sqrt(n);
        for(int i = 1; i <= sq; i++){
            if(n % i == 0){
                if(i == n / i){ 
                    numDiv += 1;
                    ans += i;
                } else {
                    numDiv += 2;
                    ans += i + n / i;
                }
            }
        }
        return (numDiv == 4) ? ans : 0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for(auto x : nums){
            ans+= sumDivisors(x);
        }
        return ans;
    }
};