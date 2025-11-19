class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> M;
        M[0] = -1;  
        int pre = 0;
        for(int i = 0; i < nums.size(); i++) {
            pre += nums[i];
            int r = pre % k;

            if(M.find(r) != M.end()) {
                if(i - M[r] >= 2) return true;
            } else {
                M[r] = i; 
            }
        }
        return false;
    }
};
