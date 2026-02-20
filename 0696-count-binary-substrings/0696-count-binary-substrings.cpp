class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans{},prev{},curr = 1,i = 1;
        while(i<=s.size()){
            if(i<s.size() && s[i] == s[i-1]) curr++;
            else {
                ans += min(prev,curr);
                prev = curr;
                curr = 1;
            }
            i++;
        }
        return ans;
    }
};

