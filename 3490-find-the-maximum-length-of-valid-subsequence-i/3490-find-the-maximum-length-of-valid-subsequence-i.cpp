class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int ans{},sub1{},sub2{},num1{},num0{};

        for(int i=0;i<nums.size();i++){
            if(i<nums.size()-1 && (nums[i]+nums[i+1])%2==1){
                sub1++;
            }
            if(nums[i]%2==0){
                num0++;
            }else if(nums[i]%2==1){
                num1++;
            }
        }

        cout<<sub1<<" "<<sub2<<" "<<num1<<" "<<num0<<endl;  
        
        return max(sub1+1,max(num1,num0));

    }
};