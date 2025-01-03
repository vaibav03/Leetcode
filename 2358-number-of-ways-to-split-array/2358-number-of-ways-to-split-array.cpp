class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long int pres{},sum{};
        int ans{};

        for(int i=0;i<nums.size();i++)
        sum+=nums[i];

        for(int i=0;i<nums.size()-1;i++){
            pres+=nums[i];
            if(pres>=sum-pres)
            ans++;
        }
        return ans;
    }
};