class Solution {
public:
    int maxDistinct(string s) {
        unordered_map<int,int> hash;
        for(auto x : s){
            hash[x]++;
        }
        return(!hash.empty()) ?  hash.size() : 0;
    }
};