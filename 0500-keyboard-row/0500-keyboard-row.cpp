class Solution {
public:
    bool ispresent(string a, string b){
        for(int i=0;i<a.size();i++){
            bool isp = false;
            for(int j=0;j<b.size();j++){
                if(a[i] == b[j] || a[i]==toupper(b[j])) isp = true;
            }
            if(!isp) return false;
        }
        return true;
    }
    vector<string> findWords(vector<string>& words) {
        vector<string> rows = {"qwertyuiop","asdfghjkl","zxcvbnm"};
        vector<string> ans;
        for(auto word : words){
            if(ispresent(word,rows[0]) || ispresent(word,rows[1]) || ispresent(word,rows[2]) ){
                ans.push_back(word);
            }
        }
        return ans;
    }
};