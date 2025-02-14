class Solution {
public:
   static bool cmp(pair<char,int> a, pair<char,int> b ){
        return a.second>b.second;
    }
    string frequencySort(string s) {
        map<char, int> M;
        for (char c : s) {
            M[c]++;
        }
        vector<pair<char, int>> freq(M.begin(), M.end());
        sort(freq.begin(),freq.end(),cmp);
        string ans = "";
        for(auto i : freq){
            while(i.second--)
            ans+=i.first;
        }
        return ans;


    }
};