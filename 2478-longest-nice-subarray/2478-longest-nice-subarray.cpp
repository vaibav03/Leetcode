class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int ans = 0, r = 0, mask = 0;
        for (int l = 0; l < nums.size(); l++) {
            if (r < l) r = l;
            while (r < nums.size() && (mask & nums[r]) == 0) {
                mask |= nums[r];
                r++;
            }
            ans = max(ans, r - l);
            if (r > l) mask ^= nums[l]; 
        }
        return ans;
    }
};
