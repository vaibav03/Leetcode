class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long int i=0,j=0,ans{};
        while(i<=j && j<nums.size()){
            if(j+1<nums.size() && nums[j]!=nums[j+1])
            {
            j++;    
            } 
             else if(i==j && j+1<nums.size() && nums[j]==nums[j+1])
             {
              ans+=1;
              i++;
              j++;  
             }
            else{
            long long int n = j-i+1;   
             ans+= (long long)n*(n+1)/2;
             i=j+1;
             j++;
            } 
        }
        return ans;
    }
};