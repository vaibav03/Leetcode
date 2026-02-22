class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        bool active = 0;
        vector<int> v(2,0);
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2 == 1 ) active = !active;
            if((i+1)%6 == 0) active = !active;
            //cout<<i<<" "<<active<<endl;
            v[active] += nums[i];
        }
        return v[0] - v[1];
    }
};