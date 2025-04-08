class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        set<int> s;
        int prev{};
        for(int i=nums.size()-1;i>=0;i--){

            if(i!=nums.size()-1)
             prev = s.size();

            s.insert(nums[i]);
            if(s.size() == prev)
            return ceil((float) (i+1)/3);
        }
        return 0;
    }
};