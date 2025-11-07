class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> m;
        vector<vector<string>> ans;
        for(auto str : strs){
            string dupe = str;
            sort(dupe.begin(),dupe.end());
            m[dupe].push_back(str);
        }
        for(auto x : m){
            vector<string> curr;
            for(int i=0;i<x.second.size();i++){
                curr.push_back(x.second[i]);
            }
            ans.push_back(curr);
        }
        return ans; 
    }
};