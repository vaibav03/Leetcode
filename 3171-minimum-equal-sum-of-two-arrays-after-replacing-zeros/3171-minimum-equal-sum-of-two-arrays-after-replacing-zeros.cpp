class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        
        long long  zero1{},zero2{},sum1{},sum2{};
        for(int i=0;i<nums1.size();i++){
            sum1+=nums1[i];
            if(nums1[i]==0){
                zero1++;
            }
        }
        for(int i=0;i<nums2.size();i++){
            sum2+=nums2[i];
            if(nums2[i]==0) zero2++;
        }

        if( (zero1==0 && sum1-sum2<zero2) || (zero2==0 && sum2-sum1<zero1) ){
           return -1; 
        }
       
       return 1ll*max((1ll*sum1+1ll*zero1),(1ll*sum2+1ll*zero2));
    }
};