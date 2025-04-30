class Solution {
public:

    int findNumbers(vector<int>& nums) {
        
        int ans{};
        for(int i=0;i<nums.size();i++){
            int digits{};
            while(nums[i]){
                nums[i]/=10;
                digits++;
            }
            if(digits%2==0) ans++;
        }
        return ans;
    }
};