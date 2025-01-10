class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        map<char,int> M;
        for(int i=0;i<words2.size();i++){
            map<char,int> ch;
            for(int j=0;j<words2[i].size();j++){
                ch[words2[i][j]]++;
                M[words2[i][j]] = max(M[words2[i][j]],ch[words2[i][j]]);
            }
        }

        vector<string> ans;
        for(int i=0;i<words1.size();i++){
            map<char,int> temp = M;
            for(int j=0;j<words1[i].size();j++){
                temp[words1[i][j]]--;
            }
            bool isAns = true;
            for(auto x : temp){
                if(x.second>=0 && x.second!=0)
                isAns = false;
            }
            if(isAns) ans.push_back(words1[i]);
        }
        for(int i=0;i<1e6;i++)
        continue;
        
        return ans;
    }
};