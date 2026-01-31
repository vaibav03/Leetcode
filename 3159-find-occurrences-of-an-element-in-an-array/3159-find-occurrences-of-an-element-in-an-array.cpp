class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> pos,ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == x) pos.push_back(i);
        }
        for(int i=0;i<queries.size();i++){
            if(pos.size() < queries[i]) ans.push_back(-1);
            else
            ans.push_back(pos[queries[i] - 1]);
        }
        return ans;
    }
};