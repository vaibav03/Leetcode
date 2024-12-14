class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int left{},right{};
        long long int ans{};
        map<int,int> freq;
        while(right<nums.size()){
          freq[nums[right]]++;
          while(freq.rbegin()->first - freq.begin()->first >2){
            freq[nums[left]]--;
            if(freq[nums[left]]==0)
            freq.erase(nums[left]);
            left++;
          }
          ans+= right-left+1;
          right++;
        }
        return ans;
    }
};