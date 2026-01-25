class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<pair<int,int>> vec;
        for(int i=0;i<nums.size();i++){
            if(nums[i] >= 0){
                vec.push_back({nums[i],i});
            }
        }
        if(vec.empty()) return nums;
        
        k%=vec.size();
        int v = vec.size();
        for(int i=0;i<vec.size();i++){
            int pos = vec[i].second;
            nums[pos] = vec[(i+k)%v].first ;
        }
        return nums;
    }
};