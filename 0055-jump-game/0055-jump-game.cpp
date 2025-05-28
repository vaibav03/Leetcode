class Solution {
public:

    bool canJump(vector<int>& nums) {
        if(nums.size() == 1) return true;
        vector<int> vis(nums.size(),0);
        int least = INT_MAX;
        for(int i = nums.size()-2;i>=0;i--){
            if(nums[i]+i >= nums.size()-1 || nums[i]+i>=least){
                 vis[i] = true;
                 least = min(least,i);
                 }

        }
        for(int i=0;i<nums.size();i++){
            cout<<vis[i]<<" ";
        }
        cout<<endl;
        return vis[0];
    }
};