class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
         int n = nums.size();
        vector<int> mini(n,INT_MAX);
        mini[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--){
            mini[i] = min(mini[i+1], nums[i]);
        }

        int maxi = INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxi = max(maxi , nums[i]);
            int curr  = maxi - mini[i];
            if(curr <= k) return i;
        }
        return -1;
    }
};