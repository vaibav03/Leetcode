class Solution {
public:
    char shift(char ch, long long sh){
        sh%=26;
        if(ch + sh > 'z') return 'a' + (ch +sh - 'z' - 1);
        
         return ch+sh;
    }
    string shiftingLetters(string s, vector<int>& shifts) {
        long long pre{};
        for(int i=s.size()-1;i>=0;i--){
            pre+=shifts[i];
            s[i] = shift(s[i],pre);
        }
        return s;
    }
};