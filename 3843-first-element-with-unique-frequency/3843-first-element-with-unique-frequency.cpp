class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,int> hash;
        for(auto num : nums){
            hash[num]++;
        }
        unordered_map<int,int> uniq;
        for(auto x : hash){
            uniq[x.second]++;
        }
        for(auto x : nums){
            int occ = hash[x];
            if(uniq[occ] == 1) return x;
        }
        return -1;
    }
};