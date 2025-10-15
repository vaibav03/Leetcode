class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> temp = nums,ans;
        sort(temp.begin(),temp.end());
        map<int,int> M;
        for(int i = n-k ;i<n;i++){
            cout<<temp[i]<<" ";
            M[temp[i]]++;
        }



        for(int i=0;i<nums.size();i++){
            if(M.count(nums[i])){
             ans.push_back(nums[i]);  
            M[nums[i]]--;  
            if(M[nums[i]] == 0) M.erase(nums[i]);
            }
        }
        return ans;
    }
};