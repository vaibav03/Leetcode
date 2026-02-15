class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        unordered_map<string,int>  hash;
        for(auto str : words){
            if(str.size() >=k ){
             string substr = str.substr(0,k);
             hash[substr]++;
            }
        }
        int ans = 0;
        for(auto x : hash){
            if(x.second >= 2 ) ans++;
        }
        return ans;
    }
};