class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> dp(n,1),prev(n,-1);
        for(int i=0;i<n;i++) prev[i] = i;

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j] == 0 && dp[j]+1>dp[i]){
                    dp[i] = dp[j]+1;
                    prev[i] = j;
                    cout<<i<<" "<<j<<endl;
                } 
            }
        }
        vector<int> ans;
        int start = max_element(dp.begin(),dp.end()) - dp.begin();
        while(start != prev[start]){
            ans.push_back(nums[start]);
            start = prev[start];
        }
        ans.push_back(nums[start]);
        return ans;
    }
};