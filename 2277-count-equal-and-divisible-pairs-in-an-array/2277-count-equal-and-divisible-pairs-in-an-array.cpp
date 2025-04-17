class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        map<int,vector<int>> M;
        for(int i=0;i<nums.size();i++){
            M[nums[i]].push_back(i);
        }
        int ans{};
        for(auto i : M){
            for(auto j : i.second){
                for(auto m : i.second){
                    if(j!=m && j*m%k==0){
                        ans++;
                    }
                }
            }
        }
        return ans/2;

    }
};