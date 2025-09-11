class Solution {
public:
    int climbStairs(int n) {
        if(n<0) return 0;
        if(n==0) return 1;
        vector<int> dp(n+1);
        int ans=1,curr,prev;
        prev = curr = 1;

        for(int i=2;i<=n;i++){
            ans = curr + prev;
            prev = curr;
            curr = ans;
        }
        return ans;
    }
};