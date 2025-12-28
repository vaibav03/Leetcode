class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
     long long ans = 1e18;
     ans = min(ans , costBoth*1ll*max(need1,need2));
     ans = min(ans, cost1*1ll*need1 + cost2*1ll*need2);
     if(need1 > need2 ){
         long long curr = cost1* 1ll *(need1 - need2) + need2 *1ll*costBoth;
         ans = min(ans,curr);
     }  else{
        long long curr = cost2* 1ll *(need2 - need1) + need1 *1ll*costBoth;
         ans = min(ans,curr);
     }
     return ans;
    }
};