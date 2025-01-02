class Solution {
public:
bool isvowel(char ch){
    if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
    return true;

    return false;
}
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> pre(words.size()+1,0);

        for(int i=1;i<=words.size();i++){
            if(isvowel(words[i-1][0]) && isvowel(words[i-1][words[i-1].size()-1]))
            pre[i] = pre[i-1] +1;
            else
            pre[i]=pre[i-1];
            cout<<pre[i]<<" ";
        }
        
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            ans.push_back(pre[queries[i][1]+1] - pre[ queries[i][0]] );
        }
        return ans;
    }
};