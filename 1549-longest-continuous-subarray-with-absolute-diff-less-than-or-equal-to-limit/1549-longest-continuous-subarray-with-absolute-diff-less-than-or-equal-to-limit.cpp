class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> s;
        int n = nums.size(), j{},i{},ans{};
        while(j<n){
            s.insert(nums[j]);
            int diff = *s.rbegin() - *s.begin();
            while(i<j && diff > limit){
                auto it  = s.find(nums[i]);
                s.erase(it);
                i++;
                diff = *s.rbegin() - *s.begin();
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};