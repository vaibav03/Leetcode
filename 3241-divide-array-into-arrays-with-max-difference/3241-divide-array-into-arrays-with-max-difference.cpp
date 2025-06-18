class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n= nums.size();
        vector<vector<int>> ans;
        int i{};
        while(i+2<n){
            if(nums[i+2]-nums[i]<=k){    
            vector<int> v(nums.begin()+i,nums.begin()+i+3);
            ans.push_back(v);
            i+=3;
            }else{
                return {};
            }
        }
         return ans;
    }
};