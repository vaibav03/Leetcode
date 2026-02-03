class Solution {
public:
    int expand(const string& s, int l, int r, int& start) {
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            l--;
            r++;
        }
        start = l + 1;
        return r - l - 1;
    }
    string longestPalindrome(string s) {
        if (s.empty()) return "";

        int bestLen = 0;
        int bestStart = 0;

        for (int i = 0; i < s.size(); i++) {
            int start1, start2;

            int len1 = expand(s, i, i, start1);     
            int len2 = expand(s, i, i + 1, start2); 

            if (len1 > bestLen) {
                bestLen = len1;
                bestStart = start1;
            }
            if (len2 > bestLen) {
                bestLen = len2;
                bestStart = start2;
            }
        }

        return s.substr(bestStart, bestLen);
    }
};
