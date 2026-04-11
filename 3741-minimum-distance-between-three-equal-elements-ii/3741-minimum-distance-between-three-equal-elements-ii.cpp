class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>> hash;
        for(int i=0;i<nums.size();i++){
            hash[nums[i]].push_back(i);
        }

        int ans = INT_MAX;
        for(auto x : hash){
            vector<int> vec = x.second;
            if(vec.size() < 3) continue;
            for(int i=0;i<=vec.size()-3;i++){
                int j = i+1,k = i+2;
                ans = min(ans,
                    abs(vec[i] - vec[j])+
                    abs(vec[j] - vec[k])+
                    abs(vec[i] - vec[k])
                );
            }
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};