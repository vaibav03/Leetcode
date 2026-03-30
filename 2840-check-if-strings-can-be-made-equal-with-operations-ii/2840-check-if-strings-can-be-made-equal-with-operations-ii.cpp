class Solution {
public:
    bool checkStrings(string s1, string s2) {
        unordered_map<char,int> Mo,Me;
        for(int i=0;i<s1.size();i+=2){
            Me[s1[i]]++;
            Me[s2[i]]--;
            if(Me[s2[i]] == 0) Me.erase(s2[i]);
            if(Me[s1[i]] == 0) Me.erase(s1[i]);
        }
        for(int i=1;i<s1.size();i+=2){
            Mo[s1[i]]++;
            Mo[s2[i]]--;
            if(Mo[s2[i]] == 0) Mo.erase(s2[i]);
            if(Mo[s1[i]] == 0) Mo.erase(s1[i]);
        }

        return (Me.size() == 0 && Mo.size()==0);
    }
};