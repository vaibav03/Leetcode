class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        multiset<int> ms;
        for(int i=0;i<k;i++){
            ms.insert(nums[i]);
        }   
        for(int i = k;i<n;i++){
            ans.push_back(*prev(ms.end()));
            auto it = ms.find(nums[i-k]);
            ms.erase(it);
            ms.insert(nums[i]);
        }
        ans.push_back(*prev(ms.end()));
    return ans;
    }
};