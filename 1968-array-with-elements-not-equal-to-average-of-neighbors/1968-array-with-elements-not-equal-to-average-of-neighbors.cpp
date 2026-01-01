class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i {}, j  = nums.size() - 1,flag{};
        vector<int> ans;
        while(i!=j){
            if(flag%2 ==0 ){ ans.push_back(nums[i]); i++; }
            else{
                ans.push_back(nums[j]); 
                j--; 
            }
            flag++;
        }
        ans.push_back(nums[i]);
        return ans;
    }
};