class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> hash;
        for(auto num : nums){
            if(hash[num] < k){
                ans.push_back(num);
                hash[num]++;
            }
        }
        return ans;
    }
};