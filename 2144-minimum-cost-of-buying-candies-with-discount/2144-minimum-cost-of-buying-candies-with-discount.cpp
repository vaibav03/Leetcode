class Solution {
public:
    int minimumCost(vector<int>& cost) {
        if(cost.size() <= 2) return accumulate(cost.begin(),cost.end(),0LL);

        sort(cost.begin(),cost.end());
        long long ans{};
        for(int i = cost.size() - 1;i>=0;i--){

            if(i>=1)
            ans+= (cost[i] + cost[i-1]);
            else ans+= cost[i];

            i-=2;
        } 
        return ans;
    }
};
