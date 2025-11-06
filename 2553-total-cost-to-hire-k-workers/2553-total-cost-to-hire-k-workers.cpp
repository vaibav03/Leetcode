class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int i1 = 0 ,j1 = candidates-1;
        int i2 = max(j1+1, (int) costs.size() - candidates),j2 = costs.size()-1;
        int mini1 = INT_MAX,mini2 = INT_MAX;
        priority_queue<int,vector<int>,greater<int>> pq1,pq2;
        for(int i=i1;i<=j1;i++) pq1.push(costs[i]);

        for(int i=i2;i<=j2;i++) pq2.push(costs[i]);
        long long ans{};
        while(k--){
            int mini1 = (!pq1.empty()) ? pq1.top() : INT_MAX,mini2 = (!pq2.empty()) ? pq2.top() : INT_MAX;
            cout<<mini1<<" "<<mini2<<endl;
            if(mini2 < mini1){
                pq2.pop();
                ans+=mini2;
                i2--;
                if(i2>j1){
                pq2.push(costs[i2]);
                }
            }else{
                pq1.pop();
                ans+=mini1;
                j1++;
                if(j1<i2)
                pq1.push(costs[j1]);
            }
        }
        return ans;
    }
};