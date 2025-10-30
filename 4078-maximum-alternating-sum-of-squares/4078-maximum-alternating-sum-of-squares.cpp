class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[](int &a,int &b){
            return abs(a)<abs(b);
        });
        int l = 0,r = nums.size()-1;
        long long ans{};
        while(l<=r){
            ans+= (nums[r]*nums[r]);
            nums[r] = 0;
            ans-= (nums[l]*nums[l]);
            nums[l] = 0;
            l++; r--;
        }
        return ans;
    }
};