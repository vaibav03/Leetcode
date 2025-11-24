class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        int ans{},xore{},num_e{},num_o{};
        map<pair<int,int>,int> pre_xor;
        pre_xor[{0,0}] = -1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2 == 0) num_e++;
            else num_o++;
            xore^=nums[i];
            if(pre_xor.find({xore,num_e-num_o}) == pre_xor.end()){
                pre_xor[{xore,num_e-num_o}] = i;
            }else{
                ans = max(ans,i - pre_xor[{xore,num_e-num_o}]);
            }
        }
        return ans;
    }
};