class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        map<int,int> M;
        for(int i=1;i<nums.size();i++){
          M[nums[i]+nums[i-1]]++;
          if(M[nums[i]+nums[i-1]]>=2)
          return true;
        }
        return false;
    }
};