class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        deque<int> dq_min,dq_max;
        long long  i=0,start=0,ans{};
        while(i<nums.size()){
                if(nums[i]<minK || nums[i]>maxK){
                    start = i+1;
                    dq_min.clear();
                    dq_max.clear();
                    i++;
                    continue;
                }

                while (!dq_min.empty() && nums[dq_min.back()] >= nums[i]) dq_min.pop_back();
                dq_min.push_back(i);

                while (!dq_max.empty() && nums[dq_max.back()] <= nums[i]) dq_max.pop_back();
                dq_max.push_back(i);

                if(nums[dq_min.front()]==minK && nums[dq_max.front()]==maxK){
                    ans+=(min(dq_min.front(),dq_max.front()) - start +1);
                }
                i++;
        }
        return ans;
    }
};