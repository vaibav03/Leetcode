class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        
        int maxi=0;
        unordered_set<int>even,odd;
        for(int i=0;i<nums.size();i++){
            odd.clear();
            even.clear();
            for(int j=i;j<nums.size();j++){
                if((nums[j]&1) == 1) odd.insert(nums[j]);
                else even.insert(nums[j]);

                if(even.size() == odd.size()) maxi = max(maxi,j-i+1);
            }
        }
        return maxi;
    }
};