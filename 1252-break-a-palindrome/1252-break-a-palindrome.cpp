class Solution {
public:
    string ans(string s){
        int i =0,j = s.size() -1;
        while(i<=j){
            
            if(s[i]!='a' && i!=j) {
                s[i] = 'a';
                return s;
            }

            i++;
            j--;
        }
        s[s.size() -1 ] = 'b';
        return s;
    }
    string breakPalindrome(string palindrome) {
        if(palindrome.size() == 1) return "";
        return ans(palindrome);
    }
};