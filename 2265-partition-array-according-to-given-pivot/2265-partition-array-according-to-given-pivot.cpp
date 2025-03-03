class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less,gre,eq;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<pivot) less.push_back(nums[i]);
            if(nums[i]>pivot) gre.push_back(nums[i]);
            if(nums[i]==pivot) eq.push_back(nums[i]);
        }

        nums = less;
        int i=0;
        while(i<eq.size()){
            nums.push_back(eq[i]);
            i++;
        }
        i=0;
        while(i<gre.size()){
            nums.push_back(gre[i]);
            i++;
        }
        return nums;
    }
};