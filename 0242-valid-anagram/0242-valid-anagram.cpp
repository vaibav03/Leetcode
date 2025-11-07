class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        map<char,int> M;
        for(int i=0;i<s.size();i++) M[s[i]]++;

        for(int i=0;i<t.size();i++){ 
            if(M[t[i]]==0) return false;
            else
            M[t[i]]--;
        }

        return true;
    }
};