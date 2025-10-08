class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int diffBits{},xore{};
        for(int i=0;i<nums.size();i++){
            xore^=nums[i];
        }
        xore^=k;
        int i = 31;
        while(i>=0){
            if((xore>>i)&1) diffBits++;
            i--;
        }
        return diffBits;
    }
};