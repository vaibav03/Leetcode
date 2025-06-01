class Solution {
public:
    long long distributeCandies(int n, int limit) {
        if(n == 3 *limit) return 1;
        long long  ans{};
        
        for(int i=0;i<=min(n,limit);i++){
            if(n-i>2*limit) continue;

            ans+=(min(limit,n-i) - max(n-i-limit,0)+1);
        }
    return ans;
    }

};