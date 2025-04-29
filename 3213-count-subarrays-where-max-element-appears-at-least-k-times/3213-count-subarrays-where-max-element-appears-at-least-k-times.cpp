class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxElement = *max_element(nums.begin(), nums.end());
        long long l = 0, r = 0, occ = 0, ans = 0;
        if(nums[l]==maxElement) occ++;
        while (r < nums.size()) {
            while(occ<k){
                r++;
                if(r==nums.size()) return ans;
                if(nums[r]==maxElement)
                occ++;
            }

            if(occ==k) ans+=(nums.size() - r);

            if(nums[l]==maxElement) occ--;

            l++;
        }
        return ans;
    }
};
