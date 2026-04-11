class Solution {
public:
    int sum(int num){
        int ans = 0;
        while(num){
            ans+= (num%10);
            num/=10;
        }
        return ans;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(sum(nums[i]) == i) return i;
        }
        return -1;
    }
};