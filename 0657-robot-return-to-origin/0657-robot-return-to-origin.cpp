class Solution {
public:
    bool judgeCircle(string moves) {
        unordered_map<char,int> hash;
        for(auto x : moves){
            hash[x]++;
        }
        return (hash['U'] == hash['D']) && (hash['L'] == hash['R']);
    }
};