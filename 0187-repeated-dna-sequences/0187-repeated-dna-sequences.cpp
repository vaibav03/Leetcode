class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size() < 10) return {};
        vector<string> ans;
        unordered_map<string,int> hash;
        for(int i=0;i<=s.size() - 10;i++){

            string curr = s.substr(i,10);

            hash[curr]++;
        }
        for(auto x : hash){
            if(x.second >= 2) ans.push_back(x.first);
        }
        return ans;
    }
};