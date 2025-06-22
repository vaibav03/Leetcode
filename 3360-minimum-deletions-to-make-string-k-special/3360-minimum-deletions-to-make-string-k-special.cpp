class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<int,int> M;
        for(int i=0;i<word.size();i++){
            M[word[i]-'a']++;
        }

        int ans=INT_MAX;
        for(auto x : M){
            int del {};
            for(auto y : M){
                if(y.second - x.second > k){
                    del+=(y.second-x.second-k);
                }else if(y.second<x.second){
                    del+=y.second;
                }
            }
            ans = min(ans,del);
        }
        return ans;
    }
};