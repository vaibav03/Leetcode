class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(),ans=nums[0],st=1,end=1;
        for(int i=0;i<n;i++){
            if(st==0){
                st = 1;

            }
            if(end==0){
                end = 1;
            }
         st*=nums[i];
         end*=nums[n-i-1];
         ans = max(st,max(end,ans));
        }
        return ans;
    }
};
