class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int,int> M;
        for(int i=0;i<nums.size();i++){
            M[nums[i]-i]++;
        }
        long long  ans{},n = nums.size();
        for(auto i : M){
            int res =  i.second*(n - i.second);
            ans+=res*1ll;
        }
        return ans/2;
    }
};