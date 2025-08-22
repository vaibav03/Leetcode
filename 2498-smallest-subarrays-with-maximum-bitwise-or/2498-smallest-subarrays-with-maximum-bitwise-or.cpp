class Solution {
public:
    void toAdd(vector<int> & nums,vector<int> &bitSet,int ind,int val){
        for(int i=0;i<32;i++){
            if((nums[ind]&(1<<i))){
                bitSet[i]+=val;
            }
        }
    }
    vector<int> smallestSubarrays(vector<int>& nums) {

        int n = nums.size(),right=n-1,left = n-2;
        vector<int> bitSet(32,0);
        vector<int> ans(n,-1);
        ans[n-1] = 1;
        toAdd(nums,bitSet,n-1,1);

        while(left>=0){
            toAdd(nums,bitSet,left,1);

           bool canRemove = true;

           while(canRemove && left<=right){
            for(int i=0;i<32;i++){
            if ((nums[right]&(1<<i)) ){
                if(bitSet[i]<2){
                     canRemove = false;
                     }  
            }
        }
        if(canRemove){
            toAdd(nums,bitSet,right,-1);
            right--;
        }
            }
           if(right<left) ans[left] = 1;
           else
           ans[left] = right - left+1;
           left--; 
        }
        return ans;
    }
};