class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> hash;
        for(int i=0;i<nums.size();i++){
            hash[nums[i]]++;
        }
        int ans{};
        for(auto x : hash){
            int val = x.first , cnt = x.second;
            if(hash.find(k - val) != hash.end())
            ans += min(cnt,hash[k-val]);
        }
        return ans/2;
    }
};