class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        int prev{};
        long long ans{};

        for(int i=1;i<=n;i++){
            if(i<n && prices[i] == prices[i-1] - 1){
                continue;
            }else{
                long long toAdd = (i-prev)*1ll*(i-prev+1)/2;
                ans+=toAdd;
                prev = i;
            }
        } 

        return ans;
    }
};